/*
** EPITECH PROJECT, 2019
** Commands.cpp
** File description:
** Commands
*/

#include "../../../include/client/Commands.hpp"

Commands::Commands(Ai &ai, Socket &socket, bool &initialized) : _ai(ai), _socket(socket), _initialized(initialized)
{
}

Commands::~Commands()
{
}

bool Commands::interpretCommand(const std::string &cmd)
{
    std::vector<std::string>::iterator argReturn;

    _cmdSplitReturn = _utils.split(cmd, "\n");
    _cmdLineSplit = _utils.split(cmd, " ");
    for (argReturn = _cmdSplitReturn.begin(); argReturn != _cmdSplitReturn.end(); argReturn++) {
        _cmdLineSplit = _utils.split(*argReturn, " ");
        if (*argReturn == "dead")
            return (false);
        if (*argReturn == "WELCOME")
            welcomeCommand();
        if (_cmdLineSplit[0] == "Id")
            _socket.setId(_cmdLineSplit[1]);
        if (_initialized == true && (*argReturn == "ok" || *argReturn == "ko"))
            _ai.setWait(false);
    }
    return (true);
}

void Commands::setTeam(std::string &team)
{
    _team = team;
}

void Commands::welcomeCommand()
{
    _socket.addCommand(_team);
    _initialized = true;
    _ai.setWait(true);
}

void Commands::lookCommand()
{
    _socket.addCommand("Look");
    _ai.setWait(true);
}

void Commands::forwardCommand()
{
    _socket.addCommand("Forward");
    _ai.setWait(true);
}

void Commands::rightCommand()
{
    _socket.addCommand("Right");
    _ai.setWait(true);
}

void Commands::leftCommand()
{
    _socket.addCommand("Left");
    _ai.setWait(true);
}

void Commands::inventoryCommand()
{
    _socket.addCommand("Inventory");
    _ai.setWait(true);
}

void Commands::nbrConnectedCommand()
{
    _socket.addCommand("Connected_nbr");
    _ai.setWait(true);
}

void Commands::ejectCommand()
{
    _socket.addCommand("Eject");
    _ai.setWait(true);
}

void Commands::forkCommand()
{
    _socket.addCommand("Fork");
    _ai.setWait(true);
}

void Commands::incantationCommand()
{
    _socket.addCommand("Incantation");
    _ai.setWait(true);
}

void Commands::broadcastCommand(const std::string &msg)
{
    _socket.addCommand("Broadcast " + msg);
    _ai.setWait(true);
}

void Commands::takeCommand(const std::string &objct)
{
    _socket.addCommand("Take " + objct);
    _ai.setWait(true);
}

void Commands::setCommand(const std::string &objct)
{
    _socket.addCommand("Set " + objct);
    _ai.setWait(true);
}

void Commands::ppoCommand()
{
    _socket.addCommand("ppo " + _socket.getId());
}
