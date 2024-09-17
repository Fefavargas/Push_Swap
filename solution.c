/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:35:52 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 11:35:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/*t_stack_node	*get_stack(int argc, char **argv);
int	is_sorted(t_stack_node *stack);
int is_repeated(t_stack_node *stack);
int find_max(t_stack_node *stack);
void    indexation(t_stack_node *stack, int count);
void    ft_rra(t_stack_node  *stack);
void    ft_ra(t_stack_node  *stack);
void    ft_sa(t_stack_node  *stack);*/

void	solution_three(t_stack_node *stack_a)
{
	int	max;

	max = find_max(stack_a);
	if (max == stack_a->nbr)
		ft_ra(stack_a);
	else if (max == stack_a->next->nbr)
		ft_rra(stack_a);
	if (!is_sorted(stack_a))
		ft_sa(stack_a);
	return ;
}

void    create_stack_b(t_stack_node *stack_a, t_stack_node *stack_b, int   count)
{
    t_stack_node *tmp;
    int num_target;
    int index;

    tmp = stack_a;
    if (count <= 3)
        return solution_three(tmp);
    index = count / 2;
    if (index < 3)
        index++;
    num_target = find_nbr_index(tmp, index - 1);
    while (tmp)
    {
        if (tmp->nbr < num_target)
            ft_pb(tmp, stack_b);
        tmp = tmp->next;
    }
    create_stack_b(stack_a, stack_b, index);
}

void	find_solution(int argc, char **argv)
{
	t_stack_node	*stack_a;
    t_stack_node	*stack_b;
	int				count;

	stack_a = get_stack(argc, argv, &count);
	if (!stack_a || is_repeated(stack_a))
    {
        free_array(stack_a, "Error\n");
        return;
    }
	indexation(stack_a, count);
    create_stack_b(stack_a, stack_b, count);
    while (stack_b)
    {
        calculate_cost_b(stack_a, stack_b);
        move_stack_b(stack_a, stack_b);
    }
    free_array(stack_a,"");
    free_array(stack_b,"");
}

int top_b_cost(t_stack_node *stack_b,int index)
{
    int cost;
    int size;

    cost = 0;
    while (stack_b && stack_b->index != index)
    {
        stack_b = stack_b->next;
        cost++;
    }
    size = cost;
    while (stack_b)
    {
        stack_b = stack_b->next;
        size++;
    }
    if (cost <= size / 2)
        return (cost);
    return (cost - size);
}

int stack_a_cost(t_stack_node *stack_a, int index)
{
    int cost;
    int size;

    cost = 0;

    while (stack_a && stack_a->index > index)
    {
        cost++;
        stack_a = stack_a->next;
    }
    size = cost;
    while (stack_a)
    {
        size++;
        stack_a = stack_a->next;
    }
    if (cost <= size / 2)
        return (cost);
    return (cost - size);
}

void    calculate_cost_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
    t_stack_node    *tmp;

    tmp = stack_b;
    while (tmp)
    {
        tmp->cost_a = stack_a_cost(stack_a, tmp->index);
        tmp->cost_b = top_b_cost(stack_b, tmp->index);
        tmp = tmp->next;
    }
}

void    move_node(t_stack_node *stack_a, t_stack_node *stack_b, t_stack_node node)
{
    while (node.cost_a < 0 && node.cost_b < 0)
    {
        ft_rrr(stack_a, stack_b);
        node.cost_a++;
        node.cost_b++;
    }
    while (node.cost_a > 0 && node.cost_b > 0)
    {
        ft_rr(stack_a, stack_b);
        node.cost_a--;
        node.cost_b--;
    }
    while (node.cost_a < 0)
    {
        ft_rra(stack_a);
        node.cost_a++;
    }
    while (node.cost_a > 0)
    {
        ft_ra(stack_a);
        node.cost_a--;
    }
    while (node.cost_b < 0)
    {
        ft_rrb(stack_b);
        node.cost_b++;
    }
    while (node.cost_b > 0)
    {
        ft_rb(stack_b);
        node.cost_b--;
    }
    ft_pa(stack_a, stack_b);
}

void    move_stack_b(t_stack_node *stack_a, t_stack_node *stack_b)
{
    int index;
    t_stack_node    tmp;

    tmp = *stack_b;
    while (stack_b)
    {
        index = find_min_cost_index(stack_b);
        while (tmp.index != index)
            tmp = *tmp.next;
        move_node(stack_a, stack_b, tmp);
    }
}