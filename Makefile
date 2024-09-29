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
HDRS :=			$(src/push_swap.h libft/libft.h src_bonus/checker_bonus.h)
SRCS = 			src/cost.c src/create_stack.c src/error.c src/move.c src/moves_push_swap.c \
				src/moves_rotate.c src/solution.c src/util.c src/util2.c src/push_swap.c

SRCS_BONUS = 	src_bonus/checker_bonus.c src_bonus/create_stack.c src_bonus/error.c \
				src_bonus/moves_push_swap.c src_bonus/moves_rotate.c src_bonus/util.c


OBJS = 			$(SRCS:.c=.o)

RM = rm -rf

${NAME}: 
		make bonus -C libft
		$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all: ${NAME}

clean:
	${RM} ${NAME}
	make clean -C libft

fclean:
	clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

bonus : 
	make bonus -C libft
	$(CC) $(CFLAGS) $(SRCS_BONUS) $(LIBFT) -o checker_bonus

$(OBJS): $(HDRS)
