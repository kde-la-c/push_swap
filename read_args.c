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

void	dlfree(t_list **lst, char **split)
{
	if (split)
		ft_dfree((void **)split);
	if (lst && *lst)
		ft_lstclear(&(*lst), free);
}

int	isnbrep(t_list *stk)
{
	int	i;
	int	j;
	int *set;

	i = 0;
	set = (int *)malloc(sizeof(int) * ft_lstsize(stk));
	set[0] = *(int *)stk->content;
	while (stk)
	{
		j = 0;
		while (j < i)
			if (*(int *)stk->content == set[j++])
				return (free(set), 1);
		set[j] = *(int *)stk->content;
 		stk = stk->next;
		i++;
	}
	free(set);
	return (0);
}

t_list	*get_arg(char *arg, t_list *ret)
{
	int		i;
	int		j;
	void	*cont;
	char	**split;

	i = 0;
	split = ft_split(arg, ' ');
	if (!split)
		return (NULL);
	while (split[i])
	{
		j = -1;
		while (split[i] && split[i][++j])
			if (!(ft_isdigit(split[i][j])
				|| (!j && split[i][j] == '-' && split[i][j + 1])))
				return (dlfree(&ret, split), NULL);
		cont = malloc(sizeof(int));
		if (!cont)
			return (dlfree(&ret, split), NULL);
		*(int *)cont = ft_atoi(split[i++]);
		ft_lstadd_back(&ret, ft_lstnew(cont));
	}
	if (*split)
		return (dlfree(NULL, split), ret);
	return (dlfree(NULL, split), NULL);
}

int	read_args(t_args args, t_list **stka)
{
	int		i;
	t_list	*tmp;

	i = 1;
	tmp = NULL;
	if (args.argc == 1)
		return (printf("%s\n", args.argv[0]), 0);
	else if (args.argc > 1)
	{
		while (args.argv[i])
			ft_lstadd_back(&(*stka), get_arg(args.argv[i++], tmp));
		*stka = get_ordinals(*stka, fill_info(*stka));
		if (*stka && !isnbrep(*stka))
			return (1);
		else
			return (dlfree(&(*stka), NULL), printf("Error\n"), 0);
	}
	else
		return (printf("Error\n"), 0);
}
