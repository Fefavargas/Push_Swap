/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:54:51 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/12 14:35:29 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stacks_node
{
    int	nbr;
    size_t  index;
    size_t  cost;
    struct  s_stacks_node   *target;
    struct  s_stacks_node   *next;
    struct  s_stacks_node   *prev;
}   t_stack_node;

void    ft_pa(t_stack_node  *stack_a, t_stack_node  *stack_b);
void    ft_pb(t_stack_node  *stack_a, t_stack_node  *stack_b);
void    ft_sa(t_stack_node  *stack);
void    ft_sb(t_stack_node  *stack);
void    ft_ss(t_stack_node  *stack_a, t_stack_node  *stack_b);
void    ft_ra(t_stack_node  *stack);
void    ft_rb(t_stack_node  *stack);
void    ft_rr(t_stack_node  *stack_a, t_stack_node  *stack_b);
void    ft_rra(t_stack_node  *stack);
void    ft_rrb(t_stack_node  *stack);
void    ft_rrr(t_stack_node  *stack_a, t_stack_node  *stack_b);

#endif
