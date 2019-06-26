/*
** EPITECH PROJECT, 2019
** Ai.cpp
** File description:
** Ai
*/

#include "../../../include/client/Ai.hpp"

Ai::Ai()
{
    _wait = false;
    _move = NONE;
    srand(time(NULL));
    _moves.emplace(FORWARD, std::bind(&Ai::forward, this));
    _moves.emplace(RIGHT, std::bind(&Ai::right, this));
    _moves.emplace(LEFT, std::bind(&Ai::left, this));
}

Ai::~Ai()
{
}

void Ai::setWait(bool wait)
{
    _wait = wait;
}

bool Ai::getWait() const
{
    return _wait;
}

void Ai::setCmd(Commands *cmds)
{
    _cmd = cmds;
}

void Ai::move()
{
    std::map<Moves, std::function<void ()>>::iterator it;
    int rand_move = rand() % 3;

    for (it = _moves.begin(); it != _moves.end(); it++) {
        if (it->first == rand_move)
            _moves[it->first]();
    }
}

void Ai::forward()
{
    _cmd->forwardCommand();
}

void Ai::right()
{
    _cmd->rightCommand();
}

void Ai::left()
{
    _cmd->leftCommand();
}

void Ai::ppo()
{
    _cmd->ppoCommand();
}
