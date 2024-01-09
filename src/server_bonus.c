/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:39:14 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/09 17:39:38 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_bit_to_ascii(int signal)
{
	static int character; // variable pour stocker le char en cours de construction 
	static int bit_count; // compteur de bits 

	character <<= 1;

	// ajouter 1 ou 0 au bit de poids le plus faible de character selon le signal recu 
	if (signal == SIGUSR1)
		character |= 1; // ajoute 1 si le signal R1 est recu 
	bit_count++;
	// pas besoin de l'ajouter pr le R2 car le decalage vers la gacuhe remplit deja avec des 0

	// check if 8 bits received 
	if (bit_count == 8)
	{
		ft_printf("%c", character);
		// reinitiliaser les compteurs pr la prochaine fois
		character = 0;
		bit_count = 0;
	}
}

int main(int ac, char **av)
{
	int pid;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Error : wrong format\n");
		return (0);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	ft_printf("Waiting for message ...");

	while (ac == 1)
	{
		signal(SIGUSR1, ft_bit_to_ascii);
		signal(SIGUSR2, ft_bit_to_ascii);
		pause();
	}
}