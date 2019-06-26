/*
** EPITECH PROJECT, 2019
** Socket.hpp
** File description:
** Socket
*/

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <string>
#include <queue>

#include "./Commands.hpp"

class Commands;

#define MAX_MSG_LEN 1024

class Socket {
	public:
		Socket(int port, std::string host);
		~Socket();
        void initSocket();
        void setCmd(Commands *cmd);
        void connectToServer();
        bool serverCommunication();
        bool socketRead();
        void socketWrite();
        void addCommand(const std::string &cmd);
        std::string getId() const;
        void setId(std::string id);

	private:
        int _port;
        std::string _host;
        int _fd;
        std::string _id;
        std::queue<std::string> _send;
        fd_set _fd_read;
        fd_set _fd_write;
        struct sockaddr_in _addr;
        Commands *_commands;
};

#endif /* !SOCKET_HPP_ */
