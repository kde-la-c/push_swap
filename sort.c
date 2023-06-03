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
 * returns 1 is list is ordered
 */
int	check_order(t_list *stk)
{
	while (stk->next && *(int *)stk->content < *(int *)stk->next->content)
		stk = stk->next;
	if (stk->next)
		return (0);
	return (1);
}

void	sort(t_info info, t_list **stka)
{
	if (check_order(*stka))
		return ;
	else if (info.nbargs <= 6)
		sort_6(info, &(*stka));
	// else if (info.nbargs == 2)
	// 	rotate(&(*stka));
	// else if (info.nbargs == 3)
	// 	sort_3(info, &(*stka));
}