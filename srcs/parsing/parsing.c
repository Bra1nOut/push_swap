/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:27:35 by levincen          #+#    #+#             */
/*   Updated: 2025/03/28 16:01:34 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long int	atoi_limits(long int result, int sign)
{
	if ((result * sign) > INT_MAX || (result * sign) < INT_MIN)
		return (ERROR);
	return (1);
}

long	ft_atoi_swap(const char *str)
{
	long	result;
	int		sign;
	int		i;

	if (!str)
		return (ft_putstr_fd("Error\n", 1), ERROR);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
		if (!str[i] || !ft_isdigit(str[i]))
			return (ERROR);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (atoi_limits(result, sign) == ERROR)
			return (ERROR);
	}
	return (result * sign);
}

int	ft_duplicate_number(char *num_str, char **argv, int i)
{
	int	num1;
	int	num2;

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
	argv_test->split = false;
	i = 0;
	argv_test->j_split = 1;
	if (argc == 2)
	{
		argv_test->split = true;
		argv_test->tab = ft_split(argv[1], " 	");
		while (argv_test->tab[argv_test->j_split])
			argv_test->j_split++;
	}
	else
	{
		argv_test->j_split = 2;
		i = 1;
		argv_test->tab = &argv[i];
	}
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
					ft_error("NUM ERROR", argv_test, NULL);
				if (ft_duplicate_number(argv_test->tab[i], argv_test->tab, i))
					ft_error("DUPLICATE ERROR", argv_test, NULL);
				i++;
			}
		}
	}
	else
		exit(0);
	return (1);
}
