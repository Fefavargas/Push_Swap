/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 18:28:42 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/28 18:23:24 by fvargas          ###   ########.fr       */
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
	t_node	max;
	size_t	count;

	max = find_max(*stack);
	count = ft_count(*stack);
	max.index = count - 1;
	while (count != 0)
	{
		max = find_max_cmp(*stack, max.nbr);
		max.index = count - 1;
		count--;
	}
}
