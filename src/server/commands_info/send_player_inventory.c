/*
** EPITECH PROJECT, 2019
** send_player_inventory.c
** File description:
** Send player content inventory
*/

#include "../../../include/server/server.h"

int send_plyr_inven(t_team *curr, t_player *player, int *done)
{
    char msg[1024];
    int id = atoi(player->act.args[1]);

    if (curr->player.id != id)
        return (-1);
    *done = 1;
    sprintf(msg, "pin %i %i %i %i %i %i %i %i %i %i\n", id, curr->player.x + 1,
        curr->player.y + 1,
        curr->player.rsrcs[FOOD],
        curr->player.rsrcs[LINEMATE],
        curr->player.rsrcs[DERAUMERE],
        curr->player.rsrcs[SIBUR],
        curr->player.rsrcs[MENDIANE],
        curr->player.rsrcs[PHIRAS],
        curr->player.rsrcs[THYSTAME]);
    add_msg(&player->plyr, msg);
    return (0);
}

int send_player_inventory(t_zappy *zappy, t_player *player)
{
    t_team *curr_plyr;
    int ret = -1;
    int done = 0;

    if (!player->act.args[1] || !is_digit(player->act.args[1]))
        return (-1);
    for (int i = 0; done == 0 && zappy->teams[i]; i++) {
        curr_plyr = zappy->teams[i]->players;
        for (; done == 0 && curr_plyr != NULL; curr_plyr = curr_plyr->next)
            ret = send_plyr_inven(curr_plyr, player, &done);
    }
    if (ret != 0)
        return (-1);
    return (0);
}
