/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:06:56 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/30 16:52:21 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

size_t	find_min_index(t_node *stack)
{
	size_t	min;

	min = stack->index;
	while (stack)
	{
		if ((int)min > stack->index)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}

t_node	*find_max(t_node *stack)
{
	t_node	*node;

	node = stack;
	while (stack)
	{
		if (node->nbr < stack->nbr)
			node = stack;
		stack = stack->next;
	}
	return (node);
}

t_node	*find_max_cmp(t_node *stack, int max)
{
	int		prev_max;
	t_node	*node;

	node = stack;
	prev_max = INT_MIN;
	while (stack)
	{
		if (prev_max < stack->nbr && stack->nbr < max)
		{
			prev_max = stack->nbr;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

t_node	find_min_max_index(t_node *stack_a, int index)
{
	t_node	*tmp;
	t_node	node;

	tmp = stack_a;
	node = *stack_a;
	while (tmp)
	{
		if (tmp->index > index)
			node = *tmp;
		tmp = tmp->next;
	}
	while (stack_a)
	{
		if (node.index > stack_a->index && stack_a->index > index)
			node = *stack_a;
		stack_a = stack_a->next;
	}
	return (node);
}

size_t	ft_count(t_node *stack)
{
	size_t	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
