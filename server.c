/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etamazya <etamazya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:19:07 by etamazya          #+#    #+#             */
/*   Updated: 2024/07/19 17:27:47 by etamazya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byte;
	static int				bit_count;

	(void)context;
	if (sig == SIGUSR2)
		byte |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write (1, &byte, 1);
		byte = 0;
		bit_count = 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	pid = getpid();
	if (argc == 1)
	{
		if (pid <= 0)
			exit(write(2, "Failed to create pid\n", 21));
		ft_printf("SERVER IS UP TO DATE\n");
		ft_printf("Process ID : %d\n", pid);
		ft_printf("Type...\n");
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
		while (1)
		{
			sigaction(SIGUSR1, &sa, NULL);
			sigaction(SIGUSR2, &sa, NULL);
			pause();
		}
	}
	else
		exit(write(2, "Error\n", 6));
	return (0);
}
