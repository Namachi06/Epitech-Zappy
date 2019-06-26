/*
** EPITECH PROJECT, 2019
** forward.c
** File description:
** Forward command
*/


#include "../../../../include/server/server.h"

void get_dir_forward(int *x, int *y, t_player *player)
{
    if (player->dir == UP) {
        *x = 0;
        *y = -1;
    }
    if (player->dir == RIGHT) {
        *x = 1;
        *y = 0;
    }
    if (player->dir == DOWN) {
        *x = 0;
        *y = 1;
    }
    if (player->dir == LEFT) {
        *x = -1;
        *y = 0;
    }
}

int forward(t_zappy *zappy, t_player *player)
{
    int x;
    int y;

    if (!init_movement_duration(zappy, player))
        return (0);
    get_dir_forward(&x, &y, player);
    move_character(zappy, player, x, y);
    add_msg(&player->plyr, "ok\n");
    return (0);
}
