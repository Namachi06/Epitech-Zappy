/*
** EPITECH PROJECT, 2019
** ZappyException.cpp
** File description:
** Zappy error exceptions
*/

#include "../../../include/GUI/ZappyExceptionGui.hpp"

ZException::ZappyExceptionGui::ZappyExceptionGui(std::string const &e) : _errorMessage(e)
{
}

ZException::ZappyExceptionGui::~ZappyExceptionGui()
{
}

const char *ZException::ZappyExceptionGui::what() const throw()
{
    return _errorMessage.c_str();
}

ZException::ArgumentExceptionGui::ArgumentExceptionGui(std::string const &errorMessage) : ZappyExceptionGui(errorMessage)
{
}

ZException::ArgumentExceptionGui::~ArgumentExceptionGui()
{
}

ZException::SocketExceptionGui::SocketExceptionGui(std::string const &errorMessage) : ZappyExceptionGui(errorMessage)
{
}

ZException::SocketExceptionGui::~SocketExceptionGui()
{
}
