/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:45:05 by levincen          #+#    #+#             */
/*   Updated: 2025/03/25 17:05:02 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	min_top_check(t_list **stack_a)
{
	while ((*stack_a)->content != smallest_finder(*stack_a)->content)
	{
		if (smallest_finder(*stack_a)->above_median)
			ra(stack_a, true);
		else
			rra(stack_a, true);
	}
}

void	prep_push(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

static void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (!cheapest)
		return ;
	if (!cheapest->target_node)
		return ;
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a, stack_b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
	prep_push(stack_a, cheapest, 'a');
	prep_push(stack_b, cheapest->target_node, 'b');
	pb(stack_a, stack_b);
}

static void	move_b_to_a(t_list **stack_a, t_list **stack_b)
{
	prep_push(stack_a, (*stack_b)->target_node, 'a');
	pa(stack_a, stack_b);
}

void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = ft_lstsize(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_top_check(stack_a);
}
