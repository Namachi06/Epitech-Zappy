/*
** EPITECH PROJECT, 2019
** CommandsGui.hpp
** File description:
** Commands graphic
*/

#ifndef COMMANDSGUI_HPP_
#define COMMANDSGUI_HPP_

#include "../GUI/UtilsGui.hpp"
#include "../GUI/SocketGui.hpp"

class SocketGui;

class CommandsGui {
	public:
		CommandsGui();
		~CommandsGui();
        bool interpretCommand(const std::string &cmd);
        void setSocket(SocketGui *socket);

        void welcomeCommand();

	private:
        UtilsGui _utils;
        SocketGui *_socket;
        std::vector<std::string> _cmdSplit;
};

#endif /* !COMMANDSGUI_HPP_ */
