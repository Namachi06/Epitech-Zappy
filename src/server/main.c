/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main server program
*/

#include "../../include/server/server.h"

int print_usage(void)
{
    fprintf(stderr, "USAGE: ./zappy_server -p port -x width -y height "
        "-n name1 name2 ... -c clientsNb -f freq\n"
        "\tport is the port number\n"
        "\twidth is the width of the world\n"
        "\theight is the height of the world\n"
        "\tnameX is the name of the team X\n"
        "\tclientsNb is the number of authorized clients per team\n"
        "\tfreq is the reciprocal of time unit for execution of actions\n"
    );
    return (-1);
}

int main(int argc, char const *argv[])
{
    t_zappy zappy;

    if (init(argc, argv, &zappy) != 0) {
        free_zappy(&zappy);
        return (84);
    }
    if (server(&zappy) != 0) {
        free_zappy(&zappy);
        return (84);
    }
    free_zappy(&zappy);
    return (0);
}
