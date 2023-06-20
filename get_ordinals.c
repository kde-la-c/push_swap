/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ordinals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:46:01 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/07 22:46:05 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*get_node(t_list *lst, int node)
{
	if (ft_lstsize(lst) < node)
		return (NULL);
	while (lst && node >= 0)
	{
		lst = lst->next;
		node--;
	}
	return (lst);
}

void	get_order(int *ord, t_list *stka, t_info info)
{
	int		i;
	long	ordinal;
	t_list	*tmp;

	ordinal = 1;
	while (ordinal <= info.nbargs)
	{
		tmp = stka;
		i = 0;
		info = fill_info(stka);
		while (tmp && *(int *)tmp->content != info.smaller)
		{
			tmp = tmp->next;
			i++;
		}
		*(int *)tmp->content = INT32_MAX;
		ord[i] = ordinal++;
	}
}

t_list	*get_ordinals(t_list *stka, t_info info)
{
	int		i;
	t_list	*tmp;
	int		*ord;

	i = 0;
	ord = (int *)malloc(sizeof(int) * info.nbargs);
	get_order(ord, stka, info);
	tmp = stka;
	while (tmp)
	{
		*(int *)tmp->content = ord[i++];
		tmp = tmp->next;
	}
	return (free(ord), stka);
}
