/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:41:26 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/24 21:46:25 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_b(t_node **stack_b, int count)
{
	while (count < 0)
	{
		ft_rrb(stack_b);
		count++;
	}
	while (count > 0)
	{
		ft_rb(stack_b);
		count--;
	}
}

void	r_rotate_a(t_node **stack_a, int count)
{
	while (count < 0)
	{
		ft_rra(stack_a);
		count++;
	}
	while (count > 0)
	{
		ft_ra(stack_a);
		count--;
	}
}

void	r_rotate_ab(t_node **stack_a, t_node **stack_b, t_node *node)
{
	while (node->cost_a < 0 && node->cost_b < 0)
	{
		ft_rrr(stack_a, stack_b);
		node->cost_a++;
		node->cost_b++;
	}
	while (node->cost_a > 0 && node->cost_b > 0)
	{
		ft_rr(stack_a, stack_b);
		node->cost_a--;
		node->cost_b--;
	}
}

void	move_node(t_node **stack_a, t_node **stack_b, t_node node)
{
	r_rotate_ab(stack_a, stack_b, &node);
	r_rotate_a(stack_a, node.cost_a);
	r_rotate_b(stack_b, node.cost_b);
	ft_pa(stack_a, stack_b);
}
