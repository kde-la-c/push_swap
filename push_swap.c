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

t_info	fill_info(t_list *stka)
{
	int		i;
	int		j;
	t_info	ret;

	ret.nbargs = ft_lstsize(stka);
	i = -2147483648;
	j = 2147483647;
	while (stka)
	{
		if (i < *(int *)stka->content)
			i = *(int *)stka->content;
		if (j > *(int *)stka->content)
			j = *(int *)stka->content;
		stka = stka->next;
	}
	ret.bigger = i;
	ret.smaller = j;
	return (ret);
}

t_list	*fill_list(char *inp)
{
	int		i;
	t_list	*ret = NULL;
	void	*cont;
	char	**split;

	i = 0;
	split = ft_split(inp, ' ');
	if (!split)
		return (NULL);
	while (split[i])
	{
		cont = malloc(sizeof(int));
		if (!cont)
			return (dlfree(&ret, split), NULL);
		*(int *)cont = ft_atoi(split[i++]);
		ft_lstadd_back(&ret, ft_lstnew(cont));
	}
	if (*split)
		return (dlfree(NULL, split), ret);
	return (dlfree(NULL, split), NULL);
}

int	print_list(t_list *lst, char *str)
{
	int	i;

	printf("%s :\n", str);
	if (!lst)
		return (-1);
	i = 0;
	while (lst && lst->content)
	{
		// sleep(1);
		printf("%i: \033[0;32m%d\033[0m\n", i++, *((int *)lst->content));
		lst = lst->next;
	}
	printf("%i: \033[0;31mNULL\033[0m\n", i);
	// write(1, ">:cc\n", 5);
	return (i);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_info	info;
	t_list	*stka;
	// t_list	*stkb = NULL;

	args.argc = argc;
	args.argv = argv;
	stka = NULL;
	// stkb = fill_list("1 22 333 4444 55555");
	read_args(args, &stka);
	info = fill_info(stka);
	if (stka)
	{
		print_list(stka, "a");
		// sort(info, &stka, &stkb);
		sort(info, &stka, 1);
		print_list(stka, "a");
		dlfree(&stka, NULL);
		// dlfree(&stkb, NULL);
	}
	return (0);
}
