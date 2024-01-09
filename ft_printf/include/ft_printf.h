/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:53:09 by nclassea          #+#    #+#             */
/*   Updated: 2023/11/27 12:13:33 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *txt, ...);
int	ft_printchar(char c);
int	ft_printstr(char *str);
int	ft_printnbr(int n);
int	ft_printptr(unsigned long long n);
int	ft_print_unsigned_nb(unsigned int n);
int	ft_printhex(unsigned int n, char format);

#endif