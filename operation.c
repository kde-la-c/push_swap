/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:46:53 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/06/28 11:47:17 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_a(t_list **stka, t_list **stkb, char *operation)
{
	int	success;

	if (!ft_strncmp(operation, "sa", 3))
		success = swap(&(*stka));
	else if (!ft_strncmp(operation, "pa", 3) && stkb)
		success = push(&(*stka), &(*stkb));
	else if (!ft_strncmp(operation, "ra", 3))
		success = rotate(&(*stka));
	else if (!ft_strncmp(operation, "rra", 3))
		success = reverse(&(*stka));
	else
		success = 0;
	if (success)
		printf("%s\n", operation);
}

void	operation_b(t_list **stka, t_list **stkb, char *operation)
{
	int	success;

	if (!ft_strncmp(operation, "sb", 3))
		success = swap(&(*stkb));
	else if (!ft_strncmp(operation, "pb", 3) && stka)
		success = push(&(*stkb), &(*stka));
	else if (!ft_strncmp(operation, "rb", 3))
		success = rotate(&(*stkb));
	else if (!ft_strncmp(operation, "rrb", 3))
		success = reverse(&(*stkb));
	else
		success = 0;
	if (success)
		printf("%s\n", operation);
}

void	operation_ab(t_list **stka, t_list **stkb, char *operation)
{
	int	success;

	if (!ft_strncmp(operation, "ss", 3))
	{
		success = swap(&(*stka));
		success += swap(&(*stkb));
	}
	else if (!ft_strncmp(operation, "rr", 3))
	{
		success = rotate(&(*stka));
		success += rotate(&(*stkb));
	}
	else if (!ft_strncmp(operation, "rrr", 3))
	{
		success = reverse(&(*stka));
		success += reverse(&(*stkb));
	}
	else
		success = 0;
	if (success == 2)
		printf("%s\n", operation);
}

void	operation(t_list **stka, t_list **stkb, char *operation)
{
	if (ft_strchr(operation, 'a'))
	{
		operation_a(&(*stka), &(*stkb), operation);
	}
	else if (ft_strchr(operation, 'b'))
		operation_b(&(*stka), &(*stkb), operation);
	else
		operation_ab(&(*stka), &(*stkb), operation);
}
