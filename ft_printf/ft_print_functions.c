/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:42:09 by etamazya          #+#    #+#             */
/*   Updated: 2024/03/14 12:13:46 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int i)
{
	return (write(1, &i, 1));
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += ft_putstr("(null)");
		return (count);
	}
	while (*str)
	{
		ft_putchar((int)*str);
		count++;
		str++;
	}
	return (count);
}

unsigned int	ft_puthex(unsigned int ul, char c)
{
	size_t	count;
	char	*str;

	count = 0;
	str = "0123456789ABCDEF";
	if (c == 'x')
		str = "0123456789abcdef";
	if (ul < 16)
		count += ft_putchar(str[ul]);
	else
	{
		count += ft_puthex(ul / 16, c);
		count += ft_puthex(ul % 16, c);
	}
	return (count);
}

unsigned int	ft_putnbr(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		if (num == -2147483648)
		{
			return (ft_putstr("-2147483648"));
		}
		count += ft_putchar('-');
		num = -num;
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}

unsigned int	ft_putunit(unsigned int num)
{
	int	count;

	count = 0;
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putnbr(num % 10);
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}
