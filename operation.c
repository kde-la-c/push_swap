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

void	output(t_list *operations)
{
	int		i;
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	i = 0;
	tmp = operations;
	while (tmp && tmp->next)
	{
		if (ft_strncmp((char *)tmp->content, (char *)tmp->next->content, 3) % 17)
		{
			tmp2 = ft_lstgetnode(operations, i - 2);
			tmp3 = ft_lstgetnode(operations, i + 1);
			ft_lstdelone(ft_lstgetnode(operations, i - 1), NULL);
			ft_lstdelone(tmp, NULL);
			tmp2->next = tmp3;
		}
		// printf("cmp[%i] :%i (%s - %s)\n", i, ft_strncmp((char *)tmp->content, (char *)tmp->next->content, 3), (char *)tmp->content, (char *)tmp->next->content);
		tmp = tmp->next;
		i++;
	}
	print_ops(operations);
}

int	operation_a(t_list **stka, t_list **stkb, char *operation)
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
		return (/* ft_printf("%s\n", operation), */ 1);
	return (0);
}

int	operation_b(t_list **stka, t_list **stkb, char *operation)
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
		return (/* ft_printf("%s\n", operation), */ 1);
	return (0);
}

int	operation_ab(t_list **stka, t_list **stkb, char *operation)
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
		return (/* ft_printf("%s\n", operation), */ 1);
	return (0);
}

int	operation(t_list **stka, t_list **stkb, char *operation)
{
	int	ret;
	static t_list	*operations;

	if (!operations)
		operations = ft_lstnew(ft_strdup("depart"));
	if (ft_strchr(operation, 'a'))
	{
		ret = operation_a(&(*stka), &(*stkb), operation);
		if (ret)
			ft_lstadd_back(&operations, ft_lstnew((void *)operation));
	}
	else if (ft_strchr(operation, 'b'))
	{
		ret =operation_b(&(*stka), &(*stkb), operation);
		if (ret)
			ft_lstadd_back(&operations, ft_lstnew((void *)operation));
	}
	else
	{
		ret = operation_ab(&(*stka), &(*stkb), operation);
		if (ret)
			ft_lstadd_back(&operations, ft_lstnew((void *)operation));
	}
	// ft_printf("debug %i\n", ft_lstsize(*stkb));
	if (check_order(*stka) && !ft_lstsize(*stkb))
	{
		// ft_printf("DONE ! B)\n");
		output(operations);
	}
	return (ret);
}

/* int	operation(t_list **stka, t_list **stkb, char *operation)
{
	if (ft_strchr(operation, 'a'))
		return (operation_a(&(*stka), &(*stkb), operation));
	else if (ft_strchr(operation, 'b'))
		return (operation_b(&(*stka), &(*stkb), operation));
	else
		return (operation_ab(&(*stka), &(*stkb), operation));
} */
