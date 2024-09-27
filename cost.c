/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:38:02 by marvin            #+#    #+#             */
/*   Updated: 2024/09/26 14:38:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_a_cost(t_node *stack_a, int index, int *cost_ar, int *cost_arr)
{
	size_t	size;
	size_t	index_target;
	size_t	last_index;

	size = ft_count(stack_a);
	*cost_ar = 0;
	if (find_max(stack_a).index < index)
		index_target = find_min_index(stack_a);
	else
		index_target = find_min_max_index(stack_a, index).index;
	while (stack_a && stack_a->index != index_target)
	{
		stack_a = stack_a->next;
		*cost_ar++;
	}
	*cost_arr = *cost_ar - size;
}

void	add_cost_node(t_node **node, int cost_a, int cost_b)
{
	(*node)->cost_a = cost_a;
	(*node)->cost_b = cost_b;
}

void	assign_cost(t_node **node, int cost_ar, int cost_arr, int cost_br, int cost_brr)
{
	int	min;

	add_cost_node(node ,cost_ar, cost_br);
	if ( bigger(cost_ar,cost_br) > bigger(abs(cost_arr), abs(cost_brr)))
		add_cost_node(node ,cost_arr, cost_brr);
	
	if (cost_ar + abs(cost_brr) < abs((*node)->cost_a + (*node)->cost_b))
		add_cost_node(node, cost_ar, cost_brr);

	if (abs(cost_arr) + cost_br < abs((*node)->cost_a + (*node)->cost_b))
		add_cost_node(node, cost_arr, cost_br);
}

void	top_b_cost(t_node *stack_b, t_node **node, int cost_ar, int cost_arr)
{
	int		cost_br;
	int		cost_brr;
	size_t	size;

	size = ft_count(stack_b);
	cost_br = 0;
	while (stack_b && stack_b->index != (*node)->index)
	{
		stack_b = stack_b->next;
		cost_br++;
	}
	cost_brr = cost_br - size;
	assign_cost(node, cost_ar, cost_arr, cost_br, cost_brr);
}

void	calculate_cost_b(t_node *stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int	cost_ar;
	int	cost_arr;

	tmp = *stack_b;
	while (tmp)
	{
		top_a_cost(stack_a, tmp->index, &cost_ar, &cost_arr);
		top_b_cost(*stack_b, &tmp, cost_ar, cost_arr);
		tmp = tmp->next;
	}
}