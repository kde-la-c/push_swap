/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 21:12:43 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/18 21:12:48 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlfree(t_list **lst, void **split)
{
	if (split)
		ft_dfree(split);
	if (lst && *lst)
		ft_lstclear(&(*lst), free);
}

int	isnbrep(t_list *stk)
{
	t_count	c;
	int		*set;

	c.i = 0;
	if (!stk)
		return (0);
	set = (int *)malloc(sizeof(int) * ft_lstsize(stk));
	if (!set)
		print_error();
	set[0] = *(int *)stk->content;
	while (stk)
	{
		c.j = 0;
		while (c.j < c.i)
			if (*(int *)stk->content == set[c.j++])
				return (free(set), 1);
		set[c.j] = *(int *)stk->content;
		stk = stk->next;
		c.i++;
	}
	return (free(set), 0);
}

int	check_arg(char *nb)
{
	t_count	c;
	int		max;
	int		min;

	max = 2147483647;
	min = -2147483648;
	c.i = 0;
	if (ft_strlen(nb) > (9 + (nb[0] == '-'))
		&& (ft_atol(nb) > max || ft_atol(nb) < min))
		return (0);
	while (nb && nb[c.i])
	{
		if (!(ft_isdigit(nb[c.i]) || (!c.i && nb[c.i] == '-' && nb[c.i + 1])))
			return (0);
		c.i++;
	}
	return (1);
}

// t_list	*get_arg(char *arg, t_list *ret)
t_list	*get_arg(char *arg)
{
	int		i;
	void	*cont;
	t_list	*node;
	t_list	*ret;
	char	**split;

	i = 0;
	ret = NULL;
	split = ft_split(arg, ' ');
	if (!split)
		print_error();
	while (split[i])
	{
		if (!check_arg(split[i]))
			print_error();
		cont = (void *)malloc(sizeof(int) * 1);
		if (!cont)
			print_error();
		*(int *)cont = ft_atoi(split[i++]);
		node = ft_lstnew(cont);
		if (!node)
			print_error();
		ft_lstadd_back(&ret, node);
	}
	return (dlfree(NULL, (void **)split), ret);
}

void	read_args(t_args args, t_list **stka)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = NULL;
	if (args.argc == 1)
		return ;
	else if (args.argc > 1)
	{
		while (args.argv[i])
		{
			tmp = get_arg(args.argv[i++]);
			if (!tmp)
				print_error();
			ft_lstadd_back(&(*stka), tmp);
		}
		if (isnbrep(*stka) == 1)
			print_error();
		*stka = get_ordinals(*stka, get_info(*stka));
	}
	else
		print_error();
}
