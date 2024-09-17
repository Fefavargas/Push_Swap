/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:22:33 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 13:22:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h" 

void    free_array(t_stack_node *stack, char *msg)
{
    t_stack_node    *tmp;

    while (stack)
    {
        tmp = stack->next;
        //tmp->next = NULL; //do I need it?
        free(stack);
        stack = tmp;
    }
    ft_putstr_fd(msg, 2);
}