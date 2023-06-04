/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_6.c                                           :+:      :+:    :+:   */
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
		rotate(&(*stk));
}

void	sort_3(t_list **stk)
{
	t_info	info;

	info = fill_info(*stk);
	if (*(int *)(*stk)->content == info.bigger)
		reverse(&(*stk));
	if (!check_order(*stk) &&
		*(int *)ft_lstlast(*stk)->content == info.bigger)
		swap(&(*stk));
	if (*(int *)(*stk)->next->content == info.bigger)
		rotate(&(*stk));
	if (!check_order(*stk))
		swap(&(*stk));
}

void	sort_6(t_info info, t_list **stka)
{
	t_list	*stkb;

	stkb = NULL;
	while (info.nbargs > 3)
	{
		push(&(*stka), &stkb);
		info.nbargs--;
	}
	sort_3(&(*stka));
	if (ft_lstsize(stkb) == 2)
		sort_2(&stkb);
	else if (ft_lstsize(stkb) == 3)
		sort_3(&stkb);
	while (stkb)
	{
		if (*(int *)stkb->content < *(int *)(*stka)->content
			|| (*(int *)stkb->content > *(int *)(*stka)->content
			&& *(int *)ft_lstlast(*stka)->content == info.bigger))
		{
			push(&stkb, &(*stka));
			info = fill_info(*stka);
		}
		else
		{
			sleep(1);
			reverse(&(*stka));
		}
	}
	while (*(int *)(*stka)->content != info.smaller)
		rotate(&(*stka));
}