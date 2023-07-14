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

t_info	get_info(t_list *stk)
{
	t_info	ret;

	get_extremes(&ret, stk);
	ret.nbargs = ft_lstsize(stk);
	return (ret);
}
