/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:45:57 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/03 22:00:08 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //deletar

char	*extract_line(char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

t_stack_node	*create_node(t_stack_node *prev, int number, size_t index)
{
	t_stack_node	*node;

	node->nbr = number;
	node->index = index;
	node->prev = prev;
	return (node);
}

int	create_stack(t_stack_node *stack, t_stack_node *prev, char *str)
{
	t_stack_node	*node;
	size_t			i;
	int				nbr;
	int				count;
	char			*line;

	i = 0;
	count = 0;
	//printf("create_stack --%s\n", str);
	while (str[i])
	{
		//printf("str --%s\n", str);
		line = extract_line(str);
		//printf("line: %s \n", line);
		nbr = ft_atoi(line);
		//printf("atoi: %d \n", nbr);
		node = create_node(prev, nbr, count);
		i += ft_strlen(line);
		if (line)
			free(line);
		if (stack == 0)
		{
			stack = node;
			prev = node;
		}
		else
			prev->next = node;
		//printf("node: %d \n", node->nbr);
		count++;
		str = &str[i];
	}
	return (count);
}

t_stack_node	*get_stack(int argc, char **argv)
{
	char			*str;
	t_stack_node	*stack;
	t_stack_node	*prev;
	int				i;
	char	*line;

	i = 1;
	prev = 0;
	stack = 0;
	printf("qtd argc = %d \n", argc);
	while (i < argc)
	{
		printf("get_stack -- i= %d  argv[i] = %s\n", i, argv[i]);
		create_stack(stack, prev, argv[i]);
		i++;
		//printf("index:%d  numbero:%i\n", prev->nbr, (int)prev->index);
		printf("index:%i ", prev->nbr);
	}
	return (stack);
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
	t_stack_node *tmp;

	tmp = stack;
	max = stack->next;
	while (stack->next != NULL)
	{
		tmp = stack->next;
		if (max < tmp->nbr)
			max = tmp->nbr;
	}
	return (max);
}

void	solution_three(t_stack_node *stack_a)
{
	int	max;

	max = find_max(stack_a);
	if (max == stack_a->nbr)
		ft_ra(stack_a);
	if (max == stack_a->prev->nbr)
		ft_rra(stack_a);
	if (!is_sorted(stack_a))
		ft_sa(stack_a);
	return ;
}



void	find_solution(int argc, char **argv)
{
	t_stack_node	*stack;

	stack = get_stack(argc, argv);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	find_solution(argc, argv);
	printf("Fernanda: %s", argv[0]);
	return (0);
}
