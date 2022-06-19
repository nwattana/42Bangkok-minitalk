/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_server.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:51:41 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/20 05:19:34 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int	pow2(int a)
{
	if (a == 0)
		return (1);
	if (a == 1)
		return (2);
	if (a == 2)
		return (4);
	if (a == 3)
		return (8);
	if (a == 4)
		return (16);
	if (a == 5)
		return (32);
	if (a == 6)
		return (64);
	if (a == 7)
		return (128);
	return (0);

}

void	received_bit(int signal)
{
	static int	value;
	static int	bit_n;
	if (signal == SIGUSR1)
	{
		if (bit_n == 0)
			value += 1;
		else{
			value += pow2(7 - bit_n);
		}
	}
	if (bit_n == 7)
	{
		write(1,&value,1);
		value = 0;
		bit_n = 0;
	}
	else
	{
		bit_n++;
	}
}

int	main(void)
{
	int pid;
	struct sigaction sa_usr1={0};
	struct sigaction sa_usr2={0};
	sigset_t	b1;

	sa_usr1.sa_handler = &received_bit;
	sa_usr2.sa_handler = &received_bit;

	sigemptyset(&b1);
	sigaddset(&b1,SIGUSR1);
	sigaddset(&b1,SIGUSR2);
	signal(SIGUSR1,&received_bit);
	signal(SIGUSR2,&received_bit);
	pid = getpid();
	printf("%d\n",pid);
	if (pid < 0)
		return (1);
	while (1)
	{
		pause();
	}
	return (0);
}
