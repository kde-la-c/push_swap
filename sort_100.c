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

// int	**make_matrix(t_info info, int nbchunks)
int	**make_matrix(t_info info)
{	
	t_count	c;
	int		**chunks;

	c.i = 5;
	c.j = 0;
	c.l = 1;
	if (!(chunks = (int **)malloc(sizeof(int *) * (c.i + 1))))
		return (NULL);
	while (c.j < c.i)
	{
		c.k = info.nbargs / c.i + (c.j < info.nbargs % c.i) + 2;
		if (!(chunks[c.j] = (int *)malloc(sizeof(int) * (c.k + 1))))
			return (dlfree(NULL, (char **)chunks), NULL);
		chunks[c.j][0] = c.k - 1;
		chunks[c.j][c.k] = 0;
		c.k = 1;
		while (c.k <= chunks[c.j][0])
			chunks[c.j][c.k++] = c.l++;
		c.j++;
	}
	chunks[c.j] = NULL;
	return (chunks);
}

/* int	**make_matrix(t_info info)
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
} */

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
		//TODO fix this infinite loop
		while (chunk[c.j])
			if (!(*(int *)stk->content == chunk[c.j]))
				c.j++;
			else if (*(int *)stk->content == chunk[c.j++])
			{
				pos[c.k++] = c.i;
			}
		pos[c.k] = -1;
		stk = stk->next;
		c.i++;
	}
	ret = pos[0];
	if (pos[0] != -1 && pos[0] > (*info).nbargs - pos[c.k - 1])
		ret = pos[c.k - 1];
	// for (int i = 0; pos[i - 1] > -1; i++)
	// {
	// 	printf("pos[%i]:%i, c.k:%li\n", i, pos[i], c.k);
	// }
	
	return (free(pos), ret);
}

void	push_ordered(t_list **stka, t_list **stkb)
{
	t_count	c;
	t_info	a_info;

	operation(&(*stka), &(*stkb), "pb");
	// while ((*stkb)->next)
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
			while (*(int *)(*stkb)->content > *(int *)(*stka)->content)
				c.i += operation(&(*stka), &(*stkb), "rra");
			operation(&(*stka), &(*stkb), "pb");
			while (c.i > 0)
			{
				c.i -= operation(&(*stka), &(*stkb), "ra");
				sleep(1);
			}
		}
	}
}

int	isnb(int *arr, int nb)
{
	while (*arr)
		if (nb == *(arr++))
			return (1);
	return (0);
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
		c.j = get_closest(*stka, chunks[c.i], &(*info));
		// printf("closest:%li\n", c.j);
		if (c.j != -1)
		{
			tmp = ft_lstgetnode(*stka, c.j);
			while (*(int *)tmp->content != *(int *)(*stka)->content)
				if (c.j <= (*info).nbargs / 2)
					operation(&(*stka), NULL, "rra");
				else
				{
					operation(&(*stka), NULL, "ra");
					sleep(1);
				}
			operation(&(*stka), &stkb, "pa");
		}
		else
		{
			// printf("++\n");
			c.i++;
		}
	}
	push_ordered(&(*stka), &stkb);
	ft_lstclear(&stkb, free);
}

// void	sort_100(t_info info, t_list **stka, int nbchunks)
void	sort_100(t_info info, t_list **stka)
{
	int		**chunks;

	// chunks = make_matrix(info, nbchunks);
	chunks = make_matrix(info);
	// print_chunks(chunks);
	// printf("rand chunk bit :%i\n", chunks[1][0]);
	push_chunks(&(*stka), chunks, &info);
	// print_chunks(chunks);
	ft_dfree((void **)chunks);
	// printf("nbch :%i\n", nbchunks);
}
