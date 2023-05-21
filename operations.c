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

/****************************************\
*segfault from operations || doperations?*
\****************************************/

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
	ft_lstadd_front(&(*stkdst), ft_lstnew((*stksrc)->content));
	ft_lstdelone(*stksrc, free);
	*stksrc = (*stksrc)->next;
}

void	rotate(t_list **stk)
{
	void	*tmp;

	tmp = (*stk)->content;
	while (*stk && (*stk)->next)
	{
		(*stk)->content = (*stk)->next->content;
		*stk = (*stk)->next;
	}
	(*stk)->next = tmp;
}

void	reverse(t_list **stk)
{
	void	*tmp;

	tmp = (ft_lstlast(*stk)->content);
	ft_lstdelone(ft_lstlast(*stk), free);
	ft_lstadd_front(&(*stk), ft_lstnew(tmp));
}
