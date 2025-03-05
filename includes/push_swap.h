/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:31:58 by levincen          #+#    #+#             */
/*   Updated: 2025/03/05 16:01:32 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include <stdbool.h>
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
bool		stack_sorted(t_list *stack);

//Init List
void		init_list(int argc, char **argv, t_list **stack);

//Instructions
int			swap(t_list **stack);
int			sa(t_list **stack_a, int yes);
int			sb(t_list **stack_b, int yes);
int			ss(t_list **stack_a, t_list **stack_b);
int			pa(t_list **stack_a, t_list **stack_b);
int			pb(t_list **stack_a, t_list **stack_b);
int			rotate(t_list **stack);
int			ra(t_list **stack_a, int yes);
int			rb(t_list **stack_b, int yes);
int			rr(t_list **stack_a, t_list **stack_b);
int			rev_rotate(t_list	**stack);
int			rra(t_list **stack_a, int yes);
int			rra(t_list **stack_a, int yes);
int			rrb(t_list **stack_b, int yes);

//Sort
t_list		*smallest_finder(t_list *stack);
t_list		*biggest_finder(t_list *stack);
int			sort_three(t_list **stack_a);
int			sort_five(t_list **stack_a, t_list **stack_b);

#endif
