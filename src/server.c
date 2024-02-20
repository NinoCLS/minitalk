/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:38:34 by nino              #+#    #+#             */
/*   Updated: 2024/02/20 18:25:02 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_bitoa(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c = (*c << 1) | 0;
}

void	bit_handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	byte_index;

	(void)context;
	ft_bitoa(sig, &c);
	if (++byte_index == 8)
	{
		byte_index = 0;
		if (c == '\0')
		{
			ft_printf("\n");
			return ;
		}
		else
			ft_printf("%c", c);
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					pid;

	(void)av;
	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = bit_handler;
	sigemptyset(&act.sa_mask);
	if (ac != 1)
	{
		ft_printf("Error : wrong format\n");
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	ft_printf("Waiting for message ...\n");
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
