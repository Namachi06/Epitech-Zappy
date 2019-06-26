/*
** EPITECH PROJECT, 2019
** Zappy.hpp
** File description:
** Zappy
*/

#ifndef ZAPPY_HPP_
#define ZAPPY_HPP_

#include <string>
#include <functional>
#include <map>
#include <chrono>
#include <thread>
#include "./Utils.hpp"

class Zappy {
	public:
		Zappy(int argc, char *argv[]);
		~Zappy();
        void initZappy(int argc, char *argv[]);
        void setPort(char *argv);
        void setTeam(char *argv);
        void setHost(char *argv);
        void usage(char *argv);
        void checkArgs();
        void run();

	private:
        Utils _utils;
        std::map<std::string, std::function<void (char *argv)>> _args;
        int _port;
        std::string _team;
        std::string _host;
};

#endif /* !ZAPPY_HPP_ */
