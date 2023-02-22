/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:14:43 by mbouderr          #+#    #+#             */
/*   Updated: 2023/02/22 01:03:32 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>

int		ft_atoi(char *str);
size_t	ft_strlen(char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
void	sig_handler(int sig, siginfo_t *siginfo, void *context);
void	ft_bzero(int *str, int len);
int		ft_power(int base, int exponent);

#endif
