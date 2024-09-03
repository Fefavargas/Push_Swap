/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 17:55:21 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/03 17:56:08 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    ft_sb(t_stack_node  *stack)
{
    ft_putstr_fd("sb ",1);
    swap(stack);
}

void    ft_pb(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("pb ",1);
    push(stack_b, stack_a);
}

void    ft_rb(t_stack_node  *stack)
{
    ft_putstr_fd("rb ",1);
    rotate(stack);
}

void    ft_rrb(t_stack_node  *stack)
{
    ft_putstr_fd("rrb ",1);
    rrotate(stack);
}