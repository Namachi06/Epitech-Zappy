/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Main program
*/

#include "../../include/GUI/ZappyExceptionGui.hpp"
#include "../../include/GUI/ZappyGui.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    try {
        ZappyGui zappy(argc, argv);

        zappy.run();
    } catch(ZException::ZappyExceptionGui const &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}

