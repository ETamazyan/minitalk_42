/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:33:59 by etamazya          #+#    #+#             */
/*   Updated: 2024/03/13 14:14:29 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_print_checklist(char c, va_list ap);
int				ft_putchar(int i);
int				ft_putstr(char *str);
unsigned int	ft_putnbr(int num);
unsigned int	ft_puthex(unsigned int ul, char c);
unsigned int	ft_putptr(unsigned long ul, char c);
unsigned int	ft_putunit(unsigned int num);

#endif
