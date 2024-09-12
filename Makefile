# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 19:44:40 by fvargas           #+#    #+#              #
#    Updated: 2024/09/12 14:24:27 by fvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap.a

SRCS =	$(wildcard *.c)
OBJS =	$(SRCS:.c=.o)
LIBFT =			libft/libft.a
CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean:	clean
	make -C libft fclean
	rm -f $(NAME)

re:	fclean all

run: $(NAME)
	./$(NAME)