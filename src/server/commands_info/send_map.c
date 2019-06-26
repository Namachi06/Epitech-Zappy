/*
** EPITECH PROJECT, 2019
** send_map.c
** File description:
** Send content of all tiles
*/

#include "../../../include/server/server.h"

int send_map_size(t_zappy *zappy, t_player *player)
{
    char msg[1024];

    (void)player;
    sprintf(msg, "msz %i %i\n", zappy->width, zappy->height);
    add_msg(&player->plyr, msg);
    return (0);
}

int send_tile_content(t_zappy *zappy, t_player *player, int x, int y)
{
    char msg[1024];

    if (!player->act.args[2])
        return (-1);
    if (!is_digit(player->act.args[1]) && !is_digit(player->act.args[2]))
        return (-1);
    if (((x = atoi(player->act.args[1])) > zappy->width ||
        (y = atoi(player->act.args[2])) > zappy->height) || (x <= 0 || y <= 0))
        return (-1);
    sprintf(msg, "bct %i %i %i %i %i %i %i %i %i\n", x, y,
        zappy->map[y - 1][x - 1].rsrcs[FOOD],
        zappy->map[y - 1][x - 1].rsrcs[LINEMATE],
        zappy->map[y - 1][x - 1].rsrcs[DERAUMERE],
        zappy->map[y - 1][x - 1].rsrcs[SIBUR],
        zappy->map[y - 1][x - 1].rsrcs[MENDIANE],
        zappy->map[y - 1][x - 1].rsrcs[PHIRAS],
        zappy->map[y - 1][x - 1].rsrcs[THYSTAME]);
        add_msg(&player->plyr, msg);
    return (0);
}

int send_map(t_zappy *zappy, t_player *player)
{
    char msg[1024];
    int x = 0, y = 0;

    if (player->act.args[1])
        return send_tile_content(zappy, player, x, y);
    for (int i = 0; i < zappy->height; i++) {
        for (int j = 0; j < zappy->width; j++) {
            memset(msg, 0, sizeof(msg));
            sprintf(msg, "mct %i %i %i %i %i %i %i %i %i\n", i + 1, j + 1,
                zappy->map[j][i].rsrcs[FOOD],
                zappy->map[j][i].rsrcs[LINEMATE],
                zappy->map[j][i].rsrcs[DERAUMERE],
                zappy->map[j][i].rsrcs[SIBUR],
                zappy->map[j][i].rsrcs[MENDIANE],
                zappy->map[j][i].rsrcs[PHIRAS],
                zappy->map[j][i].rsrcs[THYSTAME]);
            add_msg(&player->plyr, msg);
        }
    }
    return (0);
}
