NAME=out

SRC=test_thread.c

all: $(NAME)

$(NAME):
	cc -pthread $(SRC) -o $(NAME) 
	./$(NAME)

test: re all
	./out

clean:
	rm -f $(NAME)

re: clean all

.PHONY:all test clean re
