/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:54:30 by skirakos          #+#    #+#             */
/*   Updated: 2024/03/21 20:54:33 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_get_ptr(unsigned long x);
int		ft_printf_ptr(unsigned long long x);
int		ft_printf_x(unsigned int x);
int		ft_get_x(unsigned int x);
int		ft_get_upperx(unsigned int x);
int		ft_printf_upperx(unsigned int x);
int		ft_printf_u(unsigned int u);
int		ft_printf_d(int d);
int		ft_printf_str(char *x);
void	ft_putnbr_u(unsigned int u);
void	print(char c);
void	ft_putnbr(int d);

#endif
