##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compilation
##

SRC_proj	=	main.cpp \
				ZappyGui.cpp \
				client/SocketGui.cpp \
				commands/CommandsGui.cpp \
				utils/UtilsGui.cpp \
				exceptions/ZappyExceptionGui.cpp

SRC_test	= 	../../tests/test.c

OBJ		=	$(SRC_proj:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -g

SFMLFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

LDFLAG	=	-lcriterion -lgcov

NAME	=	../../zappy_gui

%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $(SFMLFLAGS) $<

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(OBJ) $(CFLAGS) -o $(NAME) -I../../include/GUI

tests_run:
	g++ -o ../../client_unit $(SRC_proj) $(SRC_test) $(LDFLAG) --coverage
	../../client_unit

clean:
	rm -f $(OBJ) *.gcno *.gcda

fclean: clean
	rm -f $(NAME) ../../client_unit

re: fclean all
