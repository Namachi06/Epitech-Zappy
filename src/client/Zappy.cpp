/*
** EPITECH PROJECT, 2019
** Zappy.cpp
** File description:
** Zappy
*/

#include <iostream>
#include <string.h>
#include "../../include/client/Zappy.hpp"
#include "../../include/client/Socket.hpp"
#include "../../include/client/Commands.hpp"
#include "../../include/client/ZappyException.hpp"

Zappy::Zappy(int argc, char *argv[])
{
    _host = "localhost";
    _port = 0;
    _args.emplace("-p", std::bind(&Zappy::setPort, this, std::placeholders::_1));
    _args.emplace("-n", std::bind(&Zappy::setTeam, this, std::placeholders::_1));
    _args.emplace("-h", std::bind(&Zappy::setHost, this, std::placeholders::_1));
    _args.emplace("-help", std::bind(&Zappy::usage, this, std::placeholders::_1));
    initZappy(argc, argv);
}

Zappy::~Zappy()
{
}

void Zappy::initZappy(int argc, char *argv[])
{
    std::map<std::string, std::function<void(char *argv)>>::iterator it;

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (_args.find(arg) == _args.end())
            throw ZException::ArgumentException("Invalid argument: " + arg);
        for (it = _args.begin(); it != _args.end(); it++) {
            if (arg.compare((*it).first) == 0) {
                _args[arg](argv[++i]);
                break;
            }
        }
    }
    checkArgs();
}

void Zappy::setPort(char *argv)
{
    if (argv == NULL || argv[0] == '-')
        throw ZException::ArgumentException("-p: Invalid argument");
    std::string port(argv);

    if (!_utils.isDigit(port))
        throw ZException::ArgumentException("-p: Must be numbers");
    _port = _utils.atoi(port);
}

void Zappy::setTeam(char *argv)
{
    if (argv == NULL || argv[0] == '-')
        throw ZException::ArgumentException("-n: Invalid argument");
    std::string team(argv);

    _team = team;
}

void Zappy::setHost(char *argv)
{
    if (argv == NULL || argv[0] == '-')
        throw ZException::ArgumentException("-h: Invalid argument");
    std::string host(argv);

    _host = host;
}

void Zappy::usage(char *argv)
{
    (void)argv;
    _utils.printUsage();
    throw ZException::ArgumentException("");
}

void Zappy::checkArgs()
{
    if (_team.empty() || _port == 0)
        throw ZException::ArgumentException("Missing arguments: -n or -p");
}

void Zappy::run()
{
    bool initialized = false;
    Ai ai;
    Socket socket(_port, _host);
    Commands cmd(ai, socket, initialized);

    socket.setCmd(&cmd);
    cmd.setTeam(_team);
    ai.setCmd(&cmd);
    socket.connectToServer();
    while (42) {
        if (!socket.serverCommunication())
            return;
        if (initialized == false || ai.getWait() == true)
            continue;
        ai.move();
        ai.ppo();
    }
}
