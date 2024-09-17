/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:16:57 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 09:16:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int is_repeated(t_stack_node *stack)
{
	t_stack_node	*tmp;
	int				nbr;

	nbr = stack->nbr;
	tmp = stack;
	while(tmp->next)
	{
		while(stack->next)
		{
			if(nbr == stack->next->nbr)
				return (1);
			stack = stack->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_sorted(t_stack_node *stack)
{
	int	min;
	t_stack_node *tmp;

	min = stack->nbr;
	tmp = stack;
	while (stack->next != NULL)
	{
		tmp = stack->next;
		if (min > tmp->nbr)
			return (0);
	}
	return (1);
}

int	find_max(t_stack_node *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (max < stack->nbr)
			max = stack->nbr;
        stack = stack->next;
	}
	return (max);
}

int	find_max_cmp(t_stack_node *stack, int max)
{
    int prev_max;

    prev_max = max;
	while (stack)
	{
		if (prev_max < stack->nbr && stack->nbr < max)
			prev_max = stack->nbr;
        stack = stack->next;
	}
	return (prev_max);
}

void    indexation(t_stack_node *stack, int count)
{
    t_stack_node    *tmp;
    int max;

    tmp = stack;
    max = find_max(stack);
    while (count != 0)
    {
        if (tmp->nbr == max)
        {
            tmp->index = count - 1;
            max = find_max_cmp(stack, max);
            tmp = stack;
        }
        count--;
        tmp = tmp->next;
    }
}

int	find_nbr_index(t_stack_node *stack, int index)
{
	while (stack)
	{
		if (stack->index == index)
			return stack->nbr;
		stack = stack->next;
	}
	return (-1);
}

int	abs(int i)
{
	if (i < 0 && i != -2147483648)
		return (-i);
	return (i);
}

int bigger(int i, int j)
{
	if (i > j)
		return (i);
	return (j);
}

int	find_cost(t_stack_node stack_b)
{
	if (stack_b.cost_a < 0 && stack_b.cost_b < 0)
			return bigger(abs(stack_b.cost_a ),abs(stack_b.cost_b));
	else if (stack_b.cost_a > 0 && stack_b.cost_b > 0)
			return bigger(abs(stack_b.cost_a ),abs(stack_b.cost_b));
	return abs(stack_b.cost_a ) + abs(stack_b.cost_b);
}

int	find_min_cost_index(t_stack_node *stack_b)
{
	int	min_cost;
	int	index;

	index = 0;
	min_cost = fin_cost(*stack_b);
	while (stack_b)
	{

		if (min_cost > find_cost(*stack_b))
		{
			index = stack_b->index;
			min_cost = fin_cost(*stack_b);
		}
		stack_b = stack_b->next;
	}
	return (index);
}