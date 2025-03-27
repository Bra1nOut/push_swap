/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:28:24 by levincen          #+#    #+#             */
/*   Updated: 2025/03/27 16:55:14 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_error(char *msg, t_check *argv_test, t_list **stack_a)
{
	ft_putendl_fd(msg, 1);
	if (argv_test->split == true)
	{
		ft_free(argv_test, argv_test->tab);
		free(argv_test->tab);
	}
	if (stack_a)
	{
		free(stack_a);
	}
	free(argv_test);
	exit(0);
}

int	ft_strcmp_swap(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isnum(char *str)
{
	int	i;
	int	sign_count;

	i = 0;
	sign_count = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign_count++;
		i++;
	}
	if (sign_count > 1)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_free(t_check *argv_test, char **str)
{
	while (argv_test->j_split >= 0)
		free(str[argv_test->j_split--]);
}

void	free_lst(t_list **stack)
{
	t_list	*next;

	if (!stack)
		return ;
	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	free(stack);
}
