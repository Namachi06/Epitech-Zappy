/*
** EPITECH PROJECT, 2019
** init_cmds.c
** File description:
** Initialize commands
*/

#include "../../../include/server/server.h"

void init_cmds_info_str(t_cmd *cmd)
{
    cmd->cmd_info_str[0] = "msz";
    cmd->cmd_info_str[1] = "sgt";
    cmd->cmd_info_str[2] = "bct";
    cmd->cmd_info_str[3] = "tna";
    cmd->cmd_info_str[4] = "ppo";
    cmd->cmd_info_str[5] = "plv";
    cmd->cmd_info_str[6] = "pin";
}

void init_cmds_info_ptr(t_cmd *cmd)
{
    cmd->cmd_info[0] = &send_map_size;
    cmd->cmd_info[1] = &send_frequency;
    cmd->cmd_info[2] = &send_map;
    cmd->cmd_info[3] = &send_teams;
    cmd->cmd_info[4] = &send_player_pos;
    cmd->cmd_info[5] = &send_player_lvl;
    cmd->cmd_info[6] = &send_player_inventory;
}

void init_cmds_str(t_cmd *cmd)
{
    cmd->cmd_str[0] = "Forward";
    cmd->cmd_str[1] = "Right";
    cmd->cmd_str[2] = "Left";
    cmd->cmd_str[3] = "Look";
    cmd->cmd_str[4] = "Connect_nbr";
    cmd->cmd_str[5] = "Inventory";
    cmd->cmd_str[6] = "Take";
    cmd->cmd_str[7] = "Set";
    cmd->cmd_str[8] = "Fork";
    cmd->cmd_str[9] = "Incantation";
    cmd->cmd_str[10] = "Eject";
    cmd->cmd_str[11] = "Broadcast";
}

void init_cmds_ptr(t_cmd *cmd)
{
    cmd->cmd[0] = &forward;
    cmd->cmd[1] = &right;
    cmd->cmd[2] = &left;
    cmd->cmd[3] = &look;
    cmd->cmd[4] = &connect_nbr;
    cmd->cmd[5] = &inventory;
    cmd->cmd[6] = &take;
    cmd->cmd[7] = &set;
    cmd->cmd[8] = &fork_player;
    cmd->cmd[9] = &incantation;
    cmd->cmd[10] = &eject;
    cmd->cmd[11] = &broadcast;
}

void init_cmds(t_cmd *cmd)
{
    init_cmds_str(cmd);
    init_cmds_ptr(cmd);
    init_cmds_info_str(cmd);
    init_cmds_info_ptr(cmd);
}
