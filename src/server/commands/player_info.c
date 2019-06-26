/*
** EPITECH PROJECT, 2019
** player_info.c
** File description:
** Get the player informations
*/

#include "../../../include/server/server.h"

int init_info_duration(t_zappy *zappy, t_player *player)
{
    if (player->act.initizalized != 0)
        return (-1);
    player->act.initizalized = 1;
    if (!strcmp(player->act.args[0], "Inventory")) {
        player->act.action = &inventory;
        player->act.duration = 1 / zappy->freq;
    }
    if (!strcmp(player->act.args[0], "Look")) {
        player->act.action = &look;
        player->act.duration = 7 / zappy->freq;
    }
    if (!strcmp(player->act.args[0], "Broadcast")) {
        player->act.action = &broadcast;
        player->act.duration = 7 / zappy->freq;
    }
    return (0);
}

int connect_nbr(t_zappy *zappy, t_player *player)
{
    (void)zappy;
    add_msg(&player->plyr, "ok\n");
    return (0);
}

int inventory(t_zappy *zappy, t_player *player)
{
    (void)zappy;
    if (!init_info_duration(zappy, player))
        return (0);
    add_msg(&player->plyr, "ok\n");
    return (0);
}

int look(t_zappy *zappy, t_player *player)
{
    (void)zappy;
    if (!init_info_duration(zappy, player))
        return (0);
    add_msg(&player->plyr, "ok\n");
    return (0);
}

int broadcast(t_zappy *zappy, t_player *player)
{
    (void)zappy;
    if (!init_info_duration(zappy, player))
        return (0);
    add_msg(&player->plyr, "ok\n");
    return (0);
}
