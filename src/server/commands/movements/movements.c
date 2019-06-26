/*
** EPITECH PROJECT, 2019
** movements.c
** File description:
** All movements commands
*/

#include "../../../../include/server/server.h"

int init_movement_duration(t_zappy *zappy, t_player *player)
{
    if (player->act.initizalized != 0)
        return (-1);
    player->act.duration = 7 / zappy->freq;
    player->act.initizalized = 1;
    if (!strcmp(player->act.args[0], "Forward"))
        player->act.action = &forward;
    if (!strcmp(player->act.args[0], "Right"))
        player->act.action = &right;
    if (!strcmp(player->act.args[0], "Left"))
        player->act.action = &left;
    return (0);
}

void move_character(t_zappy *zappy, t_player *player, int x, int y)
{
    zappy->map[player->y][player->x].player--;
    player->x += x;
    if (player->x < 0)
        player->x = zappy->width - 1;
    if (player->x >= zappy->width)
        player->x = 0;
    player->y += y;
    if (player->y < 0)
        player->y = zappy->width - 1;
    if (player->y >= zappy->width)
        player->y = 0;
    zappy->map[player->y][player->x].player++;
    get_tile_rsrcs(zappy, player);
}
