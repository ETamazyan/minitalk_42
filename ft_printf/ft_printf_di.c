/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:39:24 by skirakos          #+#    #+#             */
/*   Updated: 2024/03/21 21:39:26 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int d)
{
	if (d == -2147483648)
	{
		print('-');
		print('2');
		ft_putnbr(147483648);
	}
	else if (d >= 10)
	{
		ft_putnbr(d / 10);
		ft_putnbr(d % 10);
	}
	else if (d < 0)
	{
		d = -d;
		print('-');
		ft_putnbr(d);
	}
	else
		print(d + '0');
}

int	ft_printf_d(int d)
{
	int		len;

	ft_putnbr(d);
	len = 1;
	if (d < 0)
	{
		len++;
		d = -d;
	}
	while (d / 10 != 0)
	{
		len++;
		d /= 10;
	}
	return (len);
}
