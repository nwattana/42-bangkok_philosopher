# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwattana <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 01:37:24 by nwattana          #+#    #+#              #
#    Updated: 2022/12/12 01:37:25 by nwattana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=philo

SRC= philo.c input.c

OBJS	=$(SRC:.c=.o)

CC=cc 
WARNING=-Wall -Wextra -Werror
PTHREAD=-pthread
CFLAGS=$(WARNING) $(PTHREAD)
RM=rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

