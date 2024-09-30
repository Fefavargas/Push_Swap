/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:28:42 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/30 14:10:10 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
