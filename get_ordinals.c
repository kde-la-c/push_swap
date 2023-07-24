/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ordinals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 22:46:01 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/07 22:46:05 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_order(unsigned int *ord, t_list *stka, t_info info)
{
	t_count			c;
	unsigned int	ordinal;
	t_list			*tmp;

	ordinal = 1;
	while (ordinal <= info.nbargs)
	{
		tmp = stka;
		c.i = 0;
		info = get_info(stka);
		while (tmp && *(int *)tmp->content != info.smaller)
		{
			tmp = tmp->next;
			c.i++;
		}
		*(int *)tmp->content = INT32_MAX;
		ord[c.i] = ordinal++;
	}
}

t_list	*get_ordinals(t_list *stka, t_info info)
{
	t_count			c;
	t_list			*tmp;
	unsigned int	*ord;

	c.i = 0;
	ord = (unsigned int *)malloc(sizeof(unsigned int) * info.nbargs);
	if (!ord)
		print_error();
	get_order(ord, stka, info);
	tmp = stka;
	while (tmp)
	{
		*(unsigned int *)tmp->content = ord[c.i++];
		tmp = tmp->next;
	}
	return (free(ord), stka);
}
