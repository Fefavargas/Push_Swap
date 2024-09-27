/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:28:42 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/27 12:41:21 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int i)
{
	if (i < 0 && i != -2147483648)
		return (-i);
	return (i);
}

int	bigger_abs(int i, int j)
{
	if (abs(i) > abs(j))
		return (abs(i));
	return (abs(j));
}

int	find_cost(t_node stack_b)
{
	int	i;

	if (stack_b.cost_a < 0 && stack_b.cost_b < 0)
		i = bigger_abs(stack_b.cost_a, stack_b.cost_b);
	else if (stack_b.cost_a > 0 && stack_b.cost_b > 0)
		i = bigger_abs(stack_b.cost_a, stack_b.cost_b);
	else
		i = abs(stack_b.cost_a) + abs(stack_b.cost_b);
	return (i);
}

int	find_min_cost_index(t_node *stack_b)
{
	int	min_cost;
	int	index;

	index = stack_b->index;
	min_cost = find_cost(*stack_b);
	while (stack_b)
	{
		if (min_cost > find_cost(*stack_b))
		{
			index = stack_b->index;
			min_cost = find_cost(*stack_b);
		}
		stack_b = stack_b->next;
	}
	return (index);
}
