/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:38:02 by marvin            #+#    #+#             */
/*   Updated: 2024/09/27 13:40:27 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_a_cost(t_node *stack_a, int index, int *cost_ar, int *cost_arr)
{
	size_t	size;
	size_t	index_target;

	size = ft_count(stack_a);
	*cost_ar = 0;
	if (find_max(stack_a).index < index)
		index_target = find_min_index(stack_a);
	else
		index_target = find_min_max_index(stack_a, index).index;
	while (stack_a && stack_a->index != (int)index_target)
	{
		stack_a = stack_a->next;
		(*cost_ar)++;
	}
	*cost_arr = *cost_ar - size;
}

void	top_b_cost(t_node *stack_b, int index, int *cost_br, int *cost_brr)
{
	size_t	size;

	size = ft_count(stack_b);
	*cost_br = 0;
	*cost_brr = 0;
	while (stack_b && stack_b->index != index)
	{
		stack_b = stack_b->next;
		(*cost_br)++;
	}
	if (size != 1)
		*cost_brr = *cost_br - size;
}

void	add_cost_node(t_node **node, int cost_a, int cost_b)
{
	(*node)->cost_a = cost_a;
	(*node)->cost_b = cost_b;
}

void	assign_cost(t_node *stack_b, t_node **node, int cost_ar, int cost_arr)
{
	int	min;
	int	cost_br;
	int	cost_brr;

	top_b_cost(stack_b, (*node)->index, &cost_br, &cost_brr);
	add_cost_node(node, cost_ar, cost_br);
	if (bigger_abs(cost_ar, cost_br) > bigger_abs(cost_arr, cost_brr))
		add_cost_node(node, cost_arr, cost_brr);
	if (cost_ar - cost_brr < bigger_abs((*node)->cost_a, (*node)->cost_b))
		add_cost_node(node, cost_ar, cost_brr);
	if ((*node)->cost_a > 0 && (*node)->cost_b > 0)
		min = bigger_abs(cost_ar, cost_br);
	else if ((*node)->cost_a < 0 && (*node)->cost_b < 0)
		min = bigger_abs(cost_arr, cost_brr);
	else
		min = (*node)->cost_a - (*node)->cost_b;
	if (-cost_arr + cost_br < min)
		add_cost_node(node, cost_arr, cost_br);
}

void	calculate_cost_b(t_node *stack_a, t_node **stack_b)
{
	t_node	*tmp;
	int		cost_ar;
	int		cost_arr;

	tmp = *stack_b;
	while (tmp)
	{
		top_a_cost(stack_a, tmp->index, &cost_ar, &cost_arr);
		assign_cost(*stack_b, &tmp, cost_ar, cost_arr);
		tmp = tmp->next;
	}
}
