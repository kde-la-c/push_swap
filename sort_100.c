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

//TODO Wip on the sorting, get_positions should be working fine by now, need to do the loops
/* int	*get_positions(t_list *stk, int *content)
{
	t_count	c;
	int		*pos;
	t_info	info;

	c.i = 0;
	c.k = 0;
	pos = (int *)malloc(sizeof(int) * content[0]);
	info = fill_info(stk);
	while (stk)
	{
		c.j = 1;
		while (content[c.j])
		{
			if (*(int *)stk->content == content[c.j])
				pos[c.k] = c.i;
		}
		stk = stk->next;
		c.i++;
	}
	return (pos);
}

void	actual_sorting(t_list **stka, int **chunks)
{
	int		i;
	t_list	*stkb;

	i = 0;
	stkb = NULL;
	while (chunks[i])
	{

	}
} */

void	sort_100(t_info info, t_list **stka)
{
	int		**chunks;

	chunks = make_matrix(info);
	// actual_sorting(&(*stka), chunks);
	(void)stka;
	ft_dfree((void **)chunks);
}
