/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 21:02:24 by skirakos          #+#    #+#             */
/*   Updated: 2024/03/21 21:02:25 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_x(unsigned int x)
{
	int		len;
	char	*b;

	len = 0;
	b = "0123456789abcdef";
	if (x >= 16)
	{
		len += ft_get_x(x / 16);
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

int	ft_printf_x(unsigned int x)
{
	int	len;

	len = 0;
	len += ft_get_x(x);
	return (len);
}

int	ft_get_upperx(unsigned int x)
{
	int		len;
	char	*b;

	len = 0;
	b = "0123456789ABCDEF";
	if (x >= 16)
	{
		len += ft_get_upperx(x / 16);
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

int	ft_printf_upperx(unsigned int x)
{
	int	len;

	len = 0;
	len += ft_get_upperx(x);
	return (len);
}
