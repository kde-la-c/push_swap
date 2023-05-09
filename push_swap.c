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

int	error(int argc, void **argv)
{
	if (argc == 1)
	{
		printf("%s\n", argv[0]);
		return (-1);
	}
	else if (argc == 2)
	{

	}
}

int	get_args(int argc, void **argv)
{
	if (argc == 1)
	{
		printf("%s\n", argv[0]);
		return (-1);
	}

}

int	main(int argc, void **argv)
{
	t_list	*args;

	if (error(argc, argv) == -1)
		return (0);
	return (0);
}
