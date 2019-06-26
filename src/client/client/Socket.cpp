/*
** EPITECH PROJECT, 2019
** Socket.cpp
** File description:
** Socket
*/

#include <iostream>
#include <string.h>
#include "../../../include/client/Socket.hpp"
#include "../../../include/client/ZappyException.hpp"

Socket::Socket(int port, std::string host) : _port(port), _host(host)
{
    _fd = -1;
    initSocket();
}

Socket::~Socket()
{
    if (_fd == -1)
        close(_fd);
}

void Socket::initSocket()
{
    int opt = 1;
    struct hostent *host;

    host = gethostbyname(_host.c_str());
    if (host == NULL)
        throw ZException::SocketException("Unknown host");
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(_port);
    _addr.sin_addr = *((struct in_addr *)host->h_addr_list[0]);
    if ((_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
        throw ZException::SocketException("socket: Error occured");
    if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
        throw ZException::SocketException("setsockopt: Error occured");
}

void Socket::setCmd(Commands *cmd)
{
    _commands = cmd;
}

void Socket::connectToServer()
{
    if (connect(_fd, (struct sockaddr *)&_addr, sizeof(_addr)) == -1)
        throw ZException::SocketException("connect: Error occured");
}

bool Socket::serverCommunication()
{
    bool alive = true;

    FD_ZERO(&_fd_read);
    FD_ZERO(&_fd_write);
    FD_SET(_fd, &_fd_read);
    FD_SET(_fd, &_fd_write);
    if (select(_fd + 1, &_fd_read, &_fd_write, NULL, NULL) == -1)
        throw ZException::SocketException("select: Error occured");
    if (FD_ISSET(_fd, &_fd_read))
        alive = socketRead();
    if (FD_ISSET(_fd, &_fd_write))
        socketWrite();
    return (alive ? true : false);
}

bool Socket::socketRead()
{
    char buffer[MAX_MSG_LEN];
    ssize_t rd;

    memset(buffer, 0, MAX_MSG_LEN);
    if ((rd = read(_fd, buffer, sizeof(buffer))) <= 0) {
        std::cout << "Connexion closed" << std::endl;
        return (false);
    }
    buffer[rd] = '\0';
    std::string buff(buffer);
    std::cout << buff;
    buff.pop_back();
    if (!_commands->interpretCommand(buff))
        return (false);
    return (true);
}

void Socket::socketWrite()
{
    if (_send.empty())
        return;
    std::cout << _send.front() << std::endl;
    // _send.front().push_back('\n');
    write(_fd, _send.front().c_str(), _send.front().size());
    _send.pop();
}

void Socket::addCommand(const std::string &cmd)
{
    _send.push(cmd);
}

std::string Socket::getId() const
{
    return (_id);
}

void Socket::setId(std::string id)
{
    _id = id;
}
