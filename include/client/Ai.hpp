/*
** EPITECH PROJECT, 2019
** Ai.hpp
** File description:
** Ai
*/

#ifndef AI_HPP_
#define AI_HPP_

#include <unistd.h>
#include <time.h>
#include <map>
#include <functional>
#include "./Commands.hpp"

enum Moves
{
    FORWARD,
    RIGHT,
    LEFT,
    NONE
};

class Commands;

class Ai {
    public:
        Ai();
        ~Ai();
        void setWait(bool wait);
        bool getWait() const;
        void setCmd(Commands *cmds);

        void move();
        void forward();
        void right();
        void left();
        void ppo();

    private:
        Commands *_cmd;
        Moves _move;
        std::map<Moves, std::function<void ()>> _moves;
        bool _wait;
};

#endif /* !AI_HPP_ */
