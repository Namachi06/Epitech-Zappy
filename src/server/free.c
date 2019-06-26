/*
** EPITECH PROJECT, 2019
** free.c
** File description:
** Free memory
*/

#include "../../include/server/server.h"

void free_map(t_zappy *zappy)
{
    if (zappy->map != NULL) {
        for (int i = 0; zappy->map[i]; i++)
            free(zappy->map[i]);
        free(zappy->map);
    }
}

void free_players(t_zappy *zappy, int team)
{
    t_team *curr = NULL;

    while ((curr = zappy->teams[team]->players) != NULL) {
        zappy->teams[team]->players = zappy->teams[team]->players->next;
        if (curr->player.plyr.fd != 0)
            close(curr->player.plyr.fd);
        free(curr);
    }
}

void free_teams(t_zappy *zappy)
{
    if (zappy->teams != NULL) {
        for (int i = 0; zappy->teams[i]; i++) {
            free_players(zappy, i);
            free(zappy->teams[i]->name);
            free(zappy->teams[i]);
        }
        free(zappy->teams);
    }
}

void free_zappy(t_zappy *zappy)
{
    free_teams(zappy);
    free_map(zappy);
    if (zappy->server.fd != 0)
        close(zappy->server.fd);
    if (zappy->graph.fd != 0)
        close(zappy->graph.fd);
    del_all_msg(&zappy->server.msg);
    del_all_msg(&zappy->graph.msg);
}