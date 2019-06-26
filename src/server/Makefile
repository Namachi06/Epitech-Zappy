##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compilation
##

SRC_proj	=	main.c \
				free.c \
				commands/capacities.c \
				commands/incantation.c \
				commands/interactions.c \
				commands/movements/movements.c \
				commands/movements/forward.c \
				commands/movements/left.c \
				commands/movements/right.c \
				commands/player_info.c \
				commands/cmd_utils.c \
				commands_info/send_frequency.c \
				commands_info/send_map.c \
				commands_info/send_player_pos.c \
				commands_info/send_teams.c \
				commands_info/send_player_lvl.c \
				commands_info/send_player_inventory.c \
				init_zappy/init.c \
				init_zappy/map.c \
				init_zappy/args.c \
				init_zappy/args2.c \
				init_zappy/init_teams.c \
				init_zappy/init_cmds.c \
				server/init_server.c \
				server/server.c \
				server/fd_handler.c \
				server/server_utils.c \
				server/player_socket.c \
				server/check_players.c \
				server/graphic.c \
				server/messages.c \
				utils/utils.c \
				utils/split.c

SRC_test	= 	../../tests/test.c

OBJ		=	$(SRC_proj:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -g

LDFLAG	=	-lcriterion -lgcov

NAME	=	../../zappy_server

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) -o $(NAME) $(CFLAGS) -I../../include/server

tests_run:
	gcc -o ../../server_unit $(SRC_proj) $(SRC_test) $(LDFLAG) --coverage
	../../server_unit

clean:
	rm -f $(OBJ) *.gcno *.gcda

fclean:	clean
	rm -f $(NAME) ../../server_unit

re: fclean all
