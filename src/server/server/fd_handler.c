/*
** EPITECH PROJECT, 2019
** fd_handler.c
** File description:
** Fd handler for select
*/

#include "../../../include/server/server.h"

void parse_cmd_info(t_zappy *zappy, t_team *player)
{
    t_action *act = &player->player.act;
    int ret = -1;

    for (int i = 0; act->args && i < CMD_INFO_NBR; i++) {
        if (!strcmp(act->args[0], zappy->cmd.cmd_info_str[i])) {
            ret = zappy->cmd.cmd_info[i](zappy, &player->player);
            break;
        }
    }
    free_split(act->args);
    if (ret == -1)
        add_msg(&player->player.plyr, "ko\n");
    free(zappy->cmd.cmd_line);
    zappy->cmd.cmd_line = NULL;
}

int parse_cmd(t_zappy *zappy, t_team *player)
{
    t_action *act = &player->player.act;
    act->args = my_split(zappy->cmd.cmd_line, " ");
    int ret = -1;

    for (int i = 0; act->args && i < CMD_NBR; i++) {
        if (!strcmp(act->args[0], zappy->cmd.cmd_str[i])) {
            player->player.act.start = time(NULL);
            ret = zappy->cmd.cmd[i](zappy, &player->player);
            break;
        }
    }
    if (ret == -1)
        return (-1);
    free(zappy->cmd.cmd_line);
    zappy->cmd.cmd_line = NULL;
    return (0);
}

void client_write(t_zappy *zappy, t_team *player)
{
    if (FD_ISSET(player->player.plyr.fd, &zappy->fd_wr) == 0)
        return;
    if (player->player.plyr.nbr_msg > 0 && player->player.plyr.msg
        && player->player.plyr.msg->msg) {
        dprintf(player->player.plyr.fd, "%s", player->player.plyr.msg->msg);
        del_msg(&player->player.plyr);
    }
}

int client_read(t_zappy *zappy, t_team *player, int tm)
{
    char buffer[1024];
    ssize_t rd;

    if (FD_ISSET(player->player.plyr.fd, &zappy->fd_rd) == 0)
        return (0);
    memset(buffer, 0, sizeof(buffer));
    if ((rd = recv(player->player.plyr.fd, buffer, sizeof(buffer), 0)) <= 0) {
        printf("pdi %i\n", player->player.id);
        zappy->teams[tm]->nb_players--;
        return (delete_player(zappy, &zappy->teams[tm]->players,
            player->player.plyr.fd), -1);
    }
    buffer[rd] = '\0';
    zappy->cmd.cmd_line = strdup(buffer);
    if (parse_cmd(zappy, player) != 0)
        return (parse_cmd_info(zappy, player), 1);
    return (free_split(player->player.act.args), 1);
}

void fd_handler(t_zappy *zappy)
{
    t_team *players = NULL;

    for (int i = 0; zappy->teams[i]; i++) {
        players = zappy->teams[i]->players;
        for (; players != NULL; players = players->next) {
            if (zappy->graph.fd != 0)
                graphic_fd_handler(zappy, players);
            if (client_read(zappy, players, i) != 0)
                return;
            client_write(zappy, players);
        }
    }
}
