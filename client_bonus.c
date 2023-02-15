/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:19:54 by mbouderr          #+#    #+#             */
/*   Updated: 2023/02/15 21:58:32 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

size_t		g_incr = 0;

void	signalback(int sig)
{
	if (sig == SIGUSR1)
	{
		g_incr++;
	}
}

static void	sender(int pid, char *message, size_t len)
{
	int	bit;
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		bit = 0;
		while (bit < 8)
		{
			if ((message[i] & (1 << bit)) != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(150);
			bit++;
		}
		i++;
	}
	if (g_incr == len)
		write(1, "<<yes>>", 7);
	exit(0);
	if (g_incr != len)
		write(1, "<<no>>", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	int					pid;
	size_t				len;
	struct sigaction	sa;

	sa.sa_handler = signalback;
	sa.sa_flags = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 2)
		{
			write(1, "pid is not valid :( ", 22);
			exit(0);
		}
		len = ft_strlen(argv[2]);
		sigaction(SIGUSR1, &sa, NULL);
		sender(pid, argv[2], len);
	}
	else
	{
		write(1, "invalid format\n", 16);
		exit(0);
	}
	return (0);
}
