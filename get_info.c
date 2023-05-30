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

void	get_extremes(t_info *info, t_list *stk)
{
	int	i;
	int	j;

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
	/* while (stk)
	{
		j = ft_strlen(ft_itoa(*(int *)stk->content)) - *(int *)stk->content < 1;
		if (j > i)
			i = j;
		stk = stk->next;
	} */
	//TODO encontrar la max len sin el '-'
	i = (*info).bigger < 0;
	(*info).maxlen = ft_strlen(ft_itoa((*info).bigger)) - i;
}

t_info	fill_info(t_list *stk)
{
	t_info	ret;

	get_extremes(&ret, stk);
	ret.nbargs = ft_lstsize(stk);
	ret.nbargstmp = ret.nbargs;
	return (ret);
}
