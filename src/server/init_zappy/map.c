/*
** EPITECH PROJECT, 2019
** map.c
** File description:
** Initialize map
*/

#include "../../../include/server/server.h"

void get_tile_rsrcs(t_zappy *zappy, t_player *player)
{
    for (int i = 0; i < 7; i++) {
        player->rsrcs[i] +=
            zappy->map[player->y][player->x].rsrcs[i];
        zappy->map[player->y][player->x].rsrcs[i] = 0;
    }
}

void fill_width_tiles(int hght, t_zappy *zappy)
{
    int ressource = 0;

    for (int wdth = 0; wdth < zappy->width; wdth++) {
        while (ressource < 7)
            zappy->map[hght][wdth].rsrcs[ressource++] = rand() % 15;
        ressource = 0;
    }
}

int init_map(t_zappy *zappy)
{
    int hght = 0;

    if ((zappy->map = malloc(sizeof(t_tile *) * (zappy->height + 1))) == NULL)
        return print_error("malloc");
    for (; hght < zappy->height; hght++) {
        if ((zappy->map[hght] = malloc(sizeof(t_tile) * zappy->width)) == NULL)
            return print_error("malloc");
        fill_width_tiles(hght, zappy);
    }
    zappy->map[hght] = NULL;
    return (0);
}
