/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 14:36:05 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/07 14:36:08 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef MALLOC_NB
# define MALLOC_NB 5
#endif

void	*malloc(size_t size)
{
	static int i = 0;

	if (i == MALLOC_NB)
		return (NULL);
	i++;
	return (calloc(size, 1));
}

void	leakss()
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_list	*stka;

	atexit(leakss);
	args.argc = argc;
	args.argv = argv;
	read_args(args, &stka);
	if (!check_order(stka))
		sort(&stka);
	dlfree(&stka, NULL);
	return (0);
}
