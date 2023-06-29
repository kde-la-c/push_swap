/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:38:50 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/05 19:38:54 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**make_matrix(t_info info)
{
	t_count	c;
	int		**chunks;

	c.i = 0;
	c.k = 1;
	chunks = (int **)malloc(sizeof(int *) * 6);
	if (!chunks)
		return (NULL);
	while (c.i < 5)
	{
		c.j = (info.nbargs / 5) + (c.i < info.nbargs % 5) + 2;
		chunks[c.i] = (int *)malloc(sizeof(int) * c.j);
		chunks[c.i][0] = c.j - 2;
		chunks[c.i][c.j - 1] = 0;
		c.j = 1;
		while (chunks[c.i][c.j])
			chunks[c.i][c.j++] = c.k++;
		c.i++;
	}
	chunks[5] = NULL;
	return (chunks);
}

/**
 * returns list index of closest chunk int to reach
*/
int	get_closest(t_list *stk, int *chunk, t_info *info)
{
	int		ret;
	t_count	c;
	int		*pos;

	c.i = 0;
	c.k = 0;
	if (!stk || !chunk || !(pos = (int *)malloc(sizeof(int) * chunk[0] + 1)))
		return (-1);
	*info = fill_info(stk);
	while (stk)
	{
		c.j = 1;
		while (chunk[c.j])
			if (chunk[c.j] == -1)
				c.j++;
			else if (*(int *)stk->content == chunk[c.j++])
				pos[c.k++] = c.i;
		pos[c.k] = -1;
		stk = stk->next;
		c.i++;
	}
	ret = pos[0];
	if (pos[0] > (*info).nbargs - pos[c.k - 1])
		ret = pos[c.k - 1];
	return (free(pos), ret);
}

/* void	actual_sorting2(t_list **stka, t_list **stkb, int **chunks)
{
	t_count	c;

	c.i = 4;
	c.j = 0;
	while (c.i >= 0)
	{
		c.j = chunks[c.i][0];
		while (c.j)
		{
			c.k = 0;
			while (*(int *)(*stkb)->content != chunks[c.i][c.j])
			{
				operation(&(*stka), &(*stkb), "rrb");
				c.k++;
			}
			operation(&(*stka), &(*stkb), "pb");
			while (!c.k--)
				operation(&(*stka), &(*stkb), "rb");
			c.j--;
		}
		c.i--;
	}
} */

void	actual_sorting2(t_list **stka, t_list **stkb)
{
	t_count	c;
	t_info	a_info;

	operation(&(*stka), &(*stkb), "pb");
	while (*stkb)
	{
		a_info = fill_info(*stka);
		if (*(int *)(*stkb)->content < a_info.smaller)
			operation(&(*stka), &(*stkb), "pb");
		else if (*(int *)(*stkb)->content > a_info.bigger)
		{
			operation(&(*stka), &(*stkb), "pb");
			operation(&(*stka), &(*stkb), "rra");
		}
		else
		{
			c.i = 0;
			while (*(int *)(*stkb)->content > *(int *)(*stka)->content)
				c.i += operation(&(*stka), &(*stkb), "rra");
			operation(&(*stka), &(*stkb), "pb");
			while (c.i-- > 0)
				operation(&(*stka), &(*stkb), "ra");
		}
	}
}

void	actual_sorting(t_list **stka, int **chunks, t_info *info)
{
	t_count	c;
	t_list	*stkb;
	t_list	*tmp;

	c.i = 0;
	stkb = NULL;
	while (chunks[c.i])
	{
		c.j = get_closest(*stka, chunks[c.i], &(*info));
		if (c.j != -1)
		{
			tmp = ft_lstgetnode(*stka, c.j);
			while (*(int *)tmp->content != *(int *)(*stka)->content)
				if (c.j <= (*info).nbargs / 2)
					operation(&(*stka), NULL, "rra");
				else
					operation(&(*stka), NULL, "ra");
			operation(&(*stka), &stkb, "pa");
		}
		else
			c.i++;
	}
	actual_sorting2(&(*stka), &stkb);
	ft_lstclear(&stkb, free);
}

void	sort_100(t_info info, t_list **stka)
{
	int		**chunks;

	chunks = make_matrix(info);
	// print_chunks(chunks);
	actual_sorting(&(*stka), chunks, &info);
	// print_chunks(chunks);
	ft_dfree((void **)chunks);
}
