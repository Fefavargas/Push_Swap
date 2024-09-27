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
	loop = count / 2 + count % 2;
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