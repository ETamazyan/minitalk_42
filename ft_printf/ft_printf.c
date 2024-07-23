/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:49:35 by skirakos          #+#    #+#             */
/*   Updated: 2024/03/21 20:49:37 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print(char c)
{
	write(1, &c, 1);
}

int	ft_printf_str(char *x)
{
	int		j;
	int		len;

	j = 0;
	len = 0;
	if (x == NULL)
	{
		write(1, "(null)", 6);
		len += 6;
	}
	else
	{
		while (x[j] != '\0')
		{
			write(1, &x[j++], 1);
			len++;
		}
	}
	return (len);
}

void	ft_check(const char *str, int i, int *len, va_list args)
{
	char		c;

	if (str[i] == '%' && str[i + 1] == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		(*len)++;
	}
	else if (str[i] == '%' && str[i + 1] == 's')
		*len += ft_printf_str(va_arg(args, char *));
	else if (str[i] == '%' && str[i + 1] == 'p')
		*len += ft_printf_ptr(va_arg(args, unsigned long));
	else if (str[i] == '%' && (str[i + 1] == 'd' || str[i + 1] == 'i'))
		*len += ft_printf_d(va_arg(args, int));
	else if (str[i] == '%' && str[i + 1] == 'u')
		*len += ft_printf_u(va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'x')
		*len += ft_printf_x(va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == 'X')
		*len += ft_printf_upperx(va_arg(args, unsigned int));
	else if (str[i] == '%' && str[i + 1] == '%')
		*len += write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		ft_check(str, i, &len, args);
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
		else
			i += 2;
	}
	va_end(args);
	return (len);
}
