/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:01:38 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/30 17:29:28 by fvargas          ###   ########.fr       */
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
void	ft_rr(t_node **stack_a, t_node	**stack_b, char *msg, size_t printable);
//create_stack.c
int		create_stack_a(char *str, t_node **stack);
//util.c
int		is_repeated(t_node *stack);
int		is_sorted(t_node *stack);
//error.c
int		check_nbr(char *str);
void	free_stack(t_node **stack_a, t_node **stack_b, char **array, char *msg);
void	free_array(char **array);

#endif