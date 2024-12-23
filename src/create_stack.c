/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:48:15 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/30 22:15:49 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		check_arg(argv[i]);
		array = ft_split(argv[i++], ' ');
		if (!array[0] || !get_stack(&stack, array) || is_repeated(stack))
		{
			free_array_stack(&stack, array, "Error\n");
			return (0);
		}
		free_array(array);
	}
	indexation(&stack);
	return (stack);
}

void	choose_node_to_b(t_node **stack_a, t_node **stack_b, int count)
{
	size_t	min_index;
	int		loop;
	int		i;

	min_index = find_min_index(*stack_a);
	loop = count / 2 + count % 2;
	i = 0;
	while (i < loop)
	{
		if ((*stack_a)->index < (int)min_index + loop)
		{
			ft_p(stack_a, stack_b, "pb\n", 1);
			i++;
		}
		else
			ft_r(stack_a, stack_b, "ra\n", 1);
	}
}

void	create_stack_b(t_node **stack_a, t_node **stack_b)
{
	int	count;

	count = ft_count(*stack_a);
	if (count <= 3)
	{
		solution_three(stack_a);
		return ;
	}
	if (count <= 5)
	{
		while (count-- > 3)
			ft_p(stack_a, stack_b, "pb\n", 1);
	}
	else
		choose_node_to_b(stack_a, stack_b, count);
	create_stack_b(stack_a, stack_b);
}
