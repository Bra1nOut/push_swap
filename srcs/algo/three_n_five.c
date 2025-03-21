/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_n_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:36:47 by levincen          #+#    #+#             */
/*   Updated: 2025/03/20 17:42:07 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*smallest_finder(t_list *stack)
{
	t_list	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->content < smallest->content)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_list	*biggest_finder(t_list *stack)
{
	t_list	*biggest;

	biggest = stack;
	while (stack)
	{
		if (stack->content > biggest->content)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

void	sort_three(t_list **stack_a)
{
	t_list	*biggest;

	biggest = biggest_finder(*stack_a);
	if ((*stack_a) == biggest)
		ra(stack_a, true);
	else if (biggest == (*stack_a)->next)
		rra(stack_a, true);
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, true);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest;

	while (ft_lstsize(*stack_a) > 3)
	{
		smallest = smallest_finder(*stack_a);
		if (smallest->index <= ft_lstsize(*stack_a) / 2)
		{
			while (*stack_a != smallest)
				ra(stack_a, true);
		}
		else
		{
			while (*stack_a != smallest)
				rra(stack_a, true);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
