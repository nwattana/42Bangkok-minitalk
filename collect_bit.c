/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_bit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:40:55 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/19 15:48:22 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// 8 bit only
void	collect_bit(char aa)
{
	int	i;
	int	iter;

	i = 8;
	iter = 1 << 7;
	while (i > 0)
	{
		if (iter & aa)
			printf("1 ");
		else 
			printf("0 ");
		i--;
		iter = iter >> 1;
	}
	printf("\n");
}

int	main(void)
{
	collect_bit('A');
}
