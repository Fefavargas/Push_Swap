# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 19:44:40 by fvargas           #+#    #+#              #
#    Updated: 2024/09/03 20:01:27 by fvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap

SRCS :=			$(src/*.c)
OBJS :=			$(SRCS: src/%.c=obj/%.o)
HDRS :=			$(/*.h)

LIBFT =			libft/libft.a

CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g
