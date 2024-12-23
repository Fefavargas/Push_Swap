/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:22:24 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/28 19:49:43 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

size_t	check_move(char *move, t_node **stack_a, t_node **stack_b)
{
	if (!ft_strncmp(move, "sa\n", ft_strlen(move)))
		ft_s(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "sb\n", ft_strlen(move)))
		ft_s(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "ss\n", ft_strlen(move)))
		ft_s(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "pa\n", ft_strlen(move)))
		ft_p(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "pb\n", ft_strlen(move)))
		ft_p(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "ra\n", ft_strlen(move)))
		ft_r(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "rb\n", ft_strlen(move)))
		ft_r(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "rr\n", ft_strlen(move)))
		ft_r(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "rra\n", ft_strlen(move)))
		ft_rr(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "rrb\n", ft_strlen(move)))
		ft_rr(stack_a, stack_b, move, 0);
	else if (!ft_strncmp(move, "rrr\n", ft_strlen(move)))
		ft_rr(stack_a, stack_b, move, 0);
	else
		return (0);
	return (1);
}

int	ft_moves(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_move(line, stack_a, stack_b))
		{
			free_stack(stack_a, "Error\n");
			free_stack(stack_b, "");
			free(line);
			get_next_line(-1);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	free(line);
	get_next_line(-1);
	return (1);
}

void	result(t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(*stack_a) && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_stack(stack_a, "");
	free_stack(stack_b, "");
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = create_stack_a(argc, argv);
	if (!stack_a)
		return (0);
	if (!ft_moves(&stack_a, &stack_b))
	{
		free_stack(&stack_a, "");
		return (0);
	}
	result(&stack_a, &stack_b);
	return (0);
}
