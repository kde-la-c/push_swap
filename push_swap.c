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

int	main(int argc, char **argv)
{
	t_args	args;
	t_info	info;
	t_list	*stka;

	args.argc = argc;
	args.argv = argv;
	stka = NULL;
	read_args(args, &stka);
	info = fill_info(stka);
	if (stka)
	{
		// print_list(stka, "a");
		sort(info, &stka, ft_atoi(argv[1]));
		// print_list(stka, "finished");
		dlfree(&stka, NULL);
	}
	return (0);
}
