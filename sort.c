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

void	sort(t_info info, t_list **stk)
{
	int		i;
	t_list	*stka;
	t_list	*stkb;
	info = info;

	print_list(*stk, "stk");
	i = 0;
	stka = *stk;
	while (stka)
	{
		if (*(int *)stka->content % 10 == i)
			push(&stka, &stkb);
		else
			rotate(&stka);
		stka = stka->next;
		i++;
	}
	print_list(*stk, "stk");
}
