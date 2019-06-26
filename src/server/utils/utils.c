/*
** EPITECH PROJECT, 2019
** utils.c
** File description:
** Utils functions
*/

#include "../../../include/server/server.h"

int print_error_msg(char *error)
{
    fprintf(stderr, "%s\n", error);
    return (-1);
}

int print_error(char *function)
{
    fprintf(stderr, "%s: %s\n", function, strerror(errno));
    return (-1);
}

int is_digit(const char *str)
{
    if (!str)
        return (0);
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}

void remove_char(char *str, char character)
{
    char *tmp;
    int len = 0;

    while (*str) {
        tmp = strchr(str, character);
        if (tmp == NULL)
            break;
        else {
            len = strlen(tmp + 1);
            memmove(tmp, tmp + 1, len);
            tmp[len] = 0;
            str = tmp;
        }
    }
}
