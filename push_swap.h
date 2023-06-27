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

// argument structure
typedef struct s_args
{
	int		argc;
	char	**argv;
}			t_args;

// information structure
typedef struct s_info
{
	int		nbargs;
	int		nbargstmp;
	int		bigger;
	int		smaller;
	int		maxlen;
}			t_info;

// testing
int		print_list(t_list *lst, char *str);
void	print_chunks(int **chunks);
t_list	*fill_list(char *inp);

// argument handling
void	dlfree(t_list **lst, char **split);
t_list	*get_arg(char *arg, t_list *ret);
int		read_args(t_args args, t_list **stka);
t_info	fill_info(t_list *stk);
int		check_order(t_list *stk);
t_list	*get_ordinals(t_list *stka, t_info info);

// operations
void	swap(t_list **stk);
void	push(t_list **stksrc, t_list **stkdst);
void	rotate(t_list **stk);
void	reverse(t_list **stk);

// double operations
void	dswap(t_list **stka, t_list **stkb);
void	drotate(t_list **stka, t_list **stkb);
void	dreverse(t_list **stka, t_list **stkb);

// sorting
void	sort(t_info info, t_list **stka);
void	sort_2(t_list **stk);
void	sort_3(t_list **stk);
void	sort_5(t_info info, t_list **stka);
void	sort_100(t_info info, t_list **stka);

// void	sort_more(t_info info, t_list **stka);
// void	sort_3(t_info info, t_list **stk);
// void	sort(t_info info, t_list **stka, t_list **stkb);
// void	sort(t_info info, t_list **stka, int r);

#endif