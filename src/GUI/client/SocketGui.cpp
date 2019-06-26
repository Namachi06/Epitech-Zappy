/*
** EPITECH PROJECT, 2019
** Socket.cpp
** File description:
** Socket
*/

#include <iostream>
#include <string.h>
#include "../../../include/GUI/SocketGui.hpp"
#include "../../../include/GUI/ZappyExceptionGui.hpp"

SocketGui::SocketGui(int port, std::string host) : _port(port), _host(host)
{
    _fd = -1;
    initSocket();
}

SocketGui::~SocketGui()
{
    if (_fd == -1)
        close(_fd);
}

void SocketGui::initSocket()
{
    int opt = 1;
    struct hostent *host;

    host = gethostbyname(_host.c_str());
    if (host == NULL)
        throw ZException::SocketExceptionGui("Unknown host");
    _addr.sin_family = AF_INET;
    _addr.sin_port = htons(_port);
    _addr.sin_addr = *((struct in_addr *)host->h_addr_list[0]);
    if ((_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
        throw ZException::SocketExceptionGui("socket: Error occured");
    if (setsockopt(_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
        throw ZException::SocketExceptionGui("setsockopt: Error occured");
}

void SocketGui::setCmd(CommandsGui *cmd)
{
    _commands = cmd;
}

void SocketGui::connectToServer()
{
    if (connect(_fd, (struct sockaddr *)&_addr, sizeof(_addr)) == -1)
        throw ZException::SocketExceptionGui("connect: Error occured");
}

bool SocketGui::serverCommunication()
{
    bool alive = true;

    FD_ZERO(&_fd_read);
    FD_ZERO(&_fd_write);
    FD_SET(_fd, &_fd_read);
    FD_SET(_fd, &_fd_write);
    if (select(_fd + 1, &_fd_read, &_fd_write, NULL, NULL) == -1)
        throw ZException::SocketExceptionGui("select: Error occured");
    if (FD_ISSET(_fd, &_fd_read))
        alive = socketRead();
    if (FD_ISSET(_fd, &_fd_write))
        socketWrite();
    return (alive ? true : false);
}

bool SocketGui::socketRead()
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

void SocketGui::socketWrite()
{
    if (_send.empty())
        return;
    _send.front().push_back('\n');
    write(_fd, _send.front().c_str(), _send.front().size());
    _send.clear();
}

void SocketGui::addCommand(const std::string &cmd)
{
    _send.push_back(cmd);
}
