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

void	sort_100(t_info info, t_list **stka)
{
	int	i;
	int	**chunks;

	i = 0;
	chunks = (int **)malloc(sizeof(int *) * 6);
	if (!chunks)
		return ;
	while (i < 5)
	{
		chunks[i++] = (int *)malloc(sizeof(int) * (info.nbargs / 5) + 1);
		if (!chunks[i])
			ft_dfree((void **)chunks);
		
	}
	chunks[5] = NULL;
	stka = stka;
	ft_dfree((void **)chunks);
}
