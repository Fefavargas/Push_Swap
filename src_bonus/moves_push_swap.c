/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:48 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/30 15:28:24 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "../libft/libft.h"

void	push(t_node	**from, t_node	**to)
{
	t_node	*tmp;

	if (!*from)
		return ;
	tmp = (*from)->next;
	(*from)->next = *to;
	if (*to)
		(*to)->prev = *from;
	*to = *from;
	*from = tmp;
	if (*from)
		(*from)->prev = NULL;
}

void	ft_p(t_node	**stack_a, t_node	**stack_b, char *msg, size_t printable)
{
	if (ft_strncmp(msg, "pa", ft_strlen(msg)) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(msg, "pb", ft_strlen(msg)) == 0)
		push(stack_a, stack_b);
	if (printable)
	{
		ft_putstr_fd(msg, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	swap(t_node **stack)
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

void	ft_s(t_node	**stack_a, t_node	**stack_b, char *msg, size_t printable)
{
	if (ft_strncmp(msg, "sa", ft_strlen(msg)) == 0)
		swap(stack_a);
	else if (ft_strncmp(msg, "sb", ft_strlen(msg)) == 0)
		swap(stack_b);
	else if (ft_strncmp(msg, "ss", ft_strlen(msg)) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (printable)
	{
		ft_putstr_fd(msg, 1);
		ft_putstr_fd("\n", 1);
	}
}