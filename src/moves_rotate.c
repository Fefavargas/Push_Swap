/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:33:34 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/30 15:35:04 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	rotate(t_node **stack)
{
	t_node	*tmp1;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp1 = *stack;
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = *stack;
	(*stack)->prev = tmp1;
	(*stack)->next->prev = NULL;
	*stack = (*stack)->next;
	tmp1->next->next = NULL;
}

void	ft_r(t_node	**stack_a, t_node	**stack_b, char *msg, size_t printable)
{
	if (ft_strncmp(msg, "ra", ft_strlen(msg)) == 0)
		rotate(stack_a);
	else if (ft_strncmp(msg, "rb", ft_strlen(msg)) == 0)
		rotate(stack_b);
	else if (ft_strncmp(msg, "rr", ft_strlen(msg)) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (printable)
	{
		ft_putstr_fd(msg, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rrotate(t_node	**stack)
{
	t_node	*tmp1;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp1 = *stack;
	while (tmp1 && tmp1->next)
		tmp1 = tmp1->next;
	tmp1->prev->next = NULL;
	tmp1->prev = NULL;
	tmp1->next = *stack;
	(*stack)->prev = tmp1;
	*stack = tmp1;
}

void	ft_rr(t_node **stack_a, t_node **stack_b, char *msg, size_t printable)
{
	if (ft_strncmp(msg, "rra", ft_strlen(msg)) == 0)
		rrotate(stack_a);
	else if (ft_strncmp(msg, "rrb", ft_strlen(msg)) == 0)
		rrotate(stack_b);
	else if (ft_strncmp(msg, "rrr", ft_strlen(msg)) == 0)
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
	if (printable)
	{
		ft_putstr_fd(msg, 1);
		ft_putstr_fd("\n", 1);
	}
}
