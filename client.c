/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:18:46 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 17:43:16 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	send_message(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("%s", "Received\n");
}

void	send_binary(int pid, char *str)
{
	int		i;
	int		shift;

	i = 0;
	while (str[i])
	{
		shift = 0;
		while (shift <= 7)
		{
			if (str[i] >> shift & 1)
				kill(pid, SIGUSR2);
			else if ((str[i] >> shift & 1) == 0)
				kill(pid, SIGUSR1);
			else
				exit(write(2, "Error", 6));
			usleep(100);
			shift++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		signal(SIGUSR1, send_message);
		pid = ft_atoi(argv[1]);
		if (pid < 0)
			exit (1 && write(1, "Error\n", 1));
		send_binary(pid, argv[2]);
		send_binary(pid, "\n");
	}
	else
	{
		ft_printf("%s", "Invalid amount of arguments.\n");
		exit(1);
	}
}
