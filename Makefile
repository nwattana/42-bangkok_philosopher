NAME=philo

CC=cc
CFLAG=
PTHREAD= -pthread 
INC= -iquote./inc/
FLIE= ./main.c ./src/input.c\
		./src/routine.c\
		./src/philo_lst.c
		

DEB=

SRC=$(FLIE) $(DEB)

all: $(NAME)

test: fclean
	$(CC) $(CFLAG) $(PTHREAD) $(INC) $(SRC) -o $(NAME)

$(NAME):
	$(CC) $(CFLAG) $(PTHREAD) $(INC) $(SRC) -o $(NAME)

clean:

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
