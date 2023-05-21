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

t_list	*fill_list(char *inp)
{
	int		i;
	t_list	*ret;
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

int	print_list(t_list *lst)
{
	int	i;

	if (!lst)
		return (-1);
	i = 0;
	while (lst)
	{
		printf("%i: \033[0;32m%d\033[0m\n", i++, *((int *)lst->content));
		lst = lst->next;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	t_args	args;
	t_list	*stka;
	// t_list	*tmp;
	t_list	*stkb = NULL;

	args.argc = argc;
	args.argv = argv;
	stka = NULL;
	// stkb = fill_list("165 76");
	i = read_args(args, &stka);
	printf("ret :%i\n", i);
	printf("len :%i\n", ft_lstsize(stka));
	if (stka)
	{
		// tmp = stka;
		// print_list(tmp);
		// stka = tmp;
		// ft_lstclear(&tmp, free);
		print_list(stka);
		print_list(stkb);
		write(1, "hola\n", 5);
		dswap(&stka, &stkb);
		printf("-----\n");
		print_list(stka);
		print_list(stkb);
		dlfree(&stka, NULL);
	}
	return (0);
}
