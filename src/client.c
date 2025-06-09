/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:58:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/09 12:57:27 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// receber pid do server
// receber char e converter pra bits
// usar kill pra poder enviar os sinais em formato de bits pro server atraves do pid


#include "../inc/minitalk.h"

void	len_to_bits(int len, int pid)
{
	
	int	i = 32;

	while(--i)
	{
		if (len >> i & 1)
			kill(pid , SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
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
		pause();
	}
}
int main(int ac, char **av)
{
	int i;

	i = 0;
	send_len(ft_strlen(av[2]), atoi(av[1]));
	while (av[2][i])
	{
		char_to_bit(av[2][i], atoi(av[1]));
		i++;
	}
}