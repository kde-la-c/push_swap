/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:53:57 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/31 00:54:00 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* t_list	*get_smaller(t_list *stka)
{
	int		i;
	t_list	*tmp;
	t_list	*node;

	i = 2147483647;
	tmp = stka;
	while (stka)
	{
		if (stka->next && i < *(int *)stka->next->content)
		{
			i = *(int *)stka->next->content;
			node = stka;
		}
		stka = stka->next;
	}
	
	return (tmp);
} */

void	get_extremes(t_info *info, t_list *stk)
{
	int		i;
	int		j;
	char	*str;

	i = -2147483648;
	j = 2147483647;
	while (stk)
	{
		if (i < *(int *)stk->content)
			i = *(int *)stk->content;
		if (j > *(int *)stk->content)
			j = *(int *)stk->content;
		stk = stk->next;
	}
	(*info).bigger = i;
	(*info).smaller = j;
	if (j < 0 && (j * -1) > i)
		str = ft_itoa(j * -1);
	else
		str = ft_itoa(i);
	(*info).maxlen = ft_strlen(str);
	free(str);
}

t_info	fill_info(t_list *stk)
{
	t_info	ret;

	get_extremes(&ret, stk);
	ret.nbargs = ft_lstsize(stk);
	ret.nbargstmp = ret.nbargs;
	return (ret);
}
