/*
** EPITECH PROJECT, 2019
** init.c
** File description:
** Check server arguments program
*/

#include "../../../include/server/server.h"

void init_zappy(t_zappy *zappy)
{
    zappy->server.fd = 0;
    zappy->server.msg = NULL;
    zappy->graph.fd = 0;
    zappy->graph.msg = NULL;
    zappy->clt_fd = 0;
    zappy->port = 0;
    zappy->width = 0;
    zappy->height = 0;
    zappy->teams = NULL;
    zappy->map = NULL;
    zappy->max_player_per_team = 0;
    zappy->nbr_teams = 0;
    zappy->freq = 100;
}

void init_arguments(t_args *args)
{
    args->zappy_arg[0] = &chk_port;
    args->zappy_arg[1] = &chk_width;
    args->zappy_arg[2] = &chk_height;
    args->zappy_arg[3] = &chk_team_names;
    args->zappy_arg[4] = &chk_clients;
    args->zappy_arg[5] = &chk_freq;
    args->args[0] = "-p";
    args->args[1] = "-x";
    args->args[2] = "-y";
    args->args[3] = "-n";
    args->args[4] = "-c";
    args->args[5] = "-f";
}

int parse_arguments(t_zappy *zappy, t_args *args, char const *argv[],
    int *index)
{
    for (int i = 0; i < 6; i++) {
        if (strcmp(args->args[i], argv[*index]))
            continue;
        if (args->zappy_arg[i](zappy, argv, index, args) != 0)
            return (-1);
        else
            return (0);
    }
    return (fprintf(stderr, "Unkown argument \'%s\'\n", argv[*index]), -1);
}

int verify_data_struct(t_zappy zappy)
{
    int error = 0;

    if (zappy.port == 0)
        error = print_error_msg("Missing \'-p\' argument");
    if (zappy.width == 0)
        error = print_error_msg("Missing \'-x\' argument");
    if (zappy.height == 0)
        error = print_error_msg("Missing \'-y\' argument");
    if (zappy.teams == NULL)
        error = print_error_msg("Missing \'-n\' argument");
    if (zappy.max_player_per_team == 0)
        error = print_error_msg("Missing \'-c\' argument");
    if (error != 0)
        return (-1);
    return (0);
}

int init(int argc, char const *argv[], t_zappy *zappy)
{
    t_args args;

    srand(time(NULL));
    init_arguments(&args);
    init_zappy(zappy);
    for (int i = 1; i < argc; i++) {
        if (!strcmp("-help", argv[1]))
            return print_usage();
        if (parse_arguments(zappy, &args, argv, &i) != 0)
            return (-1);
    }
    if (verify_data_struct(*zappy) != 0)
        return (-1);
    zappy->food_freq = 126.0f / zappy->freq;
    init_cmds(&zappy->cmd);
    return init_map(zappy);
}
