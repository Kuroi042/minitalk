#include <unistd.h>
    int main()
    {
  int bit;
 int i = 0;

    char message[] = "x";

    while (message[i] != '\0')        
    {
        bit =0;
        
        
        while (bit < 8)
        {
            

            if ((message[i] & (1 << bit)))

                write(1,"0",1);
            else
                write(1,"1",1);                


            bit++;
        }
        i++;
 
    }



}