/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:31:58 by levincen          #+#    #+#             */
/*   Updated: 2025/02/28 15:57:12 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "../libft/libft/libft.h"

# define ERROR 100000000000000

typedef struct s_check
{
	char	**tab;
	int		j_split;
}				t_check;

//Parsing
int			atoi_limits(long int result, int sign);
long int	ft_atoi_swap(const char *str);
int			ft_duplicate_number(char *num_str, char **argv, int i);
void		argv_split(t_check *argv_test, int argc, char **argv);
int			argv_check(t_check *argv_test, int argc);

//Utils
void		ft_error(char *msg);
int			ft_strcmp_swap(char *s1, char *s2);
int			ft_isnum(char *str);
void		ft_free(t_check *argv_test, char **str);
void		free_lst(t_list **stack);

//Init List
void		init_list(int argc, char **argv ,t_list **stack);

//Instructions
int			swap(t_list **stack);
int			sa(t_list **stack_a, int true);
int			sb(t_list **stack_b, int true);
int			ss(t_list **stack_a, t_list **stack_b)

#endif
