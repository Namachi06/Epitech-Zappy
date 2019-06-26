/*
** EPITECH PROJECT, 2019
** ZappyException.hpp
** File description:
** Zappy error exception
*/

#ifndef ZAPPYEXCEPTION_HPP_
#define ZAPPYEXCEPTION_HPP_

#include <string>

namespace ZException
{

    class ZappyException : public std::exception {
        public:
            ZappyException(std::string const &e);
            ~ZappyException();
            virtual const char *what() const throw();

        private:
            std::string _errorMessage;
    };

    class ArgumentException : public ZappyException {
        public:
            ArgumentException(std::string const &errorMessage);
            ~ArgumentException();
    };

    class SocketException : public ZappyException {
        public:
            SocketException(std::string const &errorMessage);
            ~SocketException();
    };
}

#endif /* !ZAPPYEXCEPTION_HPP_ */
