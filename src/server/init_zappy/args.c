/*
** EPITECH PROJECT, 2019
** args.c
** File description:
** Check arguments
*/

#include "../../../include/server/server.h"

int chk_port(t_zappy *zappy, char const *argv[], int *index, t_args *args)
{
    (void)args;
    if (!argv[++(*index)] || !is_digit(argv[*index]))
        return print_error_msg("-p: Invalid argument");
    zappy->port = atoi(argv[*index]);
    return (0);
}

int chk_width(t_zappy *zappy, char const *argv[], int *index, t_args *args)
{
    int width = 0;

    (void)args;
    if (!argv[++(*index)] || !is_digit(argv[*index]))
        return print_error_msg("-x: Invalid argument");
    width = atoi(argv[*index]);
    if (width < MIN_WIDTH || width > MAX_WIDTH) {
        return (printf("-x: Width must be between %i and %i\n",
            MIN_WIDTH, MAX_WIDTH), -1);
    }
    zappy->width = width;
    return (0);
}

int chk_height(t_zappy *zappy, char const *argv[], int *index, t_args *args)
{
    int height = 0;

    (void)args;
    if (!argv[++(*index)] || !is_digit(argv[*index]))
        return print_error_msg("-y: Invalid argument");
    height = atoi(argv[*index]);
    if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
        return (printf("-x: Width must be between %i and %i\n",
            MIN_HEIGHT, MAX_HEIGHT), -1);
    }
    zappy->height = height;
    return (0);
}

int chk_team_names(t_zappy *zappy, char const *argv[], int *index,
    t_args *args)
{
    int teams_len = 0;

    (void)args;
    if (!argv[++(*index)] || argv[*index][0] == '-')
        return print_error_msg("-n: Invalid argument");
    teams_len = nbr_teams(argv, *index);
    if (!(zappy->teams = malloc(sizeof(t_main_team *) * (teams_len + 1))))
        return print_error("Malloc");
    if (init_teams(zappy, argv, index, teams_len) != 0)
        return (-1);
    return (0);
}

int chk_clients(t_zappy *zappy, char const *argv[], int *index,
    t_args *args)
{
    (void)args;
    if (!argv[++(*index)] || !is_digit(argv[*index]))
        return print_error_msg("-c: Invalid argument");
    if (!(zappy->max_player_per_team = atoi(argv[*index])))
        return print_error_msg("-c: The number of clients has "
        "to be greater than 0");
    return (0);
}