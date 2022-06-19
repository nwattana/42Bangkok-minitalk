/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_communicate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:35:56 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/20 02:38:17 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

void	handler_sigusr1(int sig){
	printf("\n(HINT)Remember that multiplication is repetitive addition\n");
}

int	main(int argc, char *argv[])
{
	if (argc > 0)
	{
		printf("Process name = \e[1;32m%s\e[0m\n", argv[0]);
	}
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0){
		/// child Process
		printf("pid == 0");
		sleep(5);
		kill(getppid(),SIGUSR1);
	}else{
		/*struct sigaction
		 *{
		 * 	union __sigaction_u 	__sigaction_u;
		 * 	sigset_t 		sa_mask;
		 * 	int			sa_flags;
		 *};
		 * 
		 *union __sigaction_u
		 *{
		 *	void	(*__sig_handler)(int);
		 *	void	(*__sig_action)(int, siginfo_t *, void *);
		 *};
		 *
		 * */
		struct sigaction sa = {0};
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handler_sigusr1;
		sigaction(SIGUSR1,&sa, NULL);

		int x;
		printf("What is the result of 3 x 5?\n");
		scanf("%d",&x);
		{
			if (x==15)
				printf("\e[1;32mRight!\e[0m\n");
			else
				printf("\e[1;30mWrong!\e[0m\n");
		}
	}
	wait(NULL);
}
