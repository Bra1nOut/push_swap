/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:31:58 by levincen          #+#    #+#             */
/*   Updated: 2025/02/26 17:34:29 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft/libft.h"

# define ERROR 100000000000000

typedef struct s_test
{
	char	**tab;
	int		j_split;
}				t_test;

//Parsing
int			atoi_limits(long int result, int sign);
long int	ft_atoi_swap(const char *str);
int			ft_duplicate_number(char *num_str, char **argv, int i);
void		argv_split(t_test *test, int argc, char **argv);
int			argv_check(t_test *test, int argc);

//Utils
void		ft_error(char *msg);
int			ft_strcmp_swap(char *s1, char *s2);
int			ft_isnum(char *str);
void		ft_free(t_test *test,char **str);

#endif
