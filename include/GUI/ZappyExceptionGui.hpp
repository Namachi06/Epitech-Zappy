/*
** EPITECH PROJECT, 2019
** ZappyExceptionGui.hpp
** File description:
** ZappyException gui
*/

#ifndef ZAPPYEXCEPTIONGUI_HPP_
#define ZAPPYEXCEPTIONGUI_HPP_

#include <string>

namespace ZException
{

    class ZappyExceptionGui : public std::exception {
        public:
            ZappyExceptionGui(std::string const &e);
            ~ZappyExceptionGui();
            virtual const char *what() const throw();

        private:
            std::string _errorMessage;
    };

    class ArgumentExceptionGui : public ZappyExceptionGui {
        public:
            ArgumentExceptionGui(std::string const &errorMessage);
            ~ArgumentExceptionGui();
    };

    class SocketExceptionGui : public ZappyExceptionGui {
        public:
            SocketExceptionGui(std::string const &errorMessage);
            ~SocketExceptionGui();
    };
}

#endif /* !ZAPPYEXCEPTIONGUI_HPP_ */
