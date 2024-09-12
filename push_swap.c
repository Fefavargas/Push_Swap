/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:45:57 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/12 18:56:46 by fvargas          ###   ########.fr       */
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
	while (stash[i] && stash[i] != ' ')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != ' ')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

t_stack_node	*create_node(int number, size_t index)
{
	t_stack_node	*node;

	node = ft_calloc(1,sizeof(t_stack_node));
	if (!node)
		return (0);
	node->nbr = number;
	node->index = index;
	return (node);
}

t_stack_node	*create_stack(t_stack_node *stack, char *str)
{
	t_stack_node	*node;
	size_t			i;
	int				nbr;
	static int		count = 0;
	char			*line;

	i = 0;
	while (str[i])
	{
		line = extract_line(str);
		nbr = ft_atoi(line);
		node = create_node(nbr, count);
				if (!node)
			return (0);
		i = ft_strlen(line) + 1;
		if (line)
			free(line);
		if (stack != 0)
		{
			node->prev = stack;
			stack->next = node;
		}
		stack = node;
		count++;
		str = &str[i];
		i = 0;
	}
	while(stack->prev)
			stack = stack->prev;
	return (stack);
}

t_stack_node	*get_stack(int argc, char **argv)
{
	t_stack_node	*stack;
	t_stack_node	*tmp;
	int				i;
	int				count;

	argc = 3; //deletar
	argv = ft_calloc(argc, sizeof(char*)); //deletar
	argv[0] = ft_calloc(10, sizeof(char)); //deletar
	ft_strlcpy(argv[0], "1 2 3 4", 8); //deletar
	argv[1] = ft_calloc(10, sizeof(char)); //deletar
	ft_strlcpy(argv[1], "5 6 7 8 1", 10); //deletar
	printf("qtd argc = %d \n", argc); //deletar
	//i = 1; //voltar
	i = 0; //deletar
	if (i < argc)
		stack = create_stack(0, argv[i]);
	tmp = stack;
	//while (i < argc - 1) // voltar
	while (i < argc - 2)
	{
		i++;
		while(tmp->next)
			tmp = tmp->next;
		create_stack(tmp, argv[i]);
	}
	return (stack);
}

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
	t_stack_node *tmp;

	tmp = stack;
	max = stack->nbr;
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
	int				i;

	stack = get_stack(argc, argv);
	i = is_repeated(stack);
}

int	main(int argc, char **argv)
{
	// if (argc < 2)
	//  	return (0);
	find_solution(argc, argv);
	printf("Fernanda: %s", argv[0]);
	return (0);
}
