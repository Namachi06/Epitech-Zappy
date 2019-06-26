/*
** EPITECH PROJECT, 2019
** UtilsGui.hpp
** File description:
** Utils gui
*/

#ifndef UTILSGUI_HPP_
#define UTILSGUI_HPP_

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

class UtilsGui {
	public:
		UtilsGui();
		~UtilsGui();
        bool isDigit(const std::string &s);
        int atoi(const std::string &s);
        void printUsage();
        std::vector<std::string> split(std::string str, std::string elem);
};

#endif /* !UTILSGUI_HPP_ */
