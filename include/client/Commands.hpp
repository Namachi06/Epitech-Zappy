/*
** EPITECH PROJECT, 2019
** Commands.hpp
** File description:
** Commands
*/

#ifndef COMMANDS_HPP_
#define COMMANDS_HPP_

#include "./Utils.hpp"
#include "./Socket.hpp"
#include "./Ai.hpp"

class Socket;
class Ai;

class Commands {
	public:
		Commands(Ai &ai, Socket &socket, bool &initialized);
		~Commands();
        bool interpretCommand(const std::string &cmd);
        void setTeam(std::string &team);

        void welcomeCommand();
        void lookCommand();
        void forwardCommand();
        void rightCommand();
        void leftCommand();
        void inventoryCommand();
        void nbrConnectedCommand();
        void ejectCommand();
        void forkCommand();
        void incantationCommand();
        void broadcastCommand(const std::string &msg);
        void takeCommand(const std::string &objct);
        void setCommand(const std::string &objct);

        void ppoCommand();

	private:
        Utils _utils;
        Ai &_ai;
        Socket &_socket;
        bool &_initialized;
        std::string _team;
        std::vector<std::string> _cmdSplitReturn;
        std::vector<std::string> _cmdLineSplit;
};

#endif /* !COMMANDS_HPP_ */
