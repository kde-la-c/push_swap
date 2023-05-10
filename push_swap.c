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

int	get_args(int argc, char **argv)
{
	if (argc == 1)
	{
		printf("%s\n", argv[0]);
		return (-1);
	}
    return (0);
}

int	main(int argc, char **argv)
{
    printf("%zu\n", ft_strlen("hola"));
	if (get_args(argc, argv) == -1)
		return (0);
	return (0);
}
