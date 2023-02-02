#ifndef MINITALK_H
#define MINITALK_H



#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>



int ft_atoi(char *str);
size_t ft_strlen(char *str);
void *ft_calloc(size_t count, size_t size);
void	ft_putnbr(int n );
void	ft_putchar(char c );
 void sender(int pid, char *message);
void sig_handler(int sig, siginfo_t *siginfo, void *context);
void ft_bzero(int *str , int len);
int ft_power(int base, int exponent);


#endif
