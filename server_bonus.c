#include "minitalk.h"

unsigned char bitsdecoder(int *bits)
{
   unsigned char c;
   int res = 0;
   int j = 7;
   while (j >= 0)
   {
      res += (bits[j] * ft_power(2, j));
      j--;
   }
   c = (unsigned char)res;
   return c;
}

void sig_handler(int sig, siginfo_t *siginfo, void *context)

{
    (void)*context;
    static pid_t      client_pid = 0;
    static int i = 0;
    static int arr[8];
    if(siginfo->si_pid != client_pid)
    { 
        client_pid = siginfo->si_pid;
       i = 0;    
        ft_bzero(arr,8);
    }
    if (sig == SIGUSR1)
    {
        arr[i++] = 1;  
    }
    else if (sig == SIGUSR2)
    {
        arr[i++] = 0;
    }
    if (i == 8)
    {
        i = 0;       
        {
            unsigned char decoded = bitsdecoder(arr);
            write(1, &decoded,1);
            kill(siginfo->si_pid, SIGUSR1);
            ft_bzero(arr, 8);
        }
    }
}

int main(int argc, char *argv[])
{
   (void)**argv;
   struct sigaction sa;
   sa.sa_sigaction = &sig_handler;
   sa.sa_flags = SA_SIGINFO;
   sigaction(SIGUSR1, &sa, NULL);
   sigaction(SIGUSR2, &sa, NULL);

   if (argc == 1)
   {
    int pid = getpid();
      printf("%d\n", pid);
      printf("waiting...\n");
      while (1)
      {
         pause();
      }
   }
   return 0;
}