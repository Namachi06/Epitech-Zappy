/*
** EPITECH PROJECT, 2019
** server.h
** File description:
** Server header
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <sys/time.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <ctype.h>
#include <signal.h>
#include <limits.h>
#include <time.h>

#include "structure.h"

#define _GNU_SOURCE
#define MAX_WIDTH 50
#define MIN_WIDTH 10
#define MAX_HEIGHT 50
#define MIN_HEIGHT 10
#define MAX_FREQ 10000
#define MIN_FREQ 1

enum Ressources
{
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD
};

typedef enum s_server_state
{
    RUNNING,
    STOPPED
} t_server_state;

// main.c
int print_usage();

// free.c
void free_zappy(t_zappy *zappy);

// utils.c
int print_error_msg(char *error);
int print_error(char *function);
int is_digit(const char *str);
void remove_char(char *str, char character);
char **my_split(char *str, const char *separator);
void free_split(char **str);

// ------ INIT ZAPPY FOLDER -------

// init.c
int init(int argc, char const *argv[], t_zappy *zappy);

// args.c
int chk_port(t_zappy *zappy, char const *argv[], int *index, t_args *args);
int chk_width(t_zappy *zappy, char const *argv[], int *index, t_args *args);
int chk_height(t_zappy *zappy, char const *argv[], int *index, t_args *args);
int chk_team_names(t_zappy *zappy, char const *argv[], int *index,
    t_args *args);
int chk_clients(t_zappy *zappy, char const *argv[], int *index, t_args *args);
int chk_freq(t_zappy *zappy, char const *argv[], int *index, t_args *args);

// init_teams.c
int nbr_teams(char const *argv[], int index);
int init_teams(t_zappy *zappy, char const *argv[], int *index, int len);

// init_cmds.c
void init_cmds(t_cmd *cmd);

// map.c
int init_map(t_zappy *zappy);
void get_tile_rsrcs(t_zappy *zappy, t_player *player);

// ------ END INIT ZAPPY FOLDER ------

// ------ SERVER FOLDER ------

// init_server.c
int init_server(t_zappy *zappy);
void init_select(t_zappy *zappy);
void init_select_graph(t_zappy *zappy);

// server.c
int server(t_zappy *zappy);

// fd_handler.c
void fd_handler(t_zappy *zappy);

// player_socket.c
void create_player(t_zappy *zappy, int team);
void delete_player(t_zappy *zappy, t_team **players, int clt_fd);

// check_players.c
void player_checker(t_zappy *zappy);

// graphic.c
int set_graphic(t_zappy *zappy, char buffer[1024]);
int graphic_fd_handler(t_zappy *zappy, t_team *player);

// messages.c
int add_msg(t_tcp *tcp, char const *msg);
void del_msg(t_tcp *tcp);
void del_all_msg(t_msg **message);

// server_utils.c
int get_team_index(t_zappy *zappy, int *team, char *team_name);
void get_new_player_team(t_zappy *zappy, char (*buffer)[1024]);
int get_clt_nbr(t_zappy *zappy);

// ------ END SERVER FOLDER ------

// ------ COMMANDS FOLDER ------

// capacities.c
int init_capacities_duration(t_zappy *zappy, t_player *player);
int fork_player(t_zappy *zappy, t_player *player);
int eject(t_zappy *zappy, t_player *player);

// incantation.c
int incantation(t_zappy *zappy, t_player *player);

// interactions.c
int take(t_zappy *zappy, t_player *player);
int set(t_zappy *zappy, t_player *player);

// forward.c
int forward(t_zappy *zappy, t_player *player);

// left.c
int left(t_zappy *zappy, t_player *player);

// right.c
int right(t_zappy *zappy, t_player *player);

// movements.c
int init_movement_duration(t_zappy *zappy, t_player *player);
void move_character(t_zappy *zappy, t_player *player, int x, int y);

// player_info.c
int connect_nbr(t_zappy *zappy, t_player *player);
int inventory(t_zappy *zappy, t_player *player);
int look(t_zappy *zappy, t_player *player);
int broadcast(t_zappy *zappy, t_player *player);

// cmd_utils.c

// ------ END COMMANDS FOLDER ------

// ------ COMMANDS_INFO FOLDER ------

// send_frequency.c
int send_frequency(t_zappy *zappy, t_player *player);

// send_map.c
int send_map(t_zappy *zappy, t_player *player);
int send_map_size(t_zappy *zappy, t_player *player);

// send_player_inventory.c
int send_player_inventory(t_zappy *zappy, t_player *player);

// send_player_lvl.c
int send_player_lvl(t_zappy *zappy, t_player *player);

// send_player_pos.c
int send_player_pos(t_zappy *zappy, t_player *player);

// send_teams.c
int send_teams(t_zappy *zappy, t_player *player);

// ------ END COMMANDS_INFO FOLDER ------

#endif /* !SERVER_H_ */
