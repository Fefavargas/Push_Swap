/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:33:34 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/28 12:39:47 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
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
	if (!ft_strncmp(msg, "ra\n", ft_strlen(msg)))
		rotate(stack_a);
	else if (!ft_strncmp(msg, "rb\n", ft_strlen(msg)))
		rotate(stack_b);
	else if (!ft_strncmp(msg, "rr\n", ft_strlen(msg)))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (printable)
		ft_putstr_fd(msg, 1);
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

void	ft_rr(t_node **stack_a, t_node **stack_b, char *msg, size_t print)
{
	if (!ft_strncmp(msg, "rra\n", ft_strlen(msg)))
		rrotate(stack_a);
	else if (!ft_strncmp(msg, "rrb\n", ft_strlen(msg)))
		rrotate(stack_b);
	else if (!ft_strncmp(msg, "rrr\n", ft_strlen(msg)))
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
	if (print)
		ft_putstr_fd(msg, 1);
}
