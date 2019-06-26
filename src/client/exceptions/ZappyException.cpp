/*
** EPITECH PROJECT, 2019
** ZappyException.cpp
** File description:
** Zappy error exceptions
*/

#include "../../../include/client/ZappyException.hpp"

ZException::ZappyException::ZappyException(std::string const &e) : _errorMessage(e)
{
}

ZException::ZappyException::~ZappyException()
{
}

const char *ZException::ZappyException::what() const throw()
{
    return _errorMessage.c_str();
}

ZException::ArgumentException::ArgumentException(std::string const &errorMessage) : ZappyException(errorMessage)
{
}

ZException::ArgumentException::~ArgumentException()
{
}

ZException::SocketException::SocketException(std::string const &errorMessage) : ZappyException(errorMessage)
{
}

ZException::SocketException::~SocketException()
{
}
