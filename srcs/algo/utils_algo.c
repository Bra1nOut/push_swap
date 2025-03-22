/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:56:09 by levincen          #+#    #+#             */
/*   Updated: 2025/03/22 16:18:26 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	stack_sorted(t_list *stack)
{
	if (!stack)
		return(false);
	while(stack->next)
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
		while (current_b)
		{
			if (current_b->content < stack_a->content && current_b->content > best_match_index)
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

	best_match_index = LONG_MAX;
	while(stack_b)
	{
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->content > stack_b->content && current_a->content < best_match_index)
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
			cheapest_node = stack;
		}
		stack = stack->next;
	}
}

static void min_top_check(t_list **stack_a)
{
	while ((*stack_a)->content != smallest_finder(*stack_a)->content)
	{
		if (smallest_finder(*stack_a)->above_median)
			ra(stack_a, false);
		else
			rra(stack_a, false);
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

t_list	*get_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return (NULL);
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}

void	prep_push(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(*stack_a);
		if (!cheapest)
		return;
	if (!cheapest->target_node)
		return;
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a	, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
	prep_push(stack_a, cheapest, 'a');
	prep_push(stack_a, cheapest->target_node, 'b');
	pb(stack_b, stack_a);
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
	{
		pb(stack_b, stack_a);
	}
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_a, stack_b);
	while (len_a-- > 3 && !stack_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while(*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_top_check(stack_a);
}
