/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:10:45 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/05/10 15:10:51 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freee(char **arr, int i)
{
	while (i >= 0 && arr[i])
		free(arr[i--]);
	free(arr);
}

t_list	*fill_list(t_list *stka)
{
	char	**split;
	char	*str = "1 2 3 4 5";
	int		i = 0;

	split = ft_split(str, ' ');
	stka = ft_lstnew(split[i]);
	while (split[i++])
		ft_lstadd_back(&stka, ft_lstnew(split[i]));
	ft_freee(split, i - 1);
	return (stka);
}

int main()
{
	t_list	*stka = NULL;
	t_list	*tmp;

	stka = fill_list(stka);
	tmp = stka;
	while (stka && stka->content)
	{
		write(1, stka->content, 1);
		write(1, "\n", 1);
		stka = stka->next;
	}
	stka = tmp;
	printf("len :%u\n", ft_lstsize(stka));
	ft_lstclear(&stka, free);
	return 0;
}
