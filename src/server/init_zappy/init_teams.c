/*
** EPITECH PROJECT, 2019
** init_teams.c
** File description:
** Init teams
*/

#include "../../../include/server/server.h"

int nbr_teams(char const *argv[], int index)
{
    int nbr = 0;

    for (; argv[index] && argv[index][0] != '-'; index++)
        nbr++;
    return (nbr);
}

int check_team_name(char const *argv[], int current, int ref_start)
{
    for (; ref_start != current; ref_start++) {
        if (!strcmp(argv[ref_start], argv[current]))
            return (0);
    }
    return (1);
}

int init_team(const char *name, t_main_team **team)
{
    if (!(*team = malloc(sizeof(t_main_team))))
        return print_error("Malloc");
    (*team)->nb_players = 0;
    (*team)->players = NULL;
    if (!((*team)->name = strdup(name)))
        return print_error("Strdup");
    return (0);
}

int init_teams(t_zappy *zappy, char const *argv[], int *index, int len)
{
    int i = 0;
    int idx_ref = *index;

    for (; i < len; (*index)++, zappy->nbr_teams++) {
        if (!check_team_name(argv, *index, idx_ref)) {
            zappy->teams[i] = NULL;
            return print_error_msg("-n: Team names must be unique");
        }
        if (init_team(argv[*index], &zappy->teams[i++]) != 0)
            return (-1);
    }
    (*index)--;
    zappy->teams[i] = NULL;
    return (0);
}
