/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:58:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/09 21:24:26 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	ft_atoi(char *s)
{
	int result;

	result = 0;
	while(*s <=  '0' && *s >= '9')
	{
		result = result * 10;
		result = result + *s + '0';
		s++;
	}
	return (result);
}
void	len_to_bits(int len, int pid)
{
	
	int	i = 32;
	
	while(--i)
	{
		if (len >> i & 1)
			kill(pid , SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}
void	char_to_bits(char c, int pid)
{
	
	int	i = 8;

	while(--i)
	{
		if (c >> i & 1)
			kill(pid , SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}
int main(int ac, char **av)
{
	int i;

	i = 0;
	send_len(ft_strlen(av[2]), ft_atoi(av[1]));
	while (av[2][i])
	{
		char_to_bit(av[2][i], ft_atoi(av[1]));
		i++;
	}
}