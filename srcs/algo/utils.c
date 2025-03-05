/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:56:09 by levincen          #+#    #+#             */
/*   Updated: 2025/03/05 15:58:55 by levincen         ###   ########.fr       */
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
