/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:30:16 by levincen          #+#    #+#             */
/*   Updated: 2025/03/04 15:44:01 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void print_stack(t_list *stack)
{
	t_list *current = stack;
	printf("Stack: ");
	while (current)
	{
		printf("%d -> ", current->content);
		current = current->next;
	}
	printf("NULL\n");
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
		stack_a = malloc(sizeof(t_list));
		stack_b = malloc(sizeof(t_list));
		argv_split(argv_test, argc, argv);
		argv_check(argv_test, argc);
		init_list(argc, argv, stack_a);
		*stack_b = NULL;
		// sa(stack_a, 1);
		// pb(stack_a, stack_b);
		// ss(stack_a, stack_b);
		// sb(stack_b, 1);
		// ra(stack_a, 1);
		if (argc == 4)
			sort_three(stack_a);
		else if (argc == 6)
			sort_five(stack_a, stack_b);
		print_stack(*stack_a);
		// printf("CA PASSE\n");
		free(argv_test);
		free_lst(stack_a);
		free_lst(stack_b);
	}
	return (0);
}
