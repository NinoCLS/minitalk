/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:39:10 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/09 17:45:20 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	confirm_msg(int signal)
{
	if (signal == SIGUSR2)
		ft_printf("Message received !\n");
}

void	ft_ascii_to_bit(int pid, char character)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((character >> i) & 1) //decale les bits de char de i vers la droite 
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			ft_ascii_to_bit(pid, av[2][i]);
			i++;
		}
		signal(SIGUSR2, confirm_msg);
	}
	else
	{
		ft_printf("Wrong number of argument");
		return (0);
	}
	return (0);
}