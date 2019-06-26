/*
** EPITECH PROJECT, 2019
** server.c
** File description:
** Main server loop
*/

#include "../../../include/server/server.h"

t_server_state state = RUNNING;

void handle_sig(int sig)
{
    (void)sig;
    state = STOPPED;
}

int new_connexion(t_zappy *zappy, int *first_connexion)
{
    struct sockaddr_in clt_addr;
    socklen_t size = sizeof(clt_addr);

    if (FD_ISSET(zappy->server.fd, &zappy->fd_rd) == 0)
        return (0);
    if ((zappy->clt_fd =
        accept(zappy->server.fd, (struct sockaddr *)&clt_addr, &size)) == -1)
        return print_error("accept");
    if (get_clt_nbr(zappy) >= (zappy->max_player_per_team * zappy->nbr_teams)) {
        dprintf(zappy->clt_fd, "Server full\n");
        close(zappy->clt_fd);
        return (0);
    }
    dprintf(zappy->clt_fd, "WELCOME\n");
    *first_connexion = 1;
    return (0);
}

int player_interaction(t_zappy *zappy, int first_connexion)
{
    char buffer[1024];
    int team_idx;
    char id[1024];

    if (first_connexion == 1 && FD_ISSET(zappy->clt_fd, &zappy->fd_rd) == 0) {
        get_new_player_team(zappy, &buffer);
        if (set_graphic(zappy, buffer) == 0)
            return (0);
        if (get_team_index(zappy, &team_idx, buffer) != 0)
            return (0);
        create_player(zappy, team_idx);
        sprintf(id, "Id %i\n", zappy->teams[team_idx]->players->player.id);
        add_msg(&zappy->teams[team_idx]->players->player.plyr, id);
        add_msg(&zappy->teams[team_idx]->players->player.plyr, "ok\n");
    } else
        fd_handler(zappy);
    return (0);
}

int server(t_zappy *zappy)
{
    int first_connexion = 0;

    init_server(zappy);
    signal(SIGINT, handle_sig);
    while (state == RUNNING) {
        init_select(zappy);
        init_select_graph(zappy);
        if (select(zappy->sd_max + 1, &zappy->fd_rd, &zappy->fd_wr, NULL, NULL)
            == -1)
            return print_error("Select");
        if (new_connexion(zappy, &first_connexion) != 0)
            return (-1);
        if (player_interaction(zappy, first_connexion) != 0)
            return (-1);
        player_checker(zappy);
        first_connexion = 0;
    }
    return (0);
}