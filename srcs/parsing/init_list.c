/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:54:57 by levincen          #+#    #+#             */
/*   Updated: 2025/03/28 15:27:50 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_non_splitted_list(char **argv, t_list **stack, t_check *argv_test)
{
	t_list		*new;
	int			i;
	int			j;
	int			index;
	long int	result;

	i = 1;
	j = 0;
	index = 1;
	*stack = NULL;
	while (argv[i])
	{
		result = ft_atoi_swap(argv[i]);
		if (result == ERROR)
			ft_error("INT RANGE ERROR", argv_test, stack);
		new = ft_lstnew(result);
		new->index = index;
		ft_lstadd_back(stack, new);
		i++;
		index++;
	}
}

void	init_splitted_list(char **splitted_list,
	t_list **stack, t_check *argv_test)
{
	t_list		*new;
	int			i;
	int			j;
	int			index;
	long int	result;

	i = 0;
	j = 0;
	index = 1;
	*stack = NULL;
	while (splitted_list[i])
	{
		result = ft_atoi_swap(splitted_list[i]);
		if (result == ERROR)
		{
			free_tab(splitted_list);
			ft_error("INT RANGE ERROR", argv_test, stack);
		}
		new = ft_lstnew(result);
		new->index = index;
		ft_lstadd_back(stack, new);
		i++;
		index++;
	}
}

t_list	**init_list(int argc, char **argv, t_check *argv_test)
{
	t_list	**stack_a;
	char	**splitted_list;
	int		j;

	j = 0;
	stack_a = ft_calloc(sizeof(t_list), 1);
	splitted_list = NULL;
	if (argc > 2)
		init_non_splitted_list(argv, stack_a, argv_test);
	else if (argc == 2)
	{
		splitted_list = ft_split(argv[1], " 	");
		init_splitted_list(splitted_list, stack_a, argv_test);
		free_tab(splitted_list);
	}
	return (stack_a);
}
