NAME=philo

CC=cc
CFLAG=
PTHREAD=
INC= -iquote ./inc/
SRC= ./main.c ./src/input.c

DEB=./src/dump.c

all: $(NAME)

test: fclean
	$(CC) $(CFLAG) $(PTHREAD) $(INC) $(SRC) $(DEB) -o $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(PTHREAD) $(INC) $(SRC) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
