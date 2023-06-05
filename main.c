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
#include "math.h"

int	ft_sqrt(int nb)
{
	int	sub;
	int	ret;

	sub = 1;
	ret = 0;
	if (nb < 0)
		return (0);
	else if (nb >= 0)
	{
		ret = ft_sqrt(ret - (sub += 2));
		printf("%i\n", nb);
		ret++;
	}
	return (ret);
}

int main()
{
	int i = sqrt(13) / 1;
	printf("squirt :%i\n", i);
	return 0;
}
