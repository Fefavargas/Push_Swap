/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 22:00:29 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/03 18:02:11 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void    ft_sa(t_stack_node  *stack)
{
    ft_putstr_fd("sa ",1);
    swap(stack);
}

void    ft_pa(t_stack_node  *stack_a, t_stack_node  *stack_b)
{
    ft_putstr_fd("pa ",1);
    push(stack_b, stack_a);
}

void    ft_ra(t_stack_node  *stack)
{
    ft_putstr_fd("ra ",1);
    rotate(stack);
}

void    ft_rra(t_stack_node  *stack)
{
    ft_putstr_fd("rra ",1);
    rrotate(stack);
}