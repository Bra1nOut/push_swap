/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:56:09 by levincen          #+#    #+#             */
/*   Updated: 2025/03/17 16:59:45 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return(1);
	while(stack)
	{
		if (stack->content > stack->next->content)
			return(false);
		stack = stack->next;
	}
	return (true);
}

void	current_index(t_list *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_a(t_list *stack_a, t_list *stack_b)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_match_index;

	best_match_index = LONG_MIN;
	while(stack_a)
	{
		current_b = stack_b;
		printf("Best_match_index 1 : %ld\n", best_match_index);
		while (current_b)
		{
			if (current_b->content < stack_a->content && current_b->content > best_match_index)
			{
				best_match_index = current_b->content;
				printf("Best_match_index 2 : %ld\n", best_match_index);
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = biggest_finder(stack_b);
		else
			stack_a->target_node = target_node;
		printf("stack_a->target_node : %d\n", stack_a->target_node->content);
		stack_a = stack_a->next;
	}
}

static void	push_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

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

void	set_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			printf("Push : %d\n", stack->content);
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	printf("Cheapest Value : %ld\n", cheapest_value);
}

void	init_nodes_a(t_list *stack_a, t_list *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	push_cost(stack_a, stack_b);
	set_cheapest(stack_a);
}
