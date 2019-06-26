/*
** EPITECH PROJECT, 2019
** structure.h
** File description:
** Structure header
*/

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

typedef enum direction
{
    UP,
    RIGHT,
    DOWN,
    LEFT
} e_direction;

#define CLIENT_LIFE (1280)
#define CMD_NBR (12)
#define CMD_INFO_NBR (7)

typedef struct s_zappy t_zappy;
typedef struct s_args t_args;
typedef struct s_player t_player;

typedef int (*zappy_args)(t_zappy *zappy, char const *argv[], int *index,
    t_args *args);
typedef int (*cmds)(t_zappy *zappy, t_player *player);
typedef int (*cmds_info)(t_zappy *zappy, t_player *player);

typedef struct s_args
{
    zappy_args zappy_arg[6];
    char *args[6];
} t_args;

typedef struct s_action
{
    time_t start;
    float duration;
    cmds action;
    char **args;
    int initizalized;
} t_action;

typedef struct s_msg
{
    char *msg;
    struct s_msg *next;
} t_msg;

typedef struct s_tcp
{
    int fd;
    int nbr_msg;
    t_msg *msg;
} t_tcp;

typedef struct s_player
{
    int id;
    int rsrcs[7];
    int level;
    int x;
    int y;
    time_t timer;
    t_action act;
    e_direction dir;
    t_tcp plyr;
} t_player;

typedef struct s_team
{
    t_player player;
    struct s_team *next;
} t_team;

typedef struct s_main_team
{
    int nb_players;
    char *name;
    t_team *players;
} t_main_team;

typedef struct s_tile
{
    int player;
    int rsrcs[7];
} t_tile;

typedef struct s_cmd
{
    char *cmd_line;
    char *cmd_str[CMD_NBR];
    cmds cmd[CMD_NBR];
    char *cmd_info_str[CMD_INFO_NBR];
    cmds_info cmd_info[CMD_INFO_NBR];
} t_cmd;

typedef struct s_zappy
{
    int clt_fd;
    int port;
    int width;
    int height;
    int nbr_teams;
    int max_player_per_team;
    int freq;
    float food_freq;
    t_main_team **teams;
    t_tile **map;
    t_tcp server;
    t_tcp graph;
    t_cmd cmd;
    int sd_max;
    fd_set fd_rd;
    fd_set fd_wr;
} t_zappy;

#endif /* !STRUCTURE_H_ */
