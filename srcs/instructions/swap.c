/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:20:33 by levincen          #+#    #+#             */
/*   Updated: 2025/03/25 15:15:42 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	int		temp;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	first = *stack;
	second = first->next;
	temp = second->content;
	second->content = first->content;
	first->content = temp;
	return(0);
}

int	sa(t_list **stack_a, bool check)
{
	if (swap(stack_a) == -1)
		return (-1);
	if (check == true)
		ft_printf("sa\n");
	return (0);
}

int	sb(t_list **stack_b, bool check)
{
	if (swap(stack_b) == -1)
		return (-1);
	if (check == true)
		ft_printf("sb\n");
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (!sa(stack_a, 1) || !sb(stack_b, 1))
		return (-1);
	sa(stack_a, false);
	sb(stack_b, false);
	ft_printf("ss\n");
	return (0);
}
