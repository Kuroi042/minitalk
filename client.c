#include "minitalk.h"

 static void send(int pid, char *message)
{
    int bit;
    int i = 0;

    

    while (message[i] != '\0')        
    {
        
        bit = 0;
        while (bit < 8)
        {
            

            if ((message[i] & (1 << bit)) != 0)

                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
                
            usleep(100);

            bit++;
        }
        i++;
     
    }
}
int main(int argc, char **argv)
{
    int pid;
    int i;

    i = 0;
    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
     if(pid < 2)
     {
         write(1,"pid error",9);
        exit(0);
     }
        send(pid, argv[2]);
        return 0;
    }
    else
    {
        printf("bad format");
        exit(0);
    }
}