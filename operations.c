/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:22:58 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/18 21:23:01 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stk)
{
	void	*pt;
	t_list	*tmp;

	if (*stk && (*stk)->next)
	{
		tmp = *stk;
		pt = tmp->content;
		tmp->content = tmp->next->content;
		tmp->next->content = pt;
	}
	else
		return ;
}

void	push(t_list **stksrc, t_list **stkdst)
{
	t_list	*tmp;

	tmp = *stksrc;
	*stksrc = (*stksrc)->next;
	tmp->next = NULL;
	ft_lstadd_front(&(*stkdst), tmp);
}

void	rotate(t_list **stk)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = *stk;
	while (tmp1 && tmp1->next && tmp1->next->next)
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = NULL;
	ft_lstadd_front(&(*stk), tmp2);
}

void	reverse(t_list **stk)
{
	t_list	*tmp;

	tmp = *stk;
	*stk = (*stk)->next;
	tmp->next = NULL;
	ft_lstadd_back(&(*stk), tmp);
}
