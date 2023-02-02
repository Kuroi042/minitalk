void sig_handler(int sig)
{
    static int i;
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
        ft_bzero(arr, 8);
    }
}