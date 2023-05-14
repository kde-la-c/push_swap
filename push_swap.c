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

t_list	*get_arg(char *arg)
{
	int		i;
	t_list	*ret;
	char	**split;

	i = 0;
	split = ft_split(arg, ' ');
	if (!split)
		return (NULL);
	ret = ft_lstnew(split[i++]);
	while (split[i])
	{
		ret = ret->next;
		ft_lstadd_back(&ret, ft_lstnew(split[i++]));
	}
	if (*split)
		ft_dfree((void **)split, i - 1);
	return (ret);
}

int	read_args(t_args args, t_list **stka)
{
	if (args.argc == 1)
		return (printf("%s\n", args.argv[0]), -1);
	else if (args.argc == 2 && ft_strlen(args.argv[1]))
	{
		*stka = get_arg(args.argv[1]);
		if (*stka)
			return (1);
		else
			return (printf("Error\n"), -1);
	}
	// else if (args.argc > 2)
	// 	return (get_args(args));
	else
		return (printf("Error\n"), -1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_args	args;
	t_list	*stka;
	t_list	*tmp;
	// t_list	*stkb;

	args.argc = argc;
	args.argv = argv;
	i = read_args(args, &stka);
	printf("ret :%i\n", i);
	tmp = stka;
	while (i != -1 && stka && stka->next)
	{
		printf("%s\n", (char *)stka->content);
		stka = stka->next;
	}
	stka = tmp;
	ft_lstclear(&stka, free);
	return (0);
}
