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

#include "checker_bonus.h"
#include "libft/libft.h"

size_t	check_move(char *move, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp(move, "sa", ft_strlen(move)) || !ft_strncmp(move, "sb", ft_strlen(move)))
		ft_s(stack_a,stack_b, move, 0);
	else if (ft_strncmp(move, "ss", ft_strlen(move)) == 0)
		ft_s(stack_a,stack_b, move, 0);
	else if (!ft_strncmp(move, "pa", ft_strlen(move)) || !ft_strncmp(move, "pb", ft_strlen(move)))
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

int	main(int argc, char **argv)
{
	char	**moves;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	moves = ft_split(argv, "\n");
	stack_a = create_stack_a((*moves)++);
	while (*moves)
	{
		if (!check_move(*moves, stack_a, stack_b))
		{
			free_array_stack(moves, stack_a, stack_b, "Error");
			return (0);
		}
		*moves = (*moves)++;
	}
	if (is_sorted(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_array_stack(moves, stack_a, stack_b, "Error");
	return (0);
}
