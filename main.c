/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:30:16 by levincen          #+#    #+#             */
/*   Updated: 2025/03/20 16:27:12 by levincen         ###   ########.fr       */
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

// static void	set_target_a(t_list *stack_a, t_list *stack_b)
// {
// 	t_list	*current_b;
// 	t_list	*target_node;
// 	long	best_match_index;

// 	while(stack_a)
// 	{
// 		best_match_index = LONG_MIN;
// 		current_b = stack_b;
// 		printf("Best_match_index 1 : %ld\n", best_match_index);
// 		while (current_b)
// 		{
// 			if (current_b->content < stack_a->content && current_b->content > best_match_index)
// 			{
// 				best_match_index = current_b->content;
// 				printf("Best_match_index 2 : %ld\n", best_match_index);
// 				target_node = current_b;
// 			}
// 			current_b = current_b->next;
// 		}
// 		if (best_match_index == LONG_MIN)
// 			stack_a->target_node = biggest_finder(stack_b);
// 		else
// 			stack_a->target_node = target_node;
// 		printf("stack_a->target_node->content : %d\n", stack_a->target_node->content);
// 		stack_a = stack_a->next;
// 	}
// }

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
		// set_target_a(*stack_a, *stack_b);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sort_three(stack_b);
		init_nodes_a(*stack_a, *stack_b);
		if (!stack_sorted(*stack_a))
		{
			if (argc == 4)
				sort_three(stack_a);
			else if (argc == 6)
				sort_five(stack_a, stack_b);
			print_stack(*stack_a);
			print_stack(*stack_b);
			// printf("CA PASSE\n");
		}
		free(argv_test);
		free_lst(stack_a);
		free_lst(stack_b);
	}
	return (0);
}
