/*
** EPITECH PROJECT, 2019
** ZappyGui.hpp
** File description:
** Zappy gui
*/

#ifndef ZAPPYGUI_HPP_
#define ZAPPYGUI_HPP_

#include <string>
#include <functional>
#include <map>
#include "./UtilsGui.hpp"

class ZappyGui {
	public:
		ZappyGui(int argc, char *argv[]);
		~ZappyGui();
        void initZappy(int argc, char *argv[]);
        void setPort(char *argv);
        void setHost(char *argv);
        void usage(char *argv);
        void checkArgs();
        void run();

	private:
        UtilsGui _utils;
        std::map<std::string, std::function<void (char *argv)>> _args;
        int _port;
        std::string _host;
};

#endif /* !ZAPPYGUI_HPP_ */
