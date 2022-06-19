/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:00:59 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/20 06:07:11 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libftprintf.h"
#include <stdio.h>
#include <signal.h>
int	ft_send(int pid, char charac);
int	send_message(int pid, char *message);

int	check_pid(char *pid_s)
{
	while(*pid_s)
		if(!ft_isdigit(*pid_s++))
			return (0);
	return (1);
}

int	send_message(int pid, char *message)
{
	unsigned int	message_len;
	char	*buff2;

	message_len = ft_strlen(message);
	buff2 = message;
	while (*buff2)
	{
		ft_send(pid,*buff2);
		buff2++;
	}
	return (message_len);
}



int	ft_send(int pid, char charac)
{
	int	compare_bit;
	int	loop_count;

	loop_count = 8;
	compare_bit = 1 << 7;
	while (loop_count > 0)
	{
		if (compare_bit & charac)
		{
			// 1 do something
			kill(pid, SIGUSR1);
		}
		else
		{
			// 0 Do something
			kill(pid, SIGUSR2);
		}
		compare_bit = compare_bit >> 1;
		loop_count--;
		usleep(100);
	}
	return (1);
}

// ./client [pid] [message]
int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (1);
	//if(!check_pid(argv[1]))
	//	return (2);
	pid = ft_atoi(argv[1]);
	// what will happen if argv[2] = "" ??? 
	if(!send_message(pid,argv[2]))
		return (3);
}

