/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:13:36 by levincen          #+#    #+#             */
/*   Updated: 2025/03/22 17:43:14 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*current;
	int		i;
	int		a;

	a = ft_lstsize(*stack_a);
	printf("size : %i\n", a);
	if (ft_lstsize(*stack_a) < 1)
	{
		return (-1);
	}
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
	return (ft_putstr_fd("pb\n", 1), 0);
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
	return (ft_putstr_fd("pa\n", 1), 0);
}
