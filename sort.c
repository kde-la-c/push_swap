/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:37:12 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/03 16:37:32 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * returns 1 if list is ordered
 */
int	check_order(t_list *stk)
{
	if (!stk)
		return (1);
	while (stk->next && *(int *)stk->content < *(int *)stk->next->content)
		stk = stk->next;
	if (stk->next)
		return (0);
	return (1);
}

void	sort(t_list **stka)
{
	t_info	info;

	info = get_info(*stka);
	if (info.nbargs <= 5)
		sort_5(info, &(*stka));
	else
		sort_more(info, &(*stka));
}
