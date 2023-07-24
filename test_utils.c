/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:41:41 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/27 16:41:49 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_list(t_list *lst, char *str)
{
	int	i;

	ft_printf("%s :\n", str);
	if (!lst)
		return (-1);
	i = 0;
	while (lst && lst->content)
	{
		ft_printf("%i: \033[0;32m%d\033[0m\n", i++, *((int *)lst->content));
		lst = lst->next;
	}
	ft_printf("%i: \033[0;31mNULL\033[0m\n", i);
	return (i);
}

void	print_chunks(int **chunks)
{
	int	i;
	int	j;

	i = 0;
	while (chunks[i])
	{
		j = 0;
		while (chunks[i][j])
		{
			ft_printf("[%i][%i]: %i\n", i, j, chunks[i][j]);
			j++;
		}
		i++;
	}
	ft_printf("[%i]: \033[0;31mNULL\033[0m\n", i);
}

t_list	*fill_list(char *inp)
{
	int		i;
	t_list	*ret;
	void	*cont;
	char	**split;

	i = 0;
	ret = NULL;
	split = ft_split(inp, ' ');
	if (!split)
		return (NULL);
	while (split[i])
	{
		cont = malloc(sizeof(int));
		if (!cont)
			return (dlfree(&ret, (void **)split), NULL);
		*(int *)cont = ft_atoi(split[i++]);
		ft_lstadd_back(&ret, ft_lstnew(cont));
	}
	if (*split)
		return (dlfree(NULL, (void **)split), ret);
	return (dlfree(NULL, (void **)split), NULL);
}
