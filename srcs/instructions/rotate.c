/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:55:42 by levincen          #+#    #+#             */
/*   Updated: 2025/03/20 17:06:36 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*current;
	int		i;

	i = 1;
	if (ft_lstsize(*stack) <= 1)
		return (-1);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_lstadd_back(stack, first);
	current = *stack;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	return (0);
}

int	ra(t_list **stack_a, bool check)
{
	if (rotate(stack_a) == -1)
		return (-1);
	if (check == true)
		ft_printf("ra\n");
	return (0);
}

int	rb(t_list **stack_b, bool check)
{
	if (rotate(stack_b) == -1)
		return (-1);
	if (check == true)
		ft_printf("rb\n");
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (!ra(stack_a, 1) || !rb(stack_b, 1))
		return (-1);
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
	return (0);
}
