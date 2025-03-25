/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:15:26 by levincen          #+#    #+#             */
/*   Updated: 2025/03/25 17:02:21 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rev_rotate(t_list	**stack)
{
	t_list	*last;
	t_list	*almost_last;
	t_list	*current;
	int		i;

	i = 0;
	last = *stack;
	almost_last = NULL;
	while (last->next)
	{
		almost_last = last;
		last = last->next;
	}
	almost_last->next = NULL;
	ft_lstadd_front(stack, last);
	current = *stack;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	return (0);
}

int	rra(t_list **stack_a, bool check)
{
	if (rev_rotate(stack_a) == -1)
		return (-1);
	if (check == true)
		ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b, bool check)
{
	if (rev_rotate(stack_b) == -1)
		return (-1);
	if (check == true)
		ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!rra(stack_a, 1) || !rrb(stack_b, 1))
		return (-1);
	rra(stack_a, false);
	rrb(stack_b, false);
	ft_printf("rrr\n");
	return (0);
}

void	rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest)
{
	while (*stack_b != cheapest->target_node && *stack_a != cheapest)
		rrr(stack_a, stack_b);
	current_index(*stack_a);
	current_index(*stack_b);
}
