/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:58:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/13 14:31:10 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	ft_atoi(const char *s)
{
	int result = 0;

	while (*s)
	{
		result = result * 10 + (*s - '0');
		s++;
	}
	return (result);
}
int	is_numeric(const char *s)
{
	int i = 0;

	if (!s || !s[0])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
int	ft_strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}
void	ft_putstr(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
void	ft_putnbr(int nb)
{
	char c;

	if(nb > 9)
		ft_putnbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);	
}