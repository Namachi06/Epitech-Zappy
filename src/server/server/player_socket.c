/*
** EPITECH PROJECT, 2019
** player_socket.c
** File description:
** Create or delete player
*/

#include "../../../include/server/server.h"

void init_tcp_player(t_zappy *zappy, t_team **new_node)
{
    (*new_node)->player.plyr.nbr_msg = 0;
    (*new_node)->player.plyr.fd = zappy->clt_fd;
    (*new_node)->player.plyr.msg = NULL;
}

void init_player(t_zappy *zappy, t_team **new_node)
{
    static int id = 1;

    init_tcp_player(zappy, new_node);
    (*new_node)->player.id = id++;
    (*new_node)->player.level = 1;
    (*new_node)->player.x = rand() % zappy->width;
    (*new_node)->player.y = rand() % zappy->height;
    (*new_node)->player.timer = time(NULL);
    (*new_node)->player.act.initizalized = 0;
    (*new_node)->player.act.args = NULL;
    (*new_node)->player.act.action = NULL;
    (*new_node)->player.dir = rand() % 4;
    (*new_node)->next = NULL;
    for (int i = 0; i < 7; i++)
        (*new_node)->player.rsrcs[i] = 0;
    zappy->map[(*new_node)->player.y][(*new_node)->player.x].player++;
    get_tile_rsrcs(zappy, &(*new_node)->player);
}

void create_player(t_zappy *zappy, int team)
{
    t_team *new_node = malloc(sizeof(t_team));
    t_team *last = zappy->teams[team]->players;

    zappy->teams[team]->nb_players++;
    init_player(zappy, &new_node);
    dprintf(zappy->clt_fd, "%i\n",
        zappy->max_player_per_team - zappy->teams[team]->nb_players);
    dprintf(zappy->clt_fd, "%i %i\n", zappy->width, zappy->height);
    printf("pnw %i %i %i %i %i %s\n", new_node->player.id,
        new_node->player.x + 1, new_node->player.y + 1,
        new_node->player.dir + 1, new_node->player.level,
        zappy->teams[team]->name);
    if (zappy->teams[team]->players ==  NULL) {
        zappy->teams[team]->players = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

void delete_player(t_zappy *zappy, t_team **players, int clt_fd)
{
    t_team *next = NULL;

    if (*players == NULL)
        return;
    next = (*players)->next;
    if ((*players)->player.plyr.fd == clt_fd) {
        close((*players)->player.plyr.fd);
        zappy->map[(*players)->player.y][(*players)->player.x].player--;
        free(*players);
        *players = next;
    } else {
        delete_player(zappy, &next, clt_fd);
        (*players)->next = next;
    }
}
