/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:22:24 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/27 15:46:47 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	free_(char *move, t_node **stack_a, t_node **stack_b, char *msg)
{
	free_array_stack(stack_a, move, "");
	free_stack(stack_b, msg);
}

int	main(int argc, char **argv)
{
	char	**moves;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	stack_a = create_stack_a(argc, argv);
	moves = ft_split(argv[argc], "\n");
	while (*moves)
	{
		if (!check_move(*moves, stack_a, stack_b))
		{
			free_(moves, stack_a, stack_b, "Error");
			return (0);
		}
		*moves = (*moves)++;
	}
	free_array_stack(stack_a, moves, "");
	free_stack(stack_b, "");
	return (0);
}
