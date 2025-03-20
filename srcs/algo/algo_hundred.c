/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:03:59 by levincen          #+#    #+#             */
/*   Updated: 2025/03/20 16:52:21 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


t_list	*get_cheapest(t_list *stack)
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
void	rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rr(stack_a, stack_b);
	current_index(stack_a);
	current_index(stack_b);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rrr(stack_a, stack_b);
	current_index(stack_a);
	current_index(stack_b);
}

static void	move_a_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;

	cheapest = get_cheapest(*stack_a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(stack_a	, stack_b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rev_rotate_both(stack_a, stack_b, cheapest);
}

void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = ft_lstsize(*stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
	if (len_a-- > 3 && !stack_sorted(*stack_a))
		pb(stack_b, stack_a);
}

int	algo(t_list **stack_a, t_list **stack_b)
{
	return (1);
}
