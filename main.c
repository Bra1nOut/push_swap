/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:30:16 by levincen          #+#    #+#             */
/*   Updated: 2025/03/27 16:04:49 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	init_all(t_check *argv_test, int argc, char **argv)
{
	argv_split(argv_test, argc, argv);
	argv_check(argv_test, argc);
}

void	algo_start(t_list **stack_a, t_list **stack_b, int argc)
{
	if (!stack_sorted(*stack_a))
		{
			if (argc == 4)
				sort_three(stack_a);
			else if (argc == 6)
				sort_five(stack_a, stack_b);
			else
				sort_stacks(stack_a, stack_b);
		}
}

void	free_all(t_check *argv_test, t_list **stack_a, t_list **stack_b)
{
	if (argv_test->split == true)
	{
		ft_free(argv_test, argv_test->tab);
		free(argv_test->tab);
	}
	free(argv_test);
	free_lst(stack_a);
	free_lst(stack_b);
}

int	main(int argc, char **argv)
{
	t_check	*argv_test;
	t_list	**stack_a;
	t_list	**stack_b;
	int		i;

	i = 1;
	if (argc >= 2)
	{
		(void) argv;
		argv_test = malloc(sizeof(t_check));
		init_all(argv_test, argc, argv);
		stack_a = init_list(argc, argv, argv_test);
		stack_b = malloc(sizeof(t_list));
		*stack_b = NULL;
		algo_start(stack_a, stack_b, argc);
		free_all(argv_test, stack_a, stack_b);
	}
	return (0);
}
