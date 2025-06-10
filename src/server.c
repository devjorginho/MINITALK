/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:26:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/10 11:41:28 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void ft_putstr(char *s)
{
    if (!s)
        return;
    while (*s)
        write(1, s++, 1);
}
void show_msg(int sig, t_data *data)
{
    if (data->i < 8)
    {
        data->c = (data->c << 1) + (sig == SIGUSR1);
        data->j++;
    }
    if (data->j == 8)
    {
        data->str[data->index++] = data->c;
        if(data->str[data->index] == '\0')
        {
            ft_putstr(data->str);
            data->index = 0;
        }
        data->j = 0;
        data->c = 0;
    }
}
void signal_to_bits(int sig)
{
    static t_data data;
    

    if (data.i < 32)
    {
        data.len = (data.len << 1) + (sig == SIGUSR1);
        data.i++;
    }
    if (data.i == 32)
    {   
        data.str = malloc(data.len + 1);
        if (!data.str)
            return;
        data.i = 0;
    }
    else
        show_msg(sig, &data);
}

int main(void)
{
    printf("PID: %d\n", getpid());
    signal(SIGUSR1, signal_to_bits);
    signal(SIGUSR2, signal_to_bits);
    while (1)
        pause();
}
