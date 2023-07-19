/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:28 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/07 14:36:32 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_args
{
	int		argc;
	char	**argv;
}			t_args;

typedef struct s_info
{
	unsigned int	nbargs;
	int				bigger;
	int				smaller;
}			t_info;

// testing
int		print_list(t_list *lst, char *str);
void	print_chunks(int **chunks);
t_list	*fill_list(char *inp);

// parsing
int		check_order(t_list *stk);
t_list	*get_arg(char *arg, t_list *ret);
void	read_args(t_args args, t_list **stka);
t_list	*get_ordinals(t_list *stka, t_info info);

// operations
int		operation(t_list **stka, t_list **stkb, char *operation);
int		swap(t_list **stk);
int		push(t_list **stksrc, t_list **stkdst);
int		rotate(t_list **stk);
int		reverse(t_list **stk);

// sorting
t_info	get_info(t_list *stk);
int		**make_matrix(t_info info);
long	get_closest(t_list *stk, int *chunk, t_info *info);
void	sort(t_list **stka);
void	sort_2(t_list **stk, t_list **stkb);
void	sort_3(t_list **stk, t_list **stkb);
void	sort_5(t_info info, t_list **stka);
void	sort_more(t_info info, t_list **stka);

// output
void	print_ops(t_list *lst);
void	output(t_list *operations);
void	print_error(void);

void	dlfree(t_list **lst, void **split);

int	isnbrep(t_list *stk);

#endif