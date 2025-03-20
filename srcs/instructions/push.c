/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:13:36 by levincen          #+#    #+#             */
/*   Updated: 2025/03/20 18:33:39 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*current;
	int		i;

	if (ft_lstsize(*stack_a) < 1)
		return (-1);
	printf("stack a size: %d\n", ft_lstsize(*stack_a));
	i = 1;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	ft_lstadd_front(stack_b, first);
	current = *stack_b;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	current = *stack_a;
	i = 1;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	ft_printf("pb\n");
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*current;
	int		i;

	if (ft_lstsize(*stack_b) < 1)
		return (-1);
	i = 1;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	ft_lstadd_front(stack_a, first);
	current = *stack_a;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	current = *stack_b;
	i = 1;
	while (current)
	{
		current->index = i++;
		current = current->next;
	}
	ft_printf("pa\n");
	return (0);
}
