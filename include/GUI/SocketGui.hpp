/*
** EPITECH PROJECT, 2019
** SocketGui.hpp
** File description:
** Socket gui
*/

#ifndef SOCKETGUI_HPP_
#define SOCKETGUI_HPP_

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <string>
#include <queue>

#include "./CommandsGui.hpp"

class CommandsGui;

#define MAX_MSG_LEN 1024

class SocketGui {
	public:
		SocketGui(int port, std::string host);
		~SocketGui();
		void initSocket();
        void setCmd(CommandsGui *cmd);
        void connectToServer();
        bool serverCommunication();
        bool socketRead();
        void socketWrite();
        void addCommand(const std::string &cmd);

	private:
		int _port;
        std::string _host;
        int _fd;
        std::vector<std::string> _send;
        fd_set _fd_read;
        fd_set _fd_write;
        struct sockaddr_in _addr;
        CommandsGui *_commands;
};

#endif /* !SOCKETGUI_HPP_ */
