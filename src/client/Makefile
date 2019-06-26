##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Compilation
##

SRC_proj	=	main.cpp \
				Zappy.cpp \
				client/Socket.cpp \
				commands/Commands.cpp \
				AI/Ai.cpp \
				utils/Utils.cpp \
				exceptions/ZappyException.cpp

SRC_test	= 	../../tests/test.c

OBJ		=	$(SRC_proj:.cpp=.o)

CFLAGS	+=	-W -Wall -Wextra -g

LDFLAG	=	-lcriterion -lgcov

NAME	=	../../zappy_ai

%.o: %.cpp
	g++ -c -o $@ $(CFLAGS) $<

all: $(NAME)

$(NAME): $(OBJ)
	@g++ $(OBJ) $(CFLAGS) -o $(NAME) -I../../include/client

tests_run:
	g++ -o ../../client_unit $(SRC_proj) $(SRC_test) $(LDFLAG) --coverage
	../../client_unit

clean:
	rm -f $(OBJ) *.gcno *.gcda

fclean: clean
	rm -f $(NAME) ../../client_unit

re: fclean all
