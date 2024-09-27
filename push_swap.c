/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:01:21 by fvargas           #+#    #+#             */
/*   Updated: 2024/09/27 13:49:38 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_b = NULL;
	stack_a = NULL;
	if (argc <= 1)
		return (0);
	stack_a = create_stack_a(argc, argv);
	if (!stack_a)
		return (0);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a, "");
		return (0);
	}
	create_stack_b(&stack_a, &stack_b);
	while (stack_b)
	{
		calculate_cost_b(stack_a, &stack_b);
		move_stack_b(&stack_a, &stack_b);
	}
	rotate_stack_a(&stack_a);
	if (is_sorted(stack_a))
		free_stack(&stack_a, "\0/\n");
	return (0);
}
