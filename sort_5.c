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

void	sort_2(t_list **stk, t_list **stkb)
{
	if (!check_order(*stk))
		operation(&(*stk), &(*stkb), "rra");
}

void	sort_3(t_list **stk, t_list **stkb)
{
	t_info	info;

	info = get_info(*stk);
	if (info.nbargs == 2)
	{
		sort_2(&(*stk), &(*stkb));
		return ;
	}
	if (*(int *)(*stk)->content == info.bigger)
		operation(&(*stk), &(*stkb), "ra");
	if (!check_order(*stk)
		&& *(int *)ft_lstlast(*stk)->content == info.bigger)
		operation(&(*stk), &(*stkb), "sa");
	if (*(int *)(*stk)->next->content == info.bigger)
		operation(&(*stk), &(*stkb), "rra");
	if (!check_order(*stk))
		operation(&(*stk), &(*stkb), "sa");
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
			operation(&(*stka), &stkb, "pb");
			info.nbargs--;
		}
		else
			operation(&(*stka), &stkb, "rra");
	}
	sort_3(&(*stka), &stkb);
	while (stkb)
	{
		operation(&(*stka), &stkb, "pa");
		if (*(int *)(*stka)->content == info.bigger)
			operation(&(*stka), &stkb, "ra");
	}
}
