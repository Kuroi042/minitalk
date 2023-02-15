/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 23:55:48 by mbouderr          #+#    #+#             */
/*   Updated: 2023/02/16 00:01:07 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putnbr(int n)

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

void	ft_bzero(int *str, int len)
{
	int	i;

	i = 0;
	if (i < len)
	{
		str[i] = '\0';
		i++;
	}
}

int	ft_power(int base, int exponent)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (i < exponent)
	{
		result *= base;
		i++;
	}
	return (result);
}
