/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:26:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/07 08:05:28 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minitalk.h"

unsigned char   bits_to_char(int *arr_bits)
{
    unsigned char   result;
    unsigned int    i;

    result = 0;
    i = 0;
    
    while (i < 8)
    {
        result |= ((arr_bits[i] & 1) << ( 7 - i));
        i++;
    }
    return (result);
}

void    signal_to_bits(int signal)
{
    unsigned char   c;
    static int    i = 0;
    static int arr_bits[8] = {0};

    if(signal != SIGUSR1 && signal != SIGUSR2)
        return ;
    if (signal == SIGUSR1)
        arr_bits[i] = 0;
    else if (signal == SIGUSR2)
        arr_bits[i] = 1;
    i++;
    if (i == 8)
    {
        c = bits_to_char(arr_bits);
        write(1, &c, 1);
        i = 0;
    }
}

int main(void)
{
    ft_printf("PID: %d\n", getpid());
    
    signal(SIGUSR1, signal_to_bits);
    signal(SIGUSR2, signal_to_bits);

    while(1)
        pause();
}

