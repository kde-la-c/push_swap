/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:57:03 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/14 13:57:20 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nbchunks(t_info info)
{
	if (info.nbargs <= 20)
		return (4);
	else if (info.nbargs <= 50)
		return (6);
	else if (info.nbargs <= 100)
		return (7);
	else if (info.nbargs <= 200)
		return (9);
	else if (info.nbargs <= 350)
		return (11);
	else if (info.nbargs <= 500)
		return (13);
	else if (info.nbargs <= 700)
		return (17);
	else
		return (20);
}

int	**make_matrix(t_info info)
{	
	t_count	c;
	int		**chunks;

	c.i = get_nbchunks(info);
	c.j = 0;
	c.l = 1;
	chunks = (int **)malloc(sizeof(int *) * (c.i + 1));
	if (!chunks)
		return (NULL);
	while (c.j < c.i)
	{
		c.k = info.nbargs / c.i + (c.j < info.nbargs % c.i) + 2;
		chunks[c.j] = (int *)malloc(sizeof(int) * (c.k + 1));
		if (!chunks[c.j])
			return (dlfree(NULL, (void **)chunks), NULL);
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
	pos = (int *)malloc(sizeof(int) * chunk[0] + 1);
	if (!pos)
		return (-1);
	if (!stk || !chunk)
		return (free(pos), -1);
	while (stk)
	{
		c.j = 1;
		while (chunk[c.j])
			if (*(int *)stk->content == chunk[c.j++])
				pos[c.k++] = c.i;
		pos[c.k] = -1;
		stk = stk->next;
		c.i++;
	}
	ret = pos[0];
	if (pos[0] != -1 && pos[0] > (*info).nbargs - pos[c.k - 1])
		ret = pos[c.k - 1];
	return (free(pos), ret);
}
