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

int	is_repeated(t_node *stack)
{
	t_node	*tmp;
	int		nbr;

	tmp = stack;
	while (tmp->next)
	{
		nbr = tmp->nbr;
		while (stack->next)
		{
			if (nbr == stack->next->nbr)
				return (1);
			stack = stack->next;
		}
		tmp = tmp->next;
		stack = tmp;
	}
	return (0);
}

int	is_sorted(t_node *stack)
{
	int	min;

	min = stack->nbr;
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (min > stack->nbr)
			return (0);
		min = stack->nbr;
	}
	return (1);
}

void	solution_three(t_node **stack_a)
{
	int	max;

	if (is_sorted(*stack_a))
		return ;
	max = find_max(*stack_a).nbr;
	if (max == (*stack_a)->nbr)
		ft_ra(stack_a);
	else if (max == (*stack_a)->next->nbr)
		ft_rra(stack_a);
	if (!is_sorted(*stack_a))
		ft_sa(stack_a);
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
	r_rotate_a (stack_a, rotation);
}

void	indexation(t_node	**stack)
{
	t_node	*tmp;
	size_t	count;
	int		max;

	tmp = *stack;
	max = find_max(*stack).nbr;
	count = ft_count(*stack);
	while (count != 0)
	{
		if (tmp->nbr == max)
		{
			tmp->index = count - 1;
			max = find_max_cmp(*stack, max);
			tmp = *stack;
			count--;
		}
		else
			tmp = tmp->next;
	}
}
