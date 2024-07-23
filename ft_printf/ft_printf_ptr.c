/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:57:51 by skirakos          #+#    #+#             */
/*   Updated: 2024/03/21 20:57:55 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptr(unsigned long x)
{
	int		len;
	char	*b;

	b = "0123456789abcdef";
	len = 0;
	if (x >= 16)
	{
		len += ft_get_ptr(x / 16);
		write(1, &b[x % 16], 1);
		len += 1;
	}
	else
	{
		write(1, &b[x], 1);
		len += 1;
	}
	return (len);
}

int	ft_printf_ptr(unsigned long long x)
{
	int	len;

	len = 0;
	len += 2;
	write(1, "0x", 2);
	len += ft_get_ptr(x);
	return (len);
}
