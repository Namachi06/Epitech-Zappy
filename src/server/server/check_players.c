/*
** EPITECH PROJECT, 2019
** check_players.c
** File description:
** Check life, food and handle player actions
*/

#include "../../../include/server/server.h"

int food(t_zappy *zappy, t_team **player)
{
    time_t delay = time(NULL) - (*player)->player.timer;

    if (delay <= (CLIENT_LIFE / zappy->freq))
        return (-1);
    for (; delay >= zappy->food_freq; delay -= zappy->food_freq) {
        if ((*player)->player.rsrcs[FOOD] > 0)
            (*player)->player.rsrcs[FOOD]--;
        (*player)->player.timer = time(NULL);
    }
    return (0);
}

int life(t_zappy *zappy, t_team **player, int team)
{
    if (food(zappy, player) != 0)
        return (0);
    if ((*player)->player.rsrcs[FOOD] > 0)
        return (0);
    printf("pdi %i\n", (*player)->player.id);
    zappy->teams[team]->nb_players--;
    dprintf((*player)->player.plyr.fd, "dead\n");
    delete_player(zappy, &zappy->teams[team]->players,
        (*player)->player.plyr.fd);
    return (-1);
}

void action(t_zappy *zappy, t_team *player)
{
    time_t delay;

    if (player->player.act.action == NULL)
        return;
    delay = time(NULL) - player->player.act.start;
    if (delay < player->player.act.duration)
        return;
    if ((player->player.act.action)(zappy, &player->player) != 0)
        add_msg(&player->player.plyr, "ko\n");
    player->player.act.action = NULL;
    player->player.act.duration = 0;
    player->player.act.initizalized = 0;
    player->player.act.start = 0;
}

void player_checker(t_zappy *zappy)
{
    t_team *player;

    for (int i = 0; zappy->teams[i]; i++) {
        player = zappy->teams[i]->players;
        for (; player != NULL; player = player->next) {
            if (life(zappy, &player, i) != 0)
                return;
            action(zappy, player);
        }
    }
}
