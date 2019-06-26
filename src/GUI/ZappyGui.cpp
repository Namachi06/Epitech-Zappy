/*
** EPITECH PROJECT, 2019
** Zappy.cpp
** File description:
** Zappy
*/

#include <iostream>
#include <string.h>
#include "../../include/GUI/ZappyGui.hpp"
#include "../../include/GUI/SocketGui.hpp"
#include "../../include/GUI/CommandsGui.hpp"
#include "../../include/GUI/ZappyExceptionGui.hpp"

ZappyGui::ZappyGui(int argc, char *argv[])
{
    _host = "localhost";
    _port = 0;
    _args.emplace("-p", std::bind(&ZappyGui::setPort, this, std::placeholders::_1));
    _args.emplace("-h", std::bind(&ZappyGui::setHost, this, std::placeholders::_1));
    _args.emplace("-help", std::bind(&ZappyGui::usage, this, std::placeholders::_1));
    initZappy(argc, argv);
}

ZappyGui::~ZappyGui()
{
}

void ZappyGui::initZappy(int argc, char *argv[])
{
    std::map<std::string, std::function<void(char *argv)>>::iterator it;

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);
        if (_args.find(arg) == _args.end())
            throw ZException::ArgumentExceptionGui("Invalid argument: " + arg);
        for (it = _args.begin(); it != _args.end(); it++) {
            if (arg.compare((*it).first) == 0) {
                _args[arg](argv[++i]);
                break;
            }
        }
    }
    checkArgs();
}

void ZappyGui::setPort(char *argv)
{
    if (argv == NULL || argv[0] == '-')
        throw ZException::ArgumentExceptionGui("-p: Invalid argument");
    std::string port(argv);

    if (!_utils.isDigit(port))
        throw ZException::ArgumentExceptionGui("-p: Must be numbers");
    _port = _utils.atoi(port);
}

void ZappyGui::setHost(char *argv)
{
    if (argv == NULL || argv[0] == '-')
        throw ZException::ArgumentExceptionGui("-h: Invalid argument");
    std::string host(argv);

    _host = host;
}

void ZappyGui::usage(char *argv)
{
    (void)argv;
    _utils.printUsage();
    throw ZException::ArgumentExceptionGui("");
}

void ZappyGui::checkArgs()
{
    if (_port == 0)
        throw ZException::ArgumentExceptionGui("Missing arguments: -n or -p");
}

void ZappyGui::run()
{
    CommandsGui cmd;
    SocketGui socket(_port, _host);

    socket.setCmd(&cmd);
    cmd.setSocket(&socket);
    socket.connectToServer();
    while (42) {
        if (!socket.serverCommunication())
            return;
    }
}
