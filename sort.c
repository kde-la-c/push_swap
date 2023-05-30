/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:46:25 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/23 18:46:31 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_list *stk)
{
	while (stk->next && *(int *)stk->content < *(int *)stk->next->content)
		stk = stk->next;
	if (stk->next)
		return (0);
	return (1);
}

void	sort(t_info info, t_list **stka, t_list **stkb)
{
	int		i;
	int		j;
	int		st;
	int		nba;

	i = 9;
	j = 1;
	st = *(int *)(*stka)->content;
	nba = info.nbargs;
	while (*stka && j)
	{
		if (*(int *)(*stka)->content % 10 == i || !(*stka)->next)
		{
			push(&(*stka), &(*stkb));
			nba--;
		}
		else
			rotate(&(*stka));
		if (*stka && (*(int *)(*stka)->content == st || j == nba))
		{
			i--;
			j = 1;
		}
		else
			j++;
	}
	print_list(*stkb, "stkb");
	i = 9;
	j = 1;
	st = *(int *)(*stkb)->content;
	nba = info.nbargs;
	while (*stkb && j)
	{
		if (*(int *)(*stkb)->content % 100 / 10 == i || !(*stkb)->next)
		{
			push(&(*stkb), &(*stka));
			nba--;
		}
		else
			rotate(&(*stkb));
		if (*stkb && (*(int *)(*stkb)->content == st || j == nba))
		{
			i--;
			j = 1;
		}
		else
			j++;
	}
}
