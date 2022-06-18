/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 07:50:57 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/18 13:30:40 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libftprintf.h"
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char *argv[])
{
	int	ser_pid;

	if (argc != 2)
		return (0);
	printf("this file name : %s\n",argv[0]);
	printf("hello I'm client\n");
	ser_pid = ft_atoi(argv[1]);
	printf("ser_pid: %d\n",ser_pid);
	if (ser_pid > 0)
		kill(ser_pid,9);
}
