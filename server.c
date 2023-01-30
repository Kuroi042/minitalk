#include "minitalk.h"      

void sig_handler(int sig)
{
    static char bits[7];
    static int i = 0;
    if (i <= 7)
    {
        if (sig == SIGUSR1)
        {
            bits[i] = '1';
        }
        else if (sig == SIGUSR2)
        {
            bits[i] = '0';
        }

        i++;
    }

    if (i == 7)
    {
        bits[i] = '\0';
        printf("Server received message: %s\n", bits);
        i = 0;
    }
}

int main(int argc , char *argv[]) 
{
  struct sigaction sa;
  sa.sa_handler = &sig_handler;
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);


    if(argc != 1)
    {
        write(1,"wawawawawa",6);
    }
  
(void)**argv;

int pid = getpid();
if(argc == 1)
{
    ft_putnbr(pid);
   write(1,"\nwaiting...\n",15);
  while(1)
    {
     pause();
    }
}
}
