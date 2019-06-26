##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Main Makefile: Compile all project
##

all: zappy_server zappy_ai zappy_gui

zappy_server:
	@make -C src/server

zappy_ai:
	@make -C src/client

zappy_gui:
	@make -C src/GUI

clean:
	@make clean -s -C src/server
	@make clean -s -C src/client
	@make clean -s -C src/GUI

fclean: clean
	@make fclean -s -C src/server
	@make fclean -s -C src/client
	@make fclean -s -C src/GUI

tests_run:
	@make tests_run -C src/client
	@make tests_run -C src/server
	@make test_run -C src/GUI

re: fclean all

.PHONY:	all zappy_server zappy_ai zappy_gui clean fclean re