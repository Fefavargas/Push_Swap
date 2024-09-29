/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:01:38 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/27 15:02:21 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stddef.h>

typedef struct s_node
{
	int				nbr;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//moves....c
void	ft_p(t_node	**stack_a, t_node	**stack_b, char *msg, size_t printable);
void	ft_s(t_node	**stack_a, t_node	**stack_b, char *msg, size_t printable);
void	ft_r(t_node	**stack_a, t_node	**stack_b, char *msg, size_t printable);
void	ft_rr(t_node	**stack_a, t_node	**stack_b, char *msg, size_t printable);
//create_stack.c
t_node	*create_stack_a(char *str);
//util.c
int		is_repeated(t_node *stack);
int		is_sorted(t_node *stack);
//error.c
int		check_nbr(char *str);
void	free_array_stack(t_node	**stack_a, t_node	**stack_b, char	**array, char	*msg);
void	free_array(char **array);

#endif