/*
** EPITECH PROJECT, 2019
** right.c
** File description:
** Right command
*/

#include "../../../../include/server/server.h"

void get_dir_right2(int *x, int *y, t_player *player)
{
    if (player->dir == DOWN) {
        *x = -1;
        *y = 0;
        player->dir = LEFT;
        return;
    }
    if (player->dir == LEFT) {
        *x = 0;
        *y = -1;
        player->dir = UP;
        return;
    }
}

void get_dir_right(int *x, int *y, t_player *player)
{
    if (player->dir == UP) {
        *x = 1;
        *y = 0;
    }
    if (player->dir == RIGHT) {
        *x = 0;
        *y = 1;
        player->dir = DOWN;
        return;
    }
    get_dir_right2(x, y, player);
}

int right(t_zappy *zappy, t_player *player)
{
    int x;
    int y;

    if (!init_movement_duration(zappy, player))
        return (0);
    get_dir_right(&x, &y, player);
    move_character(zappy, player, x, y);
    add_msg(&player->plyr, "ok\n");
    return (0);
}
