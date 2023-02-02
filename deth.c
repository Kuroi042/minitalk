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
char message[100];  // array to store the decoded message
int message_index = 0;  // index to store next character

void sig_handler(int sig)
{
    static int i;
    i = 0;
    static int arr[8];
    if (sig == SIGUSR1)
    {
        arr[i++] = 1;
        printf("Received SIGUSR1\n");
    }
    else if (sig == SIGUSR2)
    {
        arr[i++] = 0;
        printf("Received SIGUSR2\n");
    }
    if (i == 8)
    {
        i = 0;
        printf("8 bits received: ");
        for (int j = 0; j < 8; j++)
        {
            printf("%d", arr[j]);
        }
        printf("\n");
        unsigned char decoded = bitsdecoder(arr);
        printf("Decoded character: %c\n", decoded);
        message[message_index++] = decoded;  // add the decoded character to the message
        ft_bzero(arr, 8);
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
