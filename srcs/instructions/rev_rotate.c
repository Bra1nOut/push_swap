/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:15:26 by levincen          #+#    #+#             */
/*   Updated: 2025/03/05 16:01:07 by levincen         ###   ########.fr       */
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
	while(last->next)
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

int	rra(t_list **stack_a, int yes)
{
	if (rev_rotate(stack_a) == -1)
		return (-1);
	if (yes == 1)
		ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b, int yes)
{
	if (rev_rotate(stack_b) == -1)
		return (-1);
	if (yes == 1)
		ft_printf("rrb\n");
	return (0);
}
