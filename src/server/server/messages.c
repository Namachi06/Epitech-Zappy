/*
** EPITECH PROJECT, 2019
** messages.c
** File description:
** Add a message to write to the client
*/

#include "../../../include/server/server.h"

void del_all_msg(t_msg **message)
{
    t_msg *tmp;

    while ((tmp = *message) != NULL) {
        *message = (*message)->next;
        free(tmp->msg);
        free(tmp);
        tmp = NULL;
    }
}

void del_msg(t_tcp *tcp)
{
    t_msg *tmp;

    if ((tmp = tcp->msg) != NULL) {
        tcp->nbr_msg--;
        tcp->msg = tcp->msg->next;
        free(tmp->msg);
        free(tmp);
        tmp = NULL;
    }
}

int add_msg(t_tcp *tcp, char const *msg)
{
    t_msg *new_msg;
    t_msg *last = tcp->msg;

    if ((new_msg = malloc(sizeof(t_msg))) == NULL)
        return print_error("malloc");
    tcp->nbr_msg++;
    new_msg->msg = strdup(msg);
    new_msg->next = NULL;
    if (tcp->msg == NULL) {
        tcp->msg = new_msg;
        return (0);
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_msg;
    return (0);
}
