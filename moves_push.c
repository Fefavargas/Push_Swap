/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:29:48 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/12 11:39:36 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    push(t_stack_node *from, t_stack_node *to)
{
    t_stack_node    *tmp;

    tmp = from->next;
    to->prev = from;
    from->next = to;
    from = tmp;
}

void    ft_pa(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("pa\n", 1);
    push(stack_b, stack_a);
}

void    ft_pb(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("pb\n", 1);
    push(stack_a, stack_b);
}