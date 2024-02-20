/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:04:20 by nino              #+#    #+#             */
/*   Updated: 2024/02/20 17:42:00 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

static int	g_received;

void	bit_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	(void)sig;
	g_received = 1;
}

// ascii to binary
int	atob(int pid, char c)
{
	int	i;
	int	byte_index;

	byte_index = 7;
	while (byte_index >= 0)
	{
		i = 0;
		if ((c >> byte_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_received == 0)
		{
			if (i == 50)
				return (0);
			i++;
			usleep(100);
		}
		g_received = 0;
		byte_index--;
	}
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction	act;
	int					pid;
	int					byte_index;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = bit_handler;
	sigemptyset(&act.sa_mask);
	if (ac != 3)
	{
		ft_printf("Error : wrong format\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	sigaction(SIGUSR2, &act, 0);
	byte_index = 0;
	while (av[2][byte_index])
	{
		atob(pid, av[2][byte_index]);
		byte_index++;
	}
	atob(pid, 0);
	return (0);
}
