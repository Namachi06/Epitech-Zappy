/*
** EPITECH PROJECT, 2019
** args2.c
** File description:
** Check arguments part 2
*/

#include "../../../include/server/server.h"

int chk_freq(t_zappy *zappy, char const *argv[], int *index, t_args *args)
{
    int freq = 0;

    (void)args;
    if (!argv[++(*index)] || !is_digit(argv[*index]))
        return print_error_msg("-f: Invalid argument");
    if (!(freq = atoi(argv[*index])))
        return print_error_msg("-f: The frequence number has "
            "to be greater than 0");
    if (freq < MIN_FREQ || freq > MAX_FREQ)
        return (printf("-f: Frequence must be between %i and %i\n",
            MIN_FREQ, MAX_FREQ), -1);
    zappy->freq = freq;
    return (0);
}
