#include "minitalk.h"
#include <stdio.h>
#include <unistd.h>
int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	int		nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (*str == '\n' || *str == ' ' || *str == '\t' || *str == '\v'
		|| *str == '\r' || *str == '\f')
		str++;
	if (str[i] == '-')
	{
		i++;
		sign = sign * -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

size_t ft_strlen(char *str)
{
	int i =0 ;
	while(str[i] != '\0')
	{
		i++;
	}
	return i;
}
void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

void	ft_putnbr(int n )

{
	long int	i;

	i = (long int)n;
	if (i < 0)
	{
		i *= -1;
		ft_putchar('-');
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	if (i >= 0 && i <= 9)
	{
		ft_putchar(i + 48);
	}
}
void ft_putchar(char c)
{
	write(1,&c,1);
}
void ft_bzero(int *str,int len)
{
	int i = 0;
	if(i <len)
	{
		str[i] = '\0';
		i++;
	}
}

int ft_power(int base, int exponent) 
{
  int result = 1;
  int  i = 0; 
  while (i < exponent) {
    result *= base;
    i++;
  }
  return result;
}