/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:35:21 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/19 02:34:29 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	pid;

	pid = getpid();
	if (pid == -1)
		return (1);
	if(ft_printf("%d\n",pid) == -1)
		return (-1);
	while(1)
	{
		ft_printf("hello\n");
		sleep(20);
	}
	return (0);
}
