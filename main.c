/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:30:16 by levincen          #+#    #+#             */
/*   Updated: 2025/02/25 17:58:28 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

int	ft_strcmp_swap(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}


int	ft_duplicate_number(char *num_str, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_strcmp_swap(argv[i], num_str) == 0)
			return (1);
		i++;
	}
	return (0);
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

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
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
		if (!str[i + 1])
			return (ERROR);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return ((result * sign));
}

int	argv_check(int argc, char **argv)
{
	int		i;
	int		temp;
	char	**tab;

	tab = NULL;
	i = 0;
	if (argc == 2)
		tab = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		tab = &argv[i];
		printf("Argv : %s\n", argv[i]);
	}
	i = 0;
	while (tab[i])
	{
		temp = ft_atoi_swap(tab[i]);
		printf("Print i: %i\n", i);
		printf("Num : %d\n", temp);
		if (!ft_isnum(tab[i]))
			ft_error("NUM ERROR");
		printf("ft_isnum ok\n");
		if (ft_duplicate_number(tab[i], tab, i))
			ft_error("DUPLICATE ERROR");
		i++;
	}
	if (argc == 2)
		ft_free(tab);
	return (1);
}

int	main(int argc, char **argv)
{
	argv_check(argc, argv);
	printf("Apres argv_check\n");
	return (0);
}
