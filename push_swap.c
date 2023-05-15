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

t_list	*get_arg(char *arg, t_list *ret)
{
	int		i;
	int		j;
	void	*cont;
	char	**split;

	i = 0;
	split = ft_split(arg, ' ');
	if (!split)
		return (NULL);
	while (split[i])
	{
		j = 0;
		while (split[i] && split[i][j])
			if (!ft_isdigit(split[i][j++]))
				return (ft_dfree((void **)split), NULL);
		cont = malloc(sizeof(int));
		*(int *)cont = ft_atoi(split[i]);
		if (!i++)
			ret = ft_lstnew(cont);
		else
			ft_lstadd_back(&ret, ft_lstnew(cont));
	}
	if (*split)
		return (ft_dfree((void **)split), ret);
	return (ft_dfree((void **)split), NULL);
}

int	read_args(t_args args, t_list **stka)
{
	t_list	*tmp;

	if (args.argc == 1)
		return (printf("%s\n", args.argv[0]), 0);
	else if (args.argc > 1)
	{
		// if (args.argc > 2)
		if (args.argc == 2/*  && ft_strlen(args.argv[1]) */)
			tmp = get_arg(args.argv[1], *stka);
		// printf("-->%i\n", *(int *)tmp->content);
		*stka = tmp;
		if (*stka)
			return (1);
		else
			return (printf("Error\n"), 0);
	}
	else
		return (printf("Error\n"), 0);
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
	if (stka)
	{
		tmp = stka;
		// printf("-->%i\n", *(int *)tmp->content);
		while (i && stka)
		{
			printf("%i\n", *((int *)stka->content));
			stka = stka->next;
		}
		stka = tmp;
		ft_lstclear(&tmp, free);
	}
	return (0);
}
