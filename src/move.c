/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:41:26 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/30 15:29:40 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_b(t_node **stack_b, int count)
{
	while (count < 0)
	{
		ft_rr(NULL, stack_b, "rrb", 1);
		count++;
	}
	while (count > 0)
	{
		ft_r(NULL, stack_b, "rb", 1);
		count--;
	}
}

void	r_rotate_a(t_node **stack_a, int count)
{
	while (count < 0)
	{
		ft_rr(stack_a, NULL, "rra", 1);
		count++;
	}
	while (count > 0)
	{
		ft_r(stack_a, NULL, "ra", 1);
		count--;
	}
}

void	r_rotate_ab(t_node **stack_a, t_node **stack_b, t_node *node)
{
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		ft_rr(stack_a, stack_b, "rrr", 1);
		node->cost_a++;
		node->cost_b++;
	}
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		ft_r(stack_a, stack_b, "rr", 1);
		node->cost_a--;
		node->cost_b--;
	}
}

void	move_node_to_stacka(t_node **stack_a, t_node **stack_b, t_node node)
{
	r_rotate_ab(stack_a, stack_b, &node);
	r_rotate_a(stack_a, node.cost_a);
	r_rotate_b(stack_b, node.cost_b);
	ft_p(stack_a, stack_b, "pa", 1);
}

void	rotate_stack_a(t_node **stack_a)
{
	size_t	size;
	size_t	index_start;
	t_node	*tmp;
	int		rotation;

	size = ft_count(*stack_a);
	index_start = 0;
	tmp = *stack_a;
	while (tmp && tmp->index != 0)
	{
		tmp = tmp->next;
		index_start++;
	}
	rotation = index_start - size;
	if (index_start <= size / 2)
		rotation = index_start;
	r_rotate_a(stack_a, rotation);
}
