/*
** EPITECH PROJECT, 2019
** server.c
** File description:
** Init server socket
*/

#include "../../../include/server/server.h"

void init_select_graph(t_zappy *zappy)
{
    if (zappy->graph.fd == 0)
        return;
    FD_SET(zappy->graph.fd, &zappy->fd_rd);
    FD_SET(zappy->graph.fd, &zappy->fd_wr);
    if (zappy->graph.fd > zappy->sd_max)
        zappy->sd_max = zappy->graph.fd;
}

void init_select(t_zappy *zappy)
{
    t_team *curr = NULL;

    FD_ZERO(&zappy->fd_rd);
    FD_ZERO(&zappy->fd_wr);
    FD_SET(zappy->server.fd, &zappy->fd_rd);
    FD_SET(zappy->server.fd, &zappy->fd_wr);
    zappy->sd_max = zappy->server.fd;
    for (int i = 0; zappy->teams[i]; i++) {
        curr = zappy->teams[i]->players;
        for (; curr != NULL; curr = curr->next) {
            if (curr->player.plyr.fd > 0) {
                FD_SET(curr->player.plyr.fd, &zappy->fd_rd);
                FD_SET(curr->player.plyr.fd, &zappy->fd_wr);
            }
            if (curr->player.plyr.fd > zappy->sd_max)
                zappy->sd_max = curr->player.plyr.fd;
        }
    }
}

int init_socket(t_zappy *zappy, struct sockaddr_in *srv_addr)
{
    int opt = 1;

    if ((zappy->server.fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
        return print_error("Socket");
    if (setsockopt(zappy->server.fd, SOL_SOCKET, SO_REUSEADDR, &opt,
        sizeof(opt)) == -1)
        return print_error("Setsocketopt");
    srv_addr->sin_addr.s_addr = INADDR_ANY;
    srv_addr->sin_port = htons(zappy->port);
    srv_addr->sin_family = AF_INET;
    return (0);
}

int init_server(t_zappy *zappy)
{
    struct sockaddr_in srv_addr;
    int max_clt = zappy->max_player_per_team * zappy->nbr_teams;

    if (init_socket(zappy, &srv_addr) != 0)
        return (-1);
    if (bind(zappy->server.fd, (struct sockaddr *)&srv_addr,
        sizeof(srv_addr)) == -1)
        return print_error("Bind");
    if (listen(zappy->server.fd, ++max_clt) == -1)
        return print_error("Listen");
    return (0);
}
