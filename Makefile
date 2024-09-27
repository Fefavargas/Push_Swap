# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 19:23:54 by fvargas           #+#    #+#              #
#    Updated: 2024/09/27 13:38:57 by fvargas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			push_swap
CC =			cc
CFLAGS =		-Wall -Wextra -Werror -g
LIBFT =			libft/libft.a
HDRS :=			$(push_swap.h libft/libft.h)
SRCS = 			cost.c create_stack.c error.c move.c moves_push.c \
				moves_rotate.c moves_rrotate.c moves_swap.c solution.c \
				util.c util2.c push_swap.c

OBJS = 			$(SRCS:.c=.o)

RM = rm -rf

${NAME}: $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: ${NAME}

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean:
	clean
	${RM} ${OBJS}
	make fclean -C libft

re: fclean all

$(OBJS): $(HDRS)
