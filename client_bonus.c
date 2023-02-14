#include "minitalk.h"
//size_t incr = 0;
static void signalback(int sig, size_t len)
{
    sig = SIGUSR1;
    sig++;
    if (incr == len)
    {
        write(1, "message received", 25);
    }
}

static void sender(int pid, char *message, size_t len)
{
    (void)len;
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
    signalback(int sig, size_t len);
}

int main(int argc, char **argv)
{
    int pid;
    //int i = 0;

    if (argc == 3)
    {
        pid = ft_atoi(argv[1]);
        if (pid < 2)
        {
            write(1, "pid is not valid :( ", 20);
            exit(0);
        }
        size_t len = ft_strlen(argv[2]);
        sender(pid, argv[2], len);
        signal(SIGUSR1, signalback);
        return 0;
    }
    else
    {
        printf("bad format");
        exit(0);
    }
}