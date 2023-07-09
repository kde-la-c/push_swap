/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:44:59 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/03 16:45:16 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **stk)
{
	if (!check_order(*stk))
		operation(&(*stk), NULL, "ra");
}

void	sort_3(t_list **stk)
{
	t_info	info;

	info = fill_info(*stk);
	if (info.nbargs == 2)
	{
		sort_2(&(*stk));
		return ;
	}
	if (*(int *)(*stk)->content == info.bigger)
		operation(&(*stk), NULL, "rra");
	if (!check_order(*stk)
		&& *(int *)ft_lstlast(*stk)->content == info.bigger)
		operation(&(*stk), NULL, "sa");
	if (*(int *)(*stk)->next->content == info.bigger)
		operation(&(*stk), NULL, "ra");
	if (!check_order(*stk))
		operation(&(*stk), NULL, "sa");
}

void	sort_5(t_info info, t_list **stka)
{
	t_list	*stkb;

	stkb = NULL;
	while (info.nbargs > 3)
	{
		if (*(int *)(*stka)->content == info.smaller
			|| *(int *)(*stka)->content == info.bigger)
		{
			operation(&(*stka), &stkb, "pa");
			info.nbargs--;
		}
		else
			operation(&(*stka), NULL, "ra");
	}
	sort_3(&(*stka));
	while (stkb)
	{
		operation(&(*stka), &stkb, "pb");
		if (*(int *)(*stka)->content == info.bigger)
			operation(&(*stka), &stkb, "rra");
	}
}
