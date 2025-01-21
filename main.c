/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:30:16 by levincen          #+#    #+#             */
/*   Updated: 2025/01/21 16:04:48 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}

int	ft_duplicate_number(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}
int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	argv_check(int argc, char **argv)
{
	int		i;
	int		temp;
	char	**split_argv;

	split_argv = NULL;
	i = 0;
	if (argc == 2)
		split_argv = ft_split(argv[1], ' ');
	while (argv[i])
	{
		temp = ft_atoi(argv[i]);
		if (!ft_isnum(argv[i]))
			ft_error("Error1");
		printf("Here1\n");
		if (ft_duplicate_number(temp, split_argv, i))
			ft_error("Error2");
		i++;
	}
	free(split_argv);
	return (1);
}

int	main(int argc, char **argv)
{
	argv_check(argc, argv);
	printf("Here2\n");
	return (0);
}
