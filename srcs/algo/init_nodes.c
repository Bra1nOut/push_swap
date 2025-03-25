/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:54:41 by levincen          #+#    #+#             */
/*   Updated: 2025/03/25 17:05:54 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	if (!stack_a || !stack_b)
		return ;
	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

static void	set_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->content < stack_a->content
				&& current_b->content > best_match_index)
			{
				best_match_index = current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = biggest_finder(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	set_target_b(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		target_node = NULL;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->content > stack_b->content
				&& current_a->content < best_match_index)
			{
				best_match_index = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target_node = smallest_finder(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	init_nodes_a(t_list *stack_a, t_list *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	push_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}

void	init_nodes_b(t_list *stack_a, t_list *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}
