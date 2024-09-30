/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:22:24 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/30 17:44:24 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

size_t	check_move(char *move, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp(move, "sa", ft_strlen(move)))
		ft_s(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "sb", ft_strlen(move)))
		ft_s(stack_a, stack_b, move, 0);
	else if (ft_strncmp(move, "ss", ft_strlen(move)) == 0)
		ft_s(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "pa", ft_strlen(move)))
		ft_p(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "pb", ft_strlen(move)))
		ft_p(stack_a, stack_b, move, 0);
	else if (ft_strncmp(move, "ra", ft_strlen(move)) == 0)
		ft_r(stack_a, stack_b, move, 0);
	else if (ft_strncmp(move, "rb", ft_strlen(move)) == 0)
		ft_r(stack_a, stack_b, move, 0);
	else if (ft_strncmp(move, "rr", ft_strlen(move)) == 0)
		ft_r(stack_a, stack_b, move, 0);
	else if (ft_strncmp(move, "rra", ft_strlen(move)) == 0)
		ft_rr(stack_a, stack_b, move, 0);
	else if (ft_strncmp(move, "rrb", ft_strlen(move)) == 0)
		ft_rr(stack_a, stack_b, move, 0);
	else if (ft_strncmp(move, "rrr", ft_strlen(move)) == 0)
		ft_rr(stack_a, stack_b, move, 0);
	else
		return (0);
	return (1);
}

int	ft_moves(char **moves, t_node **stack_a, t_node **stack_b)
{
	char	*tmp;

	tmp = moves[0];
	free(tmp);
	moves++;
	while (*moves)
	{
		if (!check_move(*moves, stack_a, stack_b))
		{
			free_stack(stack_a, stack_b, moves, "Error");
			return (0);
		}
		*moves = (*moves)++;
	}
	return (1);
}

void	result(char **moves, t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(*stack_a) && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stack_a, stack_b, moves, "");
}

int	main(int argc, char **argv)
{
	char	**moves;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	moves = ft_split(argv[1], '\n');
	if (!moves)
		return (0);
	if (!create_stack_a(moves[0], &stack_a))
		return (0);
	if (!(moves[1]))
		result(NULL, &stack_a, &stack_b);
	else if (ft_moves(moves, &stack_a, &stack_b))
		result(moves, &stack_a, &stack_b);
	return (0);
}
