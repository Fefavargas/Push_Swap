/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:34:56 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/24 20:51:57 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rrotate(t_node	**stack)
{
	t_node	*tmp1;

	tmp1 = *stack;
	while (tmp1 && tmp1->next)
		tmp1 = tmp1->next;
	tmp1->prev->next = NULL;
	tmp1->prev = NULL;
	tmp1->next = *stack;
	(*stack)->prev = tmp1;
	*stack = tmp1;
}

void	ft_rra(t_node	**stack)
{
	ft_putstr_fd("rra\n", 1);
	rrotate(stack);
}

void	ft_rrb(t_node	**stack)
{
	ft_putstr_fd("rrb\n", 1);
	rrotate(stack);
}

void	ft_rrr(t_node	**stack_a, t_node	**stack_b)
{
	ft_putstr_fd("rrr\n", 1);
	rrotate(stack_a);
	rrotate(stack_b);
}
