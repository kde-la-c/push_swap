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

t_list	*get_ordinals(t_list *stka)
{
	t_list	*ret;
	t_list	*tmpret;
	t_list	*tmpstk;

	// ret = ft_lstdup(stka);
	ret = NULL;
	printf("-> %i\n", ft_lstsize(ret));
	tmpstk = stka;
	tmpret = ret;
	while (tmpstk)
	{
		tmpret = ft_lstnew("a");
		tmpstk = tmpstk->next;
		tmpret = tmpret->next;
	}
	return (dlfree(&stka, NULL), ret);
}
