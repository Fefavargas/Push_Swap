/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 09:08:49 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 09:08:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

char	*extract_line(char *stash)
{
	size_t	i;
    size_t	j;
	char	*line;

	i = 0;
    j = 0;
	if (!stash[j])
		return (0);
    while (stash[j] == ' ')
		j++;
	while (stash[j] && stash[j] != ' ')
		i++;
	line = (char *)ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (0);
	i = 0;
	while (stash[j] && stash[j] != ' ')
	{
		line[i] = stash[j];
		i++;
	}
	line[i] = '\0';
	return (line);
}

t_stack_node	*create_node(int number)
{
	t_stack_node	*node;

	node = ft_calloc(1,sizeof(t_stack_node));
	if (!node)
		return (0);
	node->nbr = number;
	node->index = -1;
	return (node);
}

t_stack_node	*create_stack(t_stack_node *stack, char *str, int *count)
{
	t_stack_node	*node;
	size_t			i;
	int				nbr;
	char			*line;

	i = 0;
	while (str[i])
	{
		line = extract_line(str);
		nbr = ft_atoi(line);
		node = create_node(nbr);
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
		*count++;
		str = &str[i];
		i = 0;
	}
	while(stack->prev)
			stack = stack->prev;
	return (stack);
}

/*t_stack_node	*get_stack(int argc, char **argv, int *count)
{
	t_stack_node	*stack;
	t_stack_node	*tmp;
	int				i;
	int	count;

	i = 1; 
	if (i < argc)
		stack = create_stack(0, argv[i], &count);
	tmp = stack;
	while (i < argc - 1)
	{
		while(tmp->next)
			tmp = tmp->next;
		create_stack(tmp, argv[i],  count);
		i++;
	}
	return (stack);
}*/

t_stack_node	create_node2(int number)
{
	t_stack_node	node;

	node.nbr = number;
	node.index = -1;
	return (node);
}

t_stack_node	*create_stack2(t_stack_node *stack, char **str, int *count)
{
	t_stack_node	node;
	size_t			i;
	size_t			j;
	int				nbr;
	char			*line;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && ((str[i][j] > '0' && str[i][j] < '9') || str[i][j] > ' ' || str[i][j] > '\t' || str[i][j] > '\n'))
			j++;
		if (!str[i][j])
		{
			free_array(stack, "Error\n");
			return (0); 
		}
		nbr = ft_atoi(str[i]); // verificar se é int
		node = create_node2(nbr);
		free(str[i]);
		if (!stack)
		{
			node.prev = stack;
			stack->next = &node;
		}
		stack = &node;
		*count++;
		i++;
	}
	while(stack->prev)
			stack = stack->prev;
	return (stack);
}

t_stack_node	*get_stack(int argc, char **argv, int *count)
{
	t_stack_node	*stack;
	t_stack_node	*tmp;
	char	**array;
	int				i;
	int	count;

	
	i = 1;
	tmp = stack;
	while (i < argc)
	{
		array = ft_split_mult(argv[i], " \n\t", &count);
		while(tmp->next)
			tmp = tmp->next;
		create_stack2(tmp, array,  count);
		i++;
	}
	return (stack);
}
