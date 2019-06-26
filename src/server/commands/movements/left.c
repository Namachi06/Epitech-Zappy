/*
** EPITECH PROJECT, 2019
** left.c
** File description:
** Left command
*/

#include "../../../../include/server/server.h"

void get_dir_left2(int *x, int *y, t_player *player)
{
    if (player->dir == LEFT) {
        *x = 0;
        *y = 1;
        player->dir = DOWN;
        return;
    }
    if (player->dir == DOWN) {
        *x = 1;
        *y = 0;
        player->dir = RIGHT;
        return;
    }
}

void get_dir_left(int *x, int *y, t_player *player)
{
    if (player->dir == UP) {
        *x = -1;
        *y = 0;
    }
    if (player->dir == RIGHT) {
        *x = 0;
        *y = -1;
        player->dir = UP;
        return;
    }
    get_dir_left2(x, y, player);
}

int left(t_zappy *zappy, t_player *player)
{
    int x;
    int y;

    if (!init_movement_duration(zappy, player))
        return (0);
    get_dir_left(&x, &y, player);
    move_character(zappy, player, x, y);
    add_msg(&player->plyr, "ok\n");
    return (0);
}
