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
	void	*pt;

	pt = (int *)malloc(sizeof(int));
	*(int *)pt = *((int *)(*stksrc)->content);
	ft_lstadd_front(&(*stkdst), ft_lstnew(pt));
	ft_lstdelone(*stksrc, free);
	*stksrc = (*stksrc)->next;
}

void	rotate(t_list **stk)
{
	int		i;
	t_list	*tmp1;
	t_list	*tmp2;

	i = ft_lstsize(*stk) - 1;
	tmp1 = *stk;
	tmp2 = ft_lstlast(*stk);
	while (i > 0)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
	ft_lstadd_back(&(*stk), tmp2);
	print_list(*stk);
}

void	reverse(t_list **stk)
{
	void	*tmp;

	tmp = (ft_lstlast(*stk)->content);
	ft_lstdelone(ft_lstlast(*stk), free);
	ft_lstadd_back(&(*stk), ft_lstnew(tmp));
}
