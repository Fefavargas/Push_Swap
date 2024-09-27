/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:16:14 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/27 15:46:10 by fvargas          ###   ########.fr       */
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

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (i >= 0)
		free(*(array + i--));
	free(array);
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

void	free_array_stack(t_node	**stack, char	**array, char	*msg)
{
	free_stack(stack, "");
	free_array(array);
	ft_putstr_fd(msg, 2);
}

size_t	check_move(char *move, t_node **stack_a, t_node **stack_b)
{
	if (ft_strncmp(move, "sa", ft_strlen(move)) == 0)
		ft_sa(stack_a);
	else if (ft_strncmp(move, "sb", ft_strlen(move)) == 0)
		ft_sb(stack_b);
	else if (ft_strncmp(move, "ss", ft_strlen(move)) == 0)
		ft_ss(stack_a, stack_b);
	if (ft_strncmp(move, "pa", ft_strlen(move)) == 0)
		ft_pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb", ft_strlen(move)) == 0)
		ft_pb(stack_a, stack_b);
	if (ft_strncmp(move, "ra", ft_strlen(move)) == 0)
		ft_ra(stack_a);
	else if (ft_strncmp(move, "rb", ft_strlen(move)) == 0)
		ft_rb(stack_b);
	else if (ft_strncmp(move, "rr", ft_strlen(move)) == 0)
		ft_rr(stack_a, stack_b);
	if (ft_strncmp(move, "rra", ft_strlen(move)) == 0)
		ft_rra(stack_a);
	else if (ft_strncmp(move, "rrb", ft_strlen(move)) == 0)
		ft_rrb(stack_b);
	else if (ft_strncmp(move, "rrr", ft_strlen(move)) == 0)
		ft_rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}
