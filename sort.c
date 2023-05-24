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
	int		st;
	t_list	*stk2 = NULL;
	info = info;
	r = r;

	i = 9;
	j = 1;
	st = *(int *)(*stk1)->content;
	while ((*stk1)->content && j)
	{
		if (*(int *)(*stk1)->content % 10 == i || !(*stk1)->next)
			push(&(*stk1), &stk2);
		else
			rotate(&(*stk1));
		if (*stk1 && (*(int *)(*stk1)->content == st || j == ft_lstsize(*stk1)))
		{
			i--;
			j = 1;
		}
		else
			j++;
	write(1, "CACA:(\n", 7);
	}
	// printf("%i\n", );
	while (stk2)
	{
		reverse(&stk2);
		push(&stk2, &(*stk1));
	}
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
