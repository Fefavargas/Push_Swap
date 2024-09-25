# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 19:23:54 by fvargas           #+#    #+#              #
#    Updated: 2024/09/20 12:06:27 by fvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g
LIBFT =			libft/libft.a
DEPS = 			push_swap.h
OBJS =			push_swap.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

make: push_swap.o 
	$(CC) -o makefile push_swap.o
