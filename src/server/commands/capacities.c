/*
** EPITECH PROJECT, 2019
** capacities.c
** File description:
** Capacities of a player
*/

#include "../../../include/server/server.h"

int init_capacities_duration(t_zappy *zappy, t_player *player)
{
    if (player->act.initizalized != 0)
        return (-1);
    player->act.initizalized = 1;
    if (!strcmp(player->act.args[0], "Fork")) {
        player->act.action = &fork_player;
        player->act.duration = 42 / zappy->freq;
    }
    if (!strcmp(player->act.args[0], "Incantation")) {
        player->act.action = &incantation;
        player->act.duration = 300 / zappy->freq;
    }
    if (!strcmp(player->act.args[0], "Eject")) {
        player->act.action = &eject;
        player->act.duration = 7 / zappy->freq;
    }
    return (0);
}

int fork_player(t_zappy *zappy, t_player *player)
{
    if (!init_capacities_duration(zappy, player))
        return (0);
    add_msg(&player->plyr, "ok\n");
    return (0);
}

int eject(t_zappy *zappy, t_player *player)
{
    if (!init_capacities_duration(zappy, player))
        return (0);
    add_msg(&player->plyr, "ok\n");
    return (0);
}
