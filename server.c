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
void sig_handler(int sig)
{
    
    static int i = 0;
    static int arr[8];
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
        //write(1,"\n",1);
        i = 0;
        unsigned char decoded = bitsdecoder(arr);
        write(1,&decoded,1);    
        ft_bzero(arr, 8);
    }
}

int main(int argc, char *argv[])
{
(void)**argv;
   struct sigaction sa;
   sa.sa_handler = &sig_handler;
   sigaction(SIGUSR1, &sa, NULL);
   sigaction(SIGUSR2, &sa, NULL);

   int pid = getpid();
   if (argc == 1)
   {
      printf("%d\n", pid);
      printf("waiting...\n");
      while (1)
      {
         pause();
      }
   }
   return 0;
}
