/*
** EPITECH PROJECT, 2019
** incantation.c
** File description:
** Incantation
*/

#include "../../../include/server/server.h"

void init_player_nbr(int player_nbr[7])
{
    player_nbr[0] = 1;
    player_nbr[1] = 2;
    player_nbr[2] = 2;
    player_nbr[3] = 4;
    player_nbr[4] = 4;
    player_nbr[5] = 6;
    player_nbr[6] = 6;
}

void init_rsrcs2(int rsrcs[7][6])
{
    rsrcs[6][0] = 2;
    rsrcs[6][1] = 2;
    rsrcs[6][2] = 2;
    rsrcs[6][3] = 2;
    rsrcs[6][4] = 2;
    rsrcs[6][5] = 1;
}

void init_rsrcs(int rsrcs[7][6])
{
    rsrcs[0][0] = 1;
    rsrcs[1][0] = 1;
    rsrcs[1][1] = 1;
    rsrcs[1][2] = 1;
    rsrcs[2][0] = 2;
    rsrcs[2][2] = 1;
    rsrcs[2][4] = 2;
    rsrcs[3][0] = 1;
    rsrcs[3][1] = 1;
    rsrcs[3][2] = 2;
    rsrcs[3][4] = 4;
    rsrcs[4][0] = 1;
    rsrcs[4][1] = 2;
    rsrcs[4][2] = 1;
    rsrcs[4][3] = 3;
    rsrcs[5][0] = 1;
    rsrcs[5][1] = 2;
    rsrcs[5][2] = 4;
    rsrcs[5][4] = 1;
    init_rsrcs2(rsrcs);
}

int incantation(t_zappy *zappy, t_player *player)
{
    int player_nbr[7];
    int rsrcs[7][6];

    if (!init_capacities_duration(zappy, player))
        return (0);
    init_player_nbr(player_nbr);
    init_rsrcs(rsrcs);
    add_msg(&player->plyr, "ok\n");
    return (0);
}
