/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:05:31 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/27 12:43:25 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solution_three(t_node **stack_a)
{
	int	max;

	if (is_sorted(*stack_a))
		return ;
	max = find_max(*stack_a).nbr;
	if (max == (*stack_a)->nbr)
		ft_r(stack_a, NULL, "ra", 1);
	else if (max == (*stack_a)->next->nbr)
		ft_rr(stack_a, NULL, "rra", 1);
	if (!is_sorted(*stack_a))
		ft_s(stack_a, NULL, "sa", 1);
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

void	move_stack_b(t_node **stack_a, t_node **stack_b)
{
	int		index;
	t_node	*tmp;

	tmp = *stack_b;
	index = find_min_cost_index(*stack_b);
	while (tmp->index != index)
		tmp = tmp->next;
	move_node_to_stacka(stack_a, stack_b, *tmp);
}

void	solution(t_node **stack_a, t_node **stack_b)
{
	while (stack_b)
	{
		calculate_cost_b(stack_a, &stack_b);
		move_stack_b(&stack_a, &stack_b);
	}
	rotate_stack_a(&stack_a);
	free_stack(&stack_a, "");
}
