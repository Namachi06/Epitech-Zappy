/*
** EPITECH PROJECT, 2019
** Commands.cpp
** File description:
** Commands
*/

#include "../../../include/GUI/CommandsGui.hpp"

CommandsGui::CommandsGui()
{
}

CommandsGui::~CommandsGui()
{
}

bool CommandsGui::interpretCommand(const std::string &cmd)
{
    std::vector<std::string>::iterator arg;

    _cmdSplit = _utils.split(cmd, " ");
    for (arg = _cmdSplit.begin(); arg != _cmdSplit.end(); arg++) {
        if (*arg == "WELCOME")
            welcomeCommand();
        if (*arg == "ok")
            _socket->addCommand("bct");
    }
    return (true);
}

void CommandsGui::setSocket(SocketGui *socket)
{
    _socket = socket;
}

void CommandsGui::welcomeCommand()
{
    _socket->addCommand("GRAPHIC");
}
