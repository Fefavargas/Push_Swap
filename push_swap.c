/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 22:45:57 by fvargas           #+#    #+#             */
/*   Updated: 2024/08/30 21:16:23 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h> //deletar

// char	*argv_to_string(int argc, char **argv)
// {
// 	char	*str;
// 	char	*argv_space;
// 	size_t	i;

// 	i = 1;
// 	str = "";
// 	while (i != argc)
// 	{
// 		argv_space = ft_strjoin(argv[i], " ");
// 		if (!argv_space)
// 		{
// 			free(str);
// 			return (0);
// 		}
// 		str = ft_strjoin(str, argv_space);
// 		free(argv_space);
// 		if (!str)
// 			return (0);
// 		i++;
// 	}
// 	return (str);
// }

// int	count_nbr(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		while (str[i] != ' ')
// 			i++;
// 		if (str[i] == '+' || str[i] == '-')
// 			i++;
// 		while ((str[i] >= '0' && str[i] <= '9'))
// 			i++;
// 		count += 1;
// 		if (str[i] != ' ' && str[i] != '\0')
// 			return (-1);
// 	}
// 	return (count);
// }

// int	array_int(char *str)
// {
// 	int	size;
// 	int	i;

// 	i = 0;
// 	size = count_nbr(str);
// 	printf("%d", size);
// 	return (size);
// }

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

int	create_stack(t_stack_node	*stack, t_stack_node *prev, char *str)
{
	t_stack_node	*node;
	size_t			i;
	int				nbr;
	int				count;
	char			*line;

	i = 0;
	count = 0;
	while (str[i])
	{
		line = extract_line(str);
		nbr = ft_atoi(line);
		node = create_node(prev, nbr, count);
			if (stack == 0)
				stack = node;
		prev = node;
		count ++;
		i += ft_strlen(line);
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
	while (i < argc)
	{
		printf("aqui\n");
		create_stack(stack, prev, argv[i]);
		i++;
		//printf("index:%d  numbero:%i\n", prev->nbr, (int)prev->index);
		printf("index:%i ", prev->nbr);
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	get_stack(argc, argv);
	printf("Fernanda: %s", argv[0]);
	return (0);
}
