/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:31:52 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/24 21:26:11 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	swap(t_node **stack) //need to test
{
	t_node	*tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

void	ft_sa(t_node	**stack)
{
	ft_putstr_fd("sa\n", 1);
	swap(stack);
}

void	ft_sb(t_node	**stack)
{
	ft_putstr_fd("sb\n", 1);
	swap(stack);
}

void	ft_ss(t_node	**stack_a, t_node	**stack_b)
{
	ft_putstr_fd("ss\n", 1);
	swap(stack_a);
	swap(stack_b);
}
