/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 19:34:02 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/25 18:23:35 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_node_to_b(t_node **stack_a, t_node **stack_b, int count)
{
	size_t	min_index;
	int		loop;
	int		i;

	min_index = find_min_index(*stack_a);
	loop = size_loop_push_b(count);
	i = 0;
	while (i < loop)
	{
		if ((*stack_a)->index < min_index + loop)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
}

void	create_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	count;

	count = ft_count(*stack_a);
	if (count <= 3)
	{
		solution_three(stack_a);
		return ;
	}
	if (count <= 5)
	{
		while (count-- > 3)
			ft_pb(stack_a, stack_b);
	}
	else
		choose_node_to_b(stack_a, stack_b, count);
	create_stack_b(stack_a, stack_b);
}

int	top_a_cost(t_node *stack_a, int index)
{
	int		cost_r;
	int		cost_rr;
	size_t	size;
	size_t	index_target;
	size_t	last_index;

	size = ft_count(stack_a);
	cost_r = 0;
	if (find_max(stack_a).index < index)
		index_target = find_min_index(stack_a);
	else
		index_target = find_min_max_index(stack_a, index).index;
	while (stack_a && stack_a->index != index_target)
	{
		stack_a = stack_a->next;
		cost_r++;
	}
	if (cost_r <= size / 2)
		return (cost_r);
	cost_rr = cost_r - size;
	return (cost_rr);
}

int	top_b_cost(t_node *stack_b, int index)
{
	int		cost_r;
	int		cost_rr;
	size_t	size;

	size = ft_count(stack_b);
	cost_r = 0;
	while (stack_b && stack_b->index != index)
	{
		stack_b = stack_b->next;
		cost_r++;
	}
	if (cost_r <= size / 2)
		return (cost_r);
	cost_rr = cost_r - size;
	return (cost_rr);
}

void	calculate_cost_b(t_node *stack_a, t_node **stack_b)
{
	t_node	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		tmp->cost_a = top_a_cost(stack_a, tmp->index);
		tmp->cost_b = top_b_cost(*stack_b, tmp->index);
		tmp = tmp->next;
	}
}

// int	top_a_cost_old(t_node *stack_a, int index)
// {
// 	int		cost_r;
// 	int		cost_rr;
// 	size_t	size;
// 	size_t	max_index;
// 	size_t	last_index;

// 	size = ft_count(stack_a);
// 	cost_r = 0;
// 	max_index = find_max(stack_a).index;
// 	if (max_index < index)
// 	{
// 		while (stack_a && stack_a->index != find_min_index(stack_a))
// 		{
// 			stack_a = stack_a->next;
// 			cost_r++;
// 		}
// 	}
// 	else
// 	{
// 		//max_index = find_min_max_index(stack_a, index).index;
// 		while (stack_a && stack_a->index < index)
// 		{
// 			stack_a = stack_a->next;
// 			cost_r++;
// 		}
// 	}
// 	if (cost_r <= size / 2)
// 		return (cost_r);
// 	cost_rr = cost_r - size;
// 	return (cost_rr);
// }
