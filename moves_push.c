/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:48 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/24 20:51:57 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void	ft_pa(t_node	**stack_a, t_node	**stack_b)
{
	ft_putstr_fd("pa\n", 1);
	push(stack_b, stack_a);
}

void	ft_pb(t_node	**stack_a, t_node	**stack_b)
{
	ft_putstr_fd("pb\n", 1);
	push(stack_a, stack_b);
}
