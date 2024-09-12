/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:33:34 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/12 12:16:07 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    rotate(t_stack_node *stack)
{
    t_stack_node    *tmp1;

    tmp1 = stack;
    while (!tmp1->next)
        tmp1 = tmp1->next;
    tmp1->next = stack;
    stack->prev = tmp1;
    stack->next->prev = NULL;
    stack = stack->next;
    tmp1->next->next = NULL;
}

void    ft_ra(t_stack_node  *stack)
{
    ft_putstr_fd("ra\n",1);
    rotate(stack);
}

void    ft_rb(t_stack_node  *stack)
{
    ft_putstr_fd("rb\n",1);
    rotate(stack);
}

void    ft_rr(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("rr\n",1);
    rotate(stack_a);
    rotate(stack_b);
}
