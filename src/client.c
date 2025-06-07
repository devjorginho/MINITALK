/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:58:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/07 08:05:19 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// receber pid do server
// receber char e converter pra bits
// usar kill pra poder enviar os sinais em formato de bits pro server atraves do pid


#include "../inc/minitalk.h"

int	av_to_pid(char	*av)
{
	int pid = 0;
	while(*av >= '0' && *av <= '9')
	{
		pid = pid * 10 + (*av - '0');
		av++;
	}
	return(pid);
}
int	*char_to_bits(unsigned char c)
{
	static int	bits[8];
	int	i;

	i = 0;
	while(i < 8)
	{
		bits[7 - i] = (c >> i) & 1;
		i++;
	}
	return(bits);
}
void	msg_to_server(int sv_pid, int *bits)
{
	int	i;

	i = 0;
	while(i < 8)
	{
		if(bits[i] == 0)
			kill(sv_pid, SIGUSR1);
		else if(bits[i] == 1)
			kill(sv_pid, SIGUSR2);
		usleep(100);
		i++;
	}
}
int main(int ac, char **av)
{
	int	*bits;
	int	i;
	int	pid;

	if(ac != 3)
		return (1);
	i = 0;
	pid = av_to_pid(av[1]);
	while(av[2][i])
	{
		bits = char_to_bits(av[2][i]);
		msg_to_server(pid, bits);
		i++;
	}
	return(0);
}