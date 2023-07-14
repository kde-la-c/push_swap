/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:38:50 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/05 19:38:54 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ordered(t_list **stka, t_list **stkb)
{
	t_count	c;
	t_info	a_info;

	c.i = 0;
	operation(&(*stka), &(*stkb), "pa");
	while (*stkb)
	{
		a_info = get_info(*stka);
		if (*(int *)(*stkb)->content < a_info.smaller)
			operation(&(*stka), &(*stkb), "pa");
		else if (*(int *)(*stkb)->content > a_info.bigger)
		{
			operation(&(*stka), &(*stkb), "pa");
			operation(&(*stka), &(*stkb), "ra");
		}
		else
		{
			while (*(int *)(*stkb)->content > *(int *)(*stka)->content)
				c.i += operation(&(*stka), &(*stkb), "ra");
			operation(&(*stka), &(*stkb), "pa");
			while (c.i > 0)
				c.i -= operation(&(*stka), &(*stkb), "rra");
		}
	}
}

void	push_chunks(t_list **stka, int **chunks, t_info *info)
{
	t_count	c;
	t_list	*stkb;
	t_list	*tmp;

	c.i = 0;
	stkb = NULL;
	while (chunks[c.i])
	{
		*info = get_info(*stka);
		c.j = get_closest(*stka, chunks[c.i], &(*info));
		if (c.j != -1)
		{
			tmp = ft_lstgetnode(*stka, c.j);
			while (*(int *)tmp->content != *(int *)(*stka)->content)
				if (c.j <= (*info).nbargs / 2)
					operation(&(*stka), &stkb, "ra");
			else
				operation(&(*stka), &stkb, "rra");
			operation(&(*stka), &stkb, "pb");
		}
		else
			c.i++;
	}
	push_ordered(&(*stka), &stkb);
	ft_lstclear(&stkb, free);
}

void	sort_more(t_info info, t_list **stka)
{
	int		**chunks;

	chunks = make_matrix(info);
	push_chunks(&(*stka), chunks, &info);
	ft_dfree((void **)chunks);
}
