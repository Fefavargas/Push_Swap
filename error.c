/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:16:14 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/27 13:41:38 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

int	check_nbr(char *str)
{
	size_t	j;
	long	nbr;

	j = 0;
	while (str[j])
	{
		if (str[j] == '-')
			j++;
		if (str[j] == '+')
			j++;
		if (!ft_isdigit(str[j++]))
			return (0);
	}
	nbr = ft_atoi(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

void	free_array_stack(t_node	**stack, char	**array, char	*msg)
{
	int		i;

	free_stack(stack, "");
	i = 0;
	while (array[i])
		free(array[i++]);
	ft_putstr_fd(msg, 2);
}

void	free_stack(t_node	**stack, char	*msg)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	ft_putstr_fd(msg, 2);
}
