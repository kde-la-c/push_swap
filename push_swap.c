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

#ifndef MALLOC_FAIL
# define MALLOC_FAIL 41
#endif

void	*malloc(size_t size)
{
	static int i = 0;

	if (i == MALLOC_FAIL)
		return (NULL);
	i++;
	return (calloc(size, 1));
}

void	leaks()
{
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_list	*stka;

	atexit(leaks);
	args.argc = argc;
	args.argv = argv;
	read_args(args, &stka);
	if (!check_order(stka))
		sort(&stka);
	dlfree(&stka, NULL);
	return (0);
}
