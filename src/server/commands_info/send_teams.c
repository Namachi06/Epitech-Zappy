/*
** EPITECH PROJECT, 2019
** send_teams.c
** File description:
** Send team names
*/

#include "../../../include/server/server.h"

int send_teams(t_zappy *zappy, t_player *player)
{
    char msg[1024];

    (void)player;
    for (int i = 0; i < zappy->nbr_teams; i++) {
        memset(msg, 0, sizeof(1024));
        sprintf(msg, "tna %s\n", zappy->teams[i]->name);
        add_msg(&player->plyr, msg);
    }
    return (0);
}
