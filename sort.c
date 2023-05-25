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

// void	sort(t_info info, t_list **stka, t_list **stkb)
void	sort(t_info info, t_list **stk1, int r)
{
	int		i;
	int		j;
	t_list	*stk2;

	info = info;

	i = 9;
	j = 1;
	while (*stk1 && j)
	{
		if (*(int *)(*stk1)->content % (r * 10) / r == i || !(*stk1)->next)
		{
			push(&(*stk1), &stk2);
			info.nbargstmp--;
		}
		else
			rotate(&(*stk1));
		if (j <= info.nbargstmp)
		{
			i--;
		}
		j++;
	}
	print_list(stk2, "stk2");
}

/* void	sort(t_info info, t_list **stka, t_list **stkb)
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
	while (*stkb)
	{
		rotate(&(*stkb));
		push(&(*stkb), &(*stka));
	}
} */
