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

int	operation_1(t_list **stka, t_list **stkb, char *operation)
{
	int	success;

	if (!ft_strncmp(operation, "sa", 3))
		success = swap(&(*stka));
	else if (!ft_strncmp(operation, "pa", 3) && stka)
		success = push(&(*stka), &(*stkb));
	else if (!ft_strncmp(operation, "ra", 3))
		success = rotate(&(*stka));
	else if (!ft_strncmp(operation, "rra", 3))
		success = reverse(&(*stka));
	else if (!ft_strncmp(operation, "sb", 3))
		success = swap(&(*stkb));
	else if (!ft_strncmp(operation, "pb", 3) && stkb)
		success = push(&(*stkb), &(*stka));
	else if (!ft_strncmp(operation, "rb", 3))
		success = rotate(&(*stkb));
	else if (!ft_strncmp(operation, "rrb", 3))
		success = reverse(&(*stkb));
	else
		success = 0;
	if (success)
		return (1);
	return (0);
}

int	operation_2(t_list **stka, t_list **stkb, char *operation)
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
		return (1);
	return (0);
}

void	add_op(int ret, char *operation, t_list **oplst)
{
	t_list	*node;

	if (ret)
	{
		node = ft_lstnew((void *)operation);
		if (!node)
			print_error();
		ft_lstadd_back(&(*oplst), node);
	}
}

int	operation(t_list **stka, t_list **stkb, char *operation)
{
	int				ret;
	static t_list	*oplst;

	if (ft_strchr(operation, 'a') || ft_strchr(operation, 'b'))
	{
		ret = operation_1(&(*stka), &(*stkb), operation);
		add_op(ret, operation, &oplst);
	}
	else
	{
		ret = operation_2(&(*stka), &(*stkb), operation);
		add_op(ret, operation, &oplst);
	}
	if (check_order(*stka) && !ft_lstsize(*stkb))
	{
		output(oplst);
		ft_lstclear(&oplst, NULL);
	}
	return (ret);
}
