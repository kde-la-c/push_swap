/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:45 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/10 15:10:51 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlfree(t_list **lst, char **split)
{
	if (split)
		ft_dfree((void **)split);
	if (lst && *lst)
		ft_lstclear(&(*lst), free);
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

int main()
{
	return 0;
}