/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:00:29 by fvargas           #+#    #+#             */
/*   Updated: 2024/08/30 22:10:57 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    ft_ss(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("ss",1);
    swap(stack_a);
     swap(stack_b);
}

void    ft_rr(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("rr",1);
    rotate(stack_a);
    rotate(stack_b);
}

void    ft_rrr(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("rrr",1);
    rrotate(stack_a);
    rrotate(stack_b);
}