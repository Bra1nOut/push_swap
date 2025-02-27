/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:54:57 by levincen          #+#    #+#             */
/*   Updated: 2025/02/27 17:21:22 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_list(int argc, char **argv ,t_list **stack)
{
	t_list *new;
	int	i;
	int	j;
	int	index;

	i = 1;
	j = 0;
	index = 1;
	*stack = NULL;
	if (argc > 2)
	{
		while (argv[i])
		{
			new = ft_lstnew((int)(long)ft_atoi_swap(argv[i]));
			new->index = index;
			ft_lstadd_back(stack, new);
			printf("%d\n", new->content);
			i++;
			index++;
		}
	}
}
