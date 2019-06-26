/*
** EPITECH PROJECT, 2019
** send_frequency.c
** File description:
** Send frequence number
*/

#include "../../../include/server/server.h"

int send_frequency(t_zappy *zappy, t_player *player)
{
    char msg[1024];

    (void)player;
    sprintf(msg, "sgt %i\n", zappy->freq);
    return (0);
}
