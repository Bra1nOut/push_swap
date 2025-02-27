/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:30:16 by levincen          #+#    #+#             */
/*   Updated: 2025/02/27 17:19:06 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_check	*argv_test;
	t_list	**stack_a;
	t_list	**stack_b;
	if (argc >= 2)
	{
		(void) argv;
		argv_test = malloc(sizeof(t_check));
		stack_a = malloc(sizeof(t_list));
		stack_b = malloc(sizeof(t_list));
		argv_split(argv_test, argc, argv);
		argv_check(argv_test, argc);
		init_list(argc, argv, stack_a);
		printf("CA PASSE\n");
		free(argv_test);
		free_lst(stack_a);
		free(stack_b);
	}
	return (0);
}
