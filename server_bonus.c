/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:55:40 by mbouderr          #+#    #+#             */
/*   Updated: 2023/02/17 13:00:50 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_client_pid = 0;

unsigned char	bitsdecoder(int *bits)
{
	unsigned char	c;
	int				res;
	int				j;

	res = 0;
	j = 7;
	while (j >= 0)
	{
		res += (bits[j] * ft_power(2, j));
		j--;
	}
	c = (unsigned char)res;
	return (c);
}

static void	check_client(int *arr, siginfo_t *siginfo, int *i)
{
	if (g_client_pid == 0)
		g_client_pid = siginfo->si_pid;
	else if (siginfo->si_pid != g_client_pid)
	{
		*i = 0;
		ft_bzero(arr, 8);
		g_client_pid = siginfo->si_pid;
	}
}

void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int		i;
	static int		arr[8];
	unsigned char	decoded;
	static pid_t	client_pid;

	client_pid = 0;
	(void)*context;
	check_client(arr, siginfo, &i);
	if (sig == SIGUSR1)
		arr[i++] = 1;
	else if (sig == SIGUSR2)
		arr[i++] = 0;
	if (i > 7)
	{
		i = 0;
		decoded = bitsdecoder(arr);
		write(1, &decoded, 1);
		ft_bzero(arr, 8);
		kill(siginfo->si_pid, SIGUSR1);
	}
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)**argv;
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc == 1)
	{
		pid = getpid();
		ft_putnbr(pid);
		write(1, "\n", 1);
		write(1, "waiting...\n", 11);
		while (1)
		{
			pause();
		}
	}
	return (0);
}
