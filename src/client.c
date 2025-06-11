/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:58:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 15:12:01 by jde-carv         ###   ########.fr       */
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
	while(*s >=  '0' && *s <= '9')
	{
		result = result * 10;
		result = result + *s - '0';
		s++;
	}
	return (result);
}
void	send_len(int len, int pid)
{
	
	int	i = 31;
	
	while(i >= 0)
	{
		if (len >> i & 1)
			kill(pid , SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}
void	send_char(char c, int pid)
{
	
	int	i = 7;

	while(i >= 0)
	{
		if (c >> i & 1)
			kill(pid , SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}
int main(int ac, char **av)
{
	int i;
	i = 0;
	if(ac != 3)
		return (-1);
	if(ft_atoi(av[1]) < 1)
		return (-1);
	send_len(ft_strlen(av[2]) + 1, ft_atoi(av[1]));
	while (av[2][i])
	{
		send_char(av[2][i], ft_atoi(av[1]));
		i++;
	}
	send_char('\0', ft_atoi(av[1]));
}