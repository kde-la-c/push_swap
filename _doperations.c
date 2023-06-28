/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doperations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:09:55 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/21 23:10:20 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dswap(t_list **stka, t_list **stkb)
{
	swap(&(*stka));
	swap(&(*stkb));
}

void	drotate(t_list **stka, t_list **stkb)
{
	rotate(&(*stka));
	rotate(&(*stkb));
}

void	dreverse(t_list **stka, t_list **stkb)
{
	reverse(&(*stka));
	reverse(&(*stkb));
}
