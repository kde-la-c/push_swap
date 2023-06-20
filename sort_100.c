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

int	**make_matrix(t_info info)
{
	size_t	i;
	int		j;
	int		**chunks;

	i = 0;
	chunks = (int **)malloc(sizeof(int *) * 6);
	if (!chunks)
		return (NULL);
	while (i < 5)
	{
		j = (info.nbargs / 5) + (i < info.nbargs % 5) + 1;
		chunks[i] = (int *)malloc(sizeof(int) * j);
		ft_bzero(chunks[i], (info.nbargs / 5) + j + 1);
		i++;
	}
	chunks[5] = NULL;
	return (chunks);
}

void	sort_100(t_info info, t_list **stka)
{
	int	**chunks;

	chunks = make_matrix(info);
	stka = stka;
	ft_dfree((void **)chunks);
}
