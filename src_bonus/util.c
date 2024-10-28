/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:05:31 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/28 12:40:48 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
