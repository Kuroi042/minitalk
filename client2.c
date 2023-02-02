#include "minitalk.h"

void	send(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (1 << bit)) != 0)
		printf("%d \n", bit );
			kill(pid, SIGUSR1);
                    

		// else
		// 	kill(pid, SIGUSR2);
		// usleep(100);
		 bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			send(pid, argv[2][i]);
			i++;
		}
		send(pid, '\n');
	}
	else
	{
		printf("Error: wrong format.\n");
		return (1);
	}
	return (0);
}