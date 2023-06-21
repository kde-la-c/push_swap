/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:38:50 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/05 19:38:54 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_chunks(int **chunks)
{
	int	i;
	int	j;

	i = 0;
	while (chunks[i])
	{
		j = 0;
		while (chunks[i][j])
		{
			printf("[%i][%i]: %i\n", i, j, chunks[i][j]);
			j++;
		}
		i++;
	}
}

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

int	get_closest(t_list *stk, int *chunk, t_info *info)
{
	int		ret;
	t_count	c;
	int		*pos;

	c.i = 0;
	c.k = 0;
	*info = fill_info(stk);
	pos = (int *)malloc(sizeof(int) * chunk[0] + 1);
	while (stk)
	{
		c.j = 1;
		while (chunk[c.j])
			if (chunk[c.j] == -1)
				c.k++;
			else if (*(int *)stk->content == chunk[c.j++])
				pos[c.k++] = c.i;
		pos[c.k] = -1;
		stk = stk->next;
		c.i++;
	}
	if (pos[0] > (*info).nbargs - pos[c.k - 1])
		ret = pos[c.k - 1];
	else
		ret = pos[0];
	return (free(pos), ret);
}

//TODO do stka -> stkb algo by chunks
/* void	actual_sorting(t_list **stka, int **chunks, t_info *info)
{
	int		close;
	t_count	c;
	t_list	*stkb;
	t_list	*tmp;

	c.i = 0;
	stkb = NULL;
	while (chunks[c.i])
	{
		tmp = *stka;
		c.j = 1;
		c.k = get_closest(*stka, chunks[c.i], &(*info));
		while (c.k != *(int *)tmp->content && *stka)
		{
			
			c.j++;
		}
		c.i++;
	}
} */

void	sort_100(t_info info, t_list **stka)
{
	// int		i;
	int		close;
	int		**chunks;

	// i = 0;
	chunks = make_matrix(info);
	// actual_sorting(&(*stka), chunks);
	close = get_closest(*stka, chunks[2], &info);
	print_chunks(chunks);
	printf("closest :%i\n", close);
	(void)stka;
	ft_dfree((void **)chunks);
}
