# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefa <fefa@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 19:23:54 by fvargas           #+#    #+#              #
#    Updated: 2024/10/24 14:54:36 by fefa             ###   ########.fr        #
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
				src_bonus/moves_push_swap.c src_bonus/moves_rotate.c src_bonus/util.c \

OBJS = 			$(SRCS:.c=.o)

OBJS_BONUS = 	$(SRCS_BONUS:.c=.o)

RM = rm -rf

${NAME}:$(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: ${NAME}

bonus: $(OBJS_BONUS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o checker_bonus

clean:
	${RM} ${OBJS} ${OBJS_BONUS}
	make clean -C ./libft

fclean:	clean
		${RM} ${NAME}
		${RM} checker_bonus
	

re: fclean all

$(OBJS): $(HDRS)
$(OBJS_BONUS): $(HDRS)

