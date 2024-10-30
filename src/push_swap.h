/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:01:38 by fvargas           #+#    #+#             */
/*   Updated: 2024/10/30 16:39:33 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	ft_rr(t_node	**stack_a, t_node	**stack_b, char *msg, size_t print);
//move.c
void	move_node_to_stacka(t_node **stack_a, t_node **stack_b, t_node node);
void	rotate_stack_a(t_node **stack_a);
//create_stack.c
t_node	*create_stack_a(int argc, char **argv);
void	create_stack_b(t_node **stack_a, t_node **stack_b);
//cost.c
void	calculate_cost_b(t_node *stack_a, t_node **stack_b);
//solution.c
void	solution(t_node **stack_a, t_node **stack_b);
void	solution_three(t_node **stack_a);
//error.c
int		check_nbr(char *str);
int		is_repeated(t_node *stack);
void	free_array_stack(t_node	**stack, char	**array, char	*msg);
void	free_stack(t_node	**stack, char	*msg);
void	free_array(char **array);
//util.c
size_t	find_min_index(t_node *stack);
t_node	*find_max(t_node *stack);
t_node	find_min_max_index(t_node *stack_a, int index);
t_node	*find_max_cmp(t_node *stack, int max);
size_t	ft_count(t_node *stack);
//util2.c
int		is_sorted(t_node *stack);
int		bigger_abs(int i, int j);
void	indexation(t_node	**stack);
int		abs(int i);

#endif