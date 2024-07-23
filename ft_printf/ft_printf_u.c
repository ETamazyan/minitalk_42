/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skirakos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 20:58:44 by skirakos          #+#    #+#             */
/*   Updated: 2024/03/21 20:58:46 by skirakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int u)
{
	if (u >= 10)
	{
		ft_putnbr_u(u / 10);
		ft_putnbr_u(u % 10);
	}
	else if (u < 0)
	{
		u = -u;
		print('-');
		ft_putnbr_u(u);
	}
	else
		print(u + '0');
}

int	ft_printf_u(unsigned int u)
{
	int		len;

	ft_putnbr_u(u);
	len = 1;
	while (u / 10 != 0)
	{
		len++;
		u /= 10;
	}
	return (len);
}
