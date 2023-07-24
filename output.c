/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:50:03 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/07/14 13:50:28 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	print_ops(t_list *lst)
{
	if (!lst)
		return ;
	while (lst && lst->content)
	{
		ft_printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}

void	output(t_list *oplst)
{
	t_count	c;
	t_list	*tmp;
	t_list	*node;

	c.i = 0;
	tmp = oplst;
	while (tmp && tmp->next)
	{
		c.j = ft_strncmp((char *)tmp->content, (char *)tmp->next->content, 3);
		if (c.j == 1 || c.j == 17)
		{
			node = ft_lstgetnode(oplst, c.i - 1);
			ft_lstdelnext(&node, NULL);
			node = ft_lstgetnode(oplst, c.i - 1);
			ft_lstdelnext(&node, NULL);
			tmp = oplst;
			c.i = 0;
		}
		else
		{
			tmp = tmp->next;
			c.i++;
		}
	}
	print_ops(oplst);
}
