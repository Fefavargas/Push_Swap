/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:48:15 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/25 17:06:48 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	indexation(t_node	**stack)
{
	t_node	*tmp;
	size_t	count;
	int		max;

	tmp = *stack;
	max = find_max(*stack).nbr;
	count = ft_count(*stack);
	while (count != 0)
	{
		if (tmp->nbr == max)
		{
			tmp->index = count - 1;
			max = find_max_cmp(*stack, max);
			tmp = *stack;
			count--;
		}
		else
			tmp = tmp->next;
	}
}

t_node	*create_node(int number, t_node	*prev)
{
	t_node	*node;

	node = ft_calloc(sizeof(t_node), 1);
	if (!node)
		return (0);
	node->nbr = number;
	node->index = -1;
	node->next = NULL;
	node->prev = prev;
	return (node);
}

int	get_stack(t_node **stack, char **array)
{
	size_t	i;
	int		nbr;
	t_node	*node;
	t_node	*tmp;

	i = 0;
	while (array[i])
	{
		tmp = *stack;
		while ((tmp && tmp->next))
			tmp = tmp->next;
		if (!check_nbr(array[i]))
			return (0);
		nbr = ft_atoi(array[i++]);
		node = create_node(nbr, tmp);
		if (!node)
			return (0);
		if (*stack == NULL)
			*stack = node;
		else
			tmp->next = node;
	}
	return (1);
}

t_node	*create_stack_a(int argc, char **argv)
{
	t_node	*stack;
	int		i;
	char	**array;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		array = ft_split(argv[i++], ' ');
		if (!get_stack(&stack, array) || is_repeated(stack))
		{
			free_array_stack(&stack, array, "Error\n");
			return (0);
		}
	}
	indexation(&stack);
	return (stack);
}
