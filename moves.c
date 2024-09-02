/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 21:18:54 by fvargas           #+#    #+#             */
/*   Updated: 2024/08/30 22:10:59 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(t_stack_node *from, t_stack_node *to)
{
    to->prev = from;
    from->next = to;
    from = from->next;
    from->prev = NULL;
}

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

void    rrotate(t_stack_node *stack)
{
    t_stack_node    *tmp1;

    tmp1 = stack;
    while (!tmp1->next)
        tmp1 = tmp1->next;
    tmp1->prev->next = NULL;
    tmp1->prev = NULL;
    tmp1->next = stack;
    stack->prev = tmp1;
    stack = tmp1;
}

void    swap(t_stack_node *stack)
{
    t_stack_node    *tmp;

    tmp = stack->next;
    stack->next = tmp->next;
    tmp->next->prev = stack;
    tmp->next = stack;
    stack->prev = tmp;
    tmp->prev = NULL;
    stack = tmp;
}