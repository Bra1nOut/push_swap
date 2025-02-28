/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:54:57 by levincen          #+#    #+#             */
/*   Updated: 2025/02/28 15:07:52 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_non_splitted_list(char **argv, t_list **stack)
{
	t_list *new;
	int	i;
	int	j;
	int	index;

	i = 1;
	j = 0;
	index = 1;
	*stack = NULL;
	while (argv[i])
		{
			new = ft_lstnew((int)(long)ft_atoi_swap(argv[i]));
			new->index = index;
			ft_lstadd_back(stack, new);
			printf("Content : %d, Index : %i\n", new->content, new->index);
			i++;
			index++;
		}
}

void	init_splitted_list(char **splitted_list, t_list **stack)
{
		t_list *new;
		int	i;
		int	j;
		int	index;

		i = 0;
		j = 0;
		index = 1;
		*stack = NULL;
		while (splitted_list[i])
		{
			new = ft_lstnew((int)(long)ft_atoi_swap(splitted_list[i]));
			new->index = index;
			ft_lstadd_back(stack, new);
			printf("Content : %d, Index : %i\n", new->content, new->index);
			i++;
			index++;
		}
}

void	init_list(int argc, char **argv ,t_list **stack)
{
	char	**splitted_list;
	int	j;

	j = 0;
	*stack = NULL;
	splitted_list = NULL;
	if (argc > 2)
		init_non_splitted_list(argv, stack);
	else if (argc == 2)
	{
		splitted_list = ft_split(argv[1], ' ');
		init_splitted_list(splitted_list, stack);
		while(splitted_list[j])
			free(splitted_list[j++]);
		free(splitted_list);
	}
}
