/*
** EPITECH PROJECT, 2019
** server_utils.c
** File description:
** Server util functions
*/

#include "../../../include/server/server.h"

int get_team_index(t_zappy *zappy, int *team, char team_name[1024])
{
    int i = 0;

    for (; zappy->teams[i]; i++) {
        if (!strcmp(zappy->teams[i]->name, team_name)) {
            if (zappy->teams[i]->nb_players < zappy->max_player_per_team) {
                *team = i;
                return (0);
            } else {
                i++;
                break;
            }
        }
    }
    if (zappy->teams[--i]->nb_players >= zappy->max_player_per_team)
        dprintf(zappy->clt_fd, "Team full\n");
    else
        dprintf(zappy->clt_fd, "No such team name\n");
    close(zappy->clt_fd);
    return (-1);
}

void get_new_player_team(t_zappy *zappy, char (*buffer)[1024])
{
    ssize_t rd;

    rd = read(zappy->clt_fd, *buffer, sizeof(*buffer));
    (*buffer)[rd] = '\0';
}

int get_clt_nbr(t_zappy *zappy)
{
    int nbr_clt = 0;

    for (int i = 0; zappy->teams[i]; i++)
        nbr_clt += zappy->teams[i]->nb_players;
    return (nbr_clt);
}
