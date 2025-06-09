/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:26:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/09 13:00:09 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minitalk.h"

t_data *data()
{
    static t_data g_struct;
    return (&g_struct);
}

void    signal_to_bits(int sig)
{
    
}
int main(void)
{
    ft_printf("PID: %d\n", getpid());
    signal(SIGUSR1, signal_to_bits);
    signal(SIGUSR2, signal_to_bits);

    while(1)
        pause();
}

