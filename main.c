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

int print_array(int *arr)
{
	int i = 0;

	while (arr[i])
		printf("%i\n", arr[i++]);
	return 0;
}

int main()
{
	int *arr;

	arr = (int[4]){1, 2, 3, 4};
	print_array(arr);
	return 0;
}
