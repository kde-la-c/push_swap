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

int	get_args(t_args args, t_list **stka)
{
	char	**split;
	t_list	*new;

	if (args.argc == 1)
	{
		printf("%s\n", args.argv[0]);
		return (-1);
	}
	else if (args.argc == 2)
	{
		split = ft_split(args.argv[1] + 1, ' ');
		while (*split)
		{
			new = ft_lstnew(*(split++));
			ft_lstadd_back(&(*stka), new);
			ft_lstdelone(new, free);
		}
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_list	*stka;
	// t_list	*stkb;

	args.argc = argc;
	args.argv = argv;
	if (get_args(args, &stka) == -1)
	{
		printf("lstsize :%u\n", ft_lstsize(stka));
		return (0);
	}
	return (0);
}
