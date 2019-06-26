/*
** EPITECH PROJECT, 2019
** graphic.c
** File description:
** Send data to graphic client in order to display it correctly
*/

#include "../../../include/server/server.h"

int set_graphic(t_zappy *zappy, char buffer[1024])
{
    remove_char(buffer, '\r');
    remove_char(buffer, '\n');
    if (strcmp(buffer, "GRAPHIC"))
        return (-1);
    if (zappy->graph.fd == 0) {
        zappy->graph.fd = zappy->clt_fd;
        return (0);
    }
    return (-1);
}

void parse_cmd_info_gui(t_zappy *zappy, char buffer[1024], t_team *player)
{
    char **args = my_split(buffer, " ");
    int ret = -1;

    for (int i = 0; args && i < CMD_INFO_NBR; i++) {
        if (!strcmp(args[0], zappy->cmd.cmd_info_str[i])) {
            ret = zappy->cmd.cmd_info[i](zappy, &player->player);
            break;
        }
    }
    free_split(args);
    if (ret == -1)
        add_msg(&zappy->graph, "ko\n");
}

void graphic_read(t_zappy *zappy, t_team *player)
{
    ssize_t rd;
    char buffer[1024];

    if (FD_ISSET(zappy->graph.fd, &zappy->fd_rd) == 0)
        return;
    memset(buffer, 0, sizeof(buffer));
    if ((rd = recv(zappy->graph.fd, buffer, sizeof(buffer), 0)) <= 0) {
        close(zappy->graph.fd);
        zappy->graph.fd = 0;
        return;
    }
    buffer[rd] = '\0';
    remove_char(buffer, '\r');
    remove_char(buffer, '\n');
    parse_cmd_info_gui(zappy, buffer, player);
}

void graphic_write(t_zappy *zappy)
{
    if (zappy->graph.msg && zappy->graph.msg->msg) {
        dprintf(zappy->graph.fd, "%s", zappy->graph.msg->msg);
        del_msg(&zappy->graph);
    }
}

int graphic_fd_handler(t_zappy *zappy, t_team *player)
{
    graphic_read(zappy, player);
    graphic_write(zappy);
    return (0);
}
