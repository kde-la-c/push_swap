/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:46:25 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/23 18:46:31 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_info info, t_list **stk)
{
	
}

void	sort(t_info info, t_list **stka)
{
	if (info.nbargs <= 3)
		sort_3(info, &(*stka));
}
