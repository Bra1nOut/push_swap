/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:27:35 by levincen          #+#    #+#             */
/*   Updated: 2025/03/25 15:51:43 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	atoi_limits(long int result, int sign)
{
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		ft_error("INT RANGE ERROR");
	return (1);
}

long int	ft_atoi_swap(const char *str)
{
	long int	result;
	int			sign;
	int			i;

	if (!str)
		return (ft_putstr_fd("Error\n", 1), ERROR);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		if (!str[i + 1] || !ft_isdigit(str[i + 1]))
			return (ERROR);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi_limits(result = result * 10 + (str[i] - '0'), sign);
		i++;
	}
	return (result * sign);
}

int	ft_duplicate_number(char *num_str, char **argv, int i)
{
	int num1;
	int num2;

	num1 = ft_atoi_swap(num_str);
	i++;
	while (argv[i])
	{
		num2 = ft_atoi_swap(argv[i]);
		if (num1 == num2)
			return (1);
		i++;
	}
	return (0);
}

void	argv_split(t_check *argv_test, int argc, char **argv)
{
	int		i;

	argv_test->tab = NULL;
	i = 0;
	argv_test->j_split = 1;
	if (argc == 2)
	{
		argv_test->tab = ft_split(argv[1], ' ');
		while (argv_test->tab[argv_test->j_split])
			argv_test->j_split++;
		ft_free(argv_test, argv_test->tab);
		free(argv_test->tab);
	}
	else
	{
		argv_test->j_split = 2;
		i = 1;
		argv_test->tab = &argv[i];
	}
	// printf("%d\n", argv_test->j_split);
}
int	argv_check(t_check *argv_test, int argc)
{
	int		i;
	int		temp;

	i = 0;
	if (argc >= 2)
	{
		if (argv_test->j_split > 1)
		{
			i = 0;
			while (argv_test->tab[i])
			{
				temp = ft_atoi_swap(argv_test->tab[i]);
				if (!ft_isnum(argv_test->tab[i]))
					ft_error("NUM ERROR");
				if (ft_duplicate_number(argv_test->tab[i], argv_test->tab, i))
					ft_error("DUPLICATE ERROR");
				i++;
			}
		}
	}
	else
		exit(0);
	return (1);
}
