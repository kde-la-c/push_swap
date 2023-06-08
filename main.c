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

int	print_list(t_list *lst, char *str)
{
	int	i;

	printf("%s :\n", str);
	if (!lst)
		return (-1);
	i = 0;
	while (lst && lst->content)
	{
		// sleep(1);
		printf("%i: \033[0;32m%d\033[0m\n", i++, *((int *)lst->content));
		lst = lst->next;
	}
	printf("%i: \033[0;31mNULL\033[0m\n", i);
	// write(1, ">:cc\n", 5);
	return (i);
}

int main()
{
	t_list	*lst;
	void	*ptr;

	ptr = malloc(sizeof(int));
	*(int *)ptr = 15;
	lst = ft_lstnew(NULL);
	lst->content = ptr;
	print_list(lst, "AAA");
	free(ptr);
	free(lst);
	return 0;
}
