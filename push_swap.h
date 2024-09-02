/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:54:51 by fvargas           #+#    #+#             */
/*   Updated: 2024/08/30 20:43:56 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct  s_stacks_node
{
    int  nbr;
    size_t  index;
    size_t  cost;
    struct  s_stacks_node   *target;
    struct  s_stacks_node   *next;
    struct  s_stacks_node   *prev;
}   t_stack_node;

#endif
