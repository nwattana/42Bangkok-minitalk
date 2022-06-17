/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:35:21 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/17 23:02:18 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	id;
	int	id2;
	int	i;

	id = fork();
	id2 = fork();
	i = getpid();
	printf("-------\n");
	printf("pid:  %d\n",i);
	printf("id: %d\n",id);
	printf("id: %p\n",&id);
	//printf("id2: %d\n",id2);
	//printf("id2: %p\n",&id2);
}
