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

/* int	get_maxunit(t_list *stk, int pos)
{
	int	ret;

	ret = -9;
	while (stk)
	{
		if (*(int *)stk->content % (pos * 10) / pos > ret)
			ret = *(int *)stk->content % (pos * 10) / pos;
		stk = stk->next;
	}
	printf("maxunit :%i\n", ret);
	return (ret);
} */

/* void	sort_pos(t_info info, t_list **stk1, t_list **stk2, int pos)
{
	int	i;
	int unit;
	int	size;

	i = 0;
	unit = get_maxunit(*stk1, pos);
	size = ft_lstsize(*stk1);
	while (i < size)
	{
		if ()
	}
}

//TODO new sort functions
void	sort(t_info info, t_list **stka, t_list **stkb)
{
	// int	temp;
	// int	unit;
	// int	i;

	// i = 0;
	// unit = 9;
	// temp = *(int *)(*stka)->content;
	sort_pos(info, &(*stka), &(*stkb), 1);
} */

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
		if ((*(int *)(*stka)->content % 10 == i || *(int *)(*stka)->content % 10 == -i) || !(*stka)->next)
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
	// i = 9;
	// j = 1;
	// st = *(int *)(*stkb)->content;
	// nba = info.nbargs;
	// while (*stkb && j)
	// {
	// 	if (*(int *)(*stkb)->content % 100 / 10 == i || !(*stkb)->next)
	// 	{
	// 		push(&(*stkb), &(*stka));
	// 		nba--;
	// 	}
	// 	else
	// 		rotate(&(*stkb));
	// 	if (*stkb && (*(int *)(*stkb)->content == st || j == nba))
	// 	{
	// 		i--;
	// 		j = 1;
	// 	}
	// 	else
	// 		j++;
	// }
} */
