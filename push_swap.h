/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:01:38 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/25 18:27:19 by fvargas          ###   ########.fr       */
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
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

//moves....c
void	ft_pa(t_node **stack_a, t_node **stack_b);
void	ft_pb(t_node **stack_a, t_node **stack_b);
void	ft_sa(t_node **stack);
void	ft_sb(t_node **stack);
void	ft_ss(t_node **stack_a, t_node **stack_b);
void	ft_ra(t_node **stack);
void	ft_rb(t_node **stack);
void	ft_rr(t_node **stack_a, t_node **stack_b);
void	ft_rra(t_node **stack);
void	ft_rrb(t_node **stack);
void	ft_rrr(t_node	**stack_a, t_node	**stack_b);
void	r_rotate_a(t_node **stack_a, int count);
void	move_node(t_node **stack_a, t_node **stack_b, t_node node);
//crate_tack.c
t_node	*create_stack_a(int argc, char **argv);
//crate_tack_b.c
void	create_stack_b(t_node **stack_a, t_node **stack_b);
//cost.c
void	calculate_cost_b(t_node *stack_a, t_node **stack_b);
//util.c
size_t	find_min_index(t_node *stack);
t_node	find_max(t_node *stack);
t_node	find_min_max_index(t_node *stack_a, int index);
int		find_max_cmp(t_node *stack, int max);
size_t	ft_count(t_node *stack);
//util2.
int		size_loop_push_b(int count);
int		find_min_cost_index(t_node *stack_b);
//solutin.c
int		is_repeated(t_node *stack);
int		is_sorted(t_node *stack);
void	solution_three(t_node **stack_a);
void	move_stack_b(t_node **stack_a, t_node **stack_b);
void	rotate_stack_a(t_node **stack_a);
//checker.c
int		check_nbr(char *str);
void	free_array_stack(t_node	**stack, char	**array, char	*msg);
void	free_stack(t_node	**stack, char	*msg);

#endif