/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:38:34 by nino              #+#    #+#             */
/*   Updated: 2024/01/08 13:53:10 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void    process_signal_to_char(int signal)
{
    static int bit;
    static int character;

    bit = 0;
    character = 0;

    if (signal == SIGUSR1)
        character |= (1 << bit);
    bit++;

    if (bit == 8)
    {
        ft_printf("%c", character);
        bit = 0;
        character = 0;
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
        signal(SIGUSR1, process_signal_to_char);
        signal(SIGUSR2, process_signal_to_char);
        pause();
    }
}