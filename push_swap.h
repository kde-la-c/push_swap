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

// free
void	dlfree(t_list **lst, char **split);

// argument handling
t_list	*get_arg(char *arg, t_list *ret);
int		read_args(t_args args, t_list **stka);

#endif