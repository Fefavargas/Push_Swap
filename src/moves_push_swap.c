/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fefa <fefa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:48 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/24 16:16:11 by fefa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
	if (!ft_strncmp(msg, "pa\n", ft_strlen(msg)))
		push(stack_b, stack_a);
	else if (!ft_strncmp(msg, "pb\n", ft_strlen(msg)))
		push(stack_a, stack_b);
	if (printable)
		ft_putstr_fd(msg, 1);
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
	if (!ft_strncmp(msg, "sa\n", ft_strlen(msg)))
		swap(stack_a);
	else if (!ft_strncmp(msg, "sb\n", ft_strlen(msg)))
		swap(stack_b);
	else if (!ft_strncmp(msg, "ss\n", ft_strlen(msg)))
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (printable)
		ft_putstr_fd(msg, 1);
}
