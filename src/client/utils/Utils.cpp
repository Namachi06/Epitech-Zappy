/*
** EPITECH PROJECT, 2019
** Utils.cpp
** File description:
** Util functions
*/

#include "../../../include/client/Utils.hpp"
#include <sstream>
#include <iostream>

Utils::Utils()
{
}

Utils::~Utils()
{
}

bool Utils::isDigit(const std::string &s)
{
    std::string::const_iterator it = s.begin();

    for (; it != s.end() && std::isdigit(*it); it++);
    return !s.empty() && it == s.end();
}

int Utils::atoi(const std::string &s)
{
    int nbr;
    std::stringstream str(s);

    str >> nbr;
    return (nbr);
}

void Utils::printUsage()
{
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::cout << "\tport is the port number" << std::endl;
    std::cout << "\tname is the name of the team" << std::endl;
    std::cout << "\tmachine is the name of the machine; localhost by default" << std::endl;
}

bool Utils::strStr(std::string &s, const std::string &str)
{
    if (s.find(str) != std::string::npos)
        return true;
    return false;
}

std::vector<std::string> Utils::split(std::string str, std::string elem)
{
    std::vector<std::string> result;

    boost::split(result, str, boost::is_any_of(elem));
    return result;
}

std::string Utils::getWordStr(const std::string &str, const std::string &wrd, std::string separator)
{
    std::vector<std::string> result;
    std::vector<std::string>::iterator word;

    if (str.empty() || separator.empty())
        return nullptr;
    result = split(str, " ");
    for (word = result.begin(); word != result.end(); word++) {
        if (wrd == *word)
            return (*word);
    }
    return nullptr;
}
