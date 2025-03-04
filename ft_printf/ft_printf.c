/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:41:58 by etamazya          #+#    #+#             */
/*   Updated: 2024/03/14 12:18:03 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

unsigned int	ft_putptr(unsigned long ul, char c)
{
	size_t	count;
	char	*str;

	count = 0;
	str = "0123456789abcdef";
	if (ul < 16)
		count += ft_putchar(str[ul]);
	else
	{
		count += ft_putptr(ul / 16, c);
		count += ft_putptr(ul % 16, c);
	}
	return (count);
}

int	ft_print_checklist(char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		count += ft_putunit(va_arg(ap, unsigned int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), c);
	else if (c == 'p')
	{
		count += write(1, "0x", 2);
		count += ft_putptr(va_arg(ap, unsigned long), c);
	}
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	size_t	count;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
			count += ft_print_checklist(*(++s), ap);
		else
			count += write(1, s, 1);
		s++;
	}
	va_end(ap);
	return (count);
}
