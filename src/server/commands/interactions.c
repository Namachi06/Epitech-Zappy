/*
** EPITECH PROJECT, 2019
** interactions.c
** File description:
** Player interactions
*/

#include "../../../include/server/server.h"

int init_interactions_duration(t_zappy *zappy, t_player *player)
{
    if (player->act.initizalized != 0)
        return (-1);
    player->act.initizalized = 1;
    player->act.duration = 7 / zappy->freq;
    if (!strcmp(player->act.args[0], "Take"))
        player->act.action = &take;
    if (!strcmp(player->act.args[0], "Set"))
        player->act.action = &incantation;
    return (0);
}

void take_cmp(t_zappy *zappy, t_player *player)
{
    if (!strcmp(player->act.args[1], "food"))
        player->rsrcs[FOOD] += zappy->map[player->y][player->x].rsrcs[FOOD];
    if (!strcmp(player->act.args[1], "linemate"))
        player->rsrcs[LINEMATE] +=
            zappy->map[player->y][player->x].rsrcs[LINEMATE];
    if (!strcmp(player->act.args[1], "deraumere"))
        player->rsrcs[DERAUMERE] +=
            zappy->map[player->y][player->x].rsrcs[DERAUMERE];
    if (!strcmp(player->act.args[1], "sibur"))
        player->rsrcs[SIBUR] += zappy->map[player->y][player->x].rsrcs[SIBUR];
    if (!strcmp(player->act.args[1], "mendiane"))
        player->rsrcs[MENDIANE] +=
            zappy->map[player->y][player->x].rsrcs[MENDIANE];
    if (!strcmp(player->act.args[1], "phiras"))
        player->rsrcs[PHIRAS] += zappy->map[player->y][player->x].rsrcs[PHIRAS];
    if (!strcmp(player->act.args[1], "thystame"))
        player->rsrcs[THYSTAME] +=
            zappy->map[player->y][player->x].rsrcs[THYSTAME];
}

int take(t_zappy *zappy, t_player *player)
{
    if (player->act.args[1] && !init_interactions_duration(zappy, player))
        return (0);
    if (player->act.args[1] == NULL)
        return (-1);
    take_cmp(zappy, player);
    add_msg(&player->plyr, "ok\n");
    return (0);
}

int set(t_zappy *zappy, t_player *player)
{
    if (!init_interactions_duration(zappy, player))
        return (0);
    add_msg(&player->plyr, "set\n");
    return (0);
}
