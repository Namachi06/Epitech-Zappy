/*
** EPITECH PROJECT, 2019
** main.cpp
** File description:
** Main client program
*/

#include "../../include/client/ZappyException.hpp"
#include "../../include/client/Zappy.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    try {
        Zappy zappy(argc, argv);

        zappy.run();
    } catch(ZException::ZappyException const &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
    return (0);
}
