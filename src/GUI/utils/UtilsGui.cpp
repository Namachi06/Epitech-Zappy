/*
** EPITECH PROJECT, 2019
** Utils.cpp
** File description:
** Util functions
*/

#include "../../../include/GUI/UtilsGui.hpp"
#include <sstream>
#include <iostream>

UtilsGui::UtilsGui()
{
}

UtilsGui::~UtilsGui()
{
}

bool UtilsGui::isDigit(const std::string &s)
{
    std::string::const_iterator it = s.begin();

    for (; it != s.end() && std::isdigit(*it); it++);
    return !s.empty() && it == s.end();
}

int UtilsGui::atoi(const std::string &s)
{
    int nbr;
    std::stringstream str(s);

    str >> nbr;
    return (nbr);
}

void UtilsGui::printUsage()
{
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::cout << "\tport is the port number" << std::endl;
    std::cout << "\tname is the name of the team" << std::endl;
    std::cout << "\tmachine is the name of the machine; localhost by default" << std::endl;
}

std::vector<std::string> UtilsGui::split(std::string str, std::string elem)
{
    std::vector<std::string> result;

    boost::split(result, str, boost::is_any_of(elem));
    return result;
}
