/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:26:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 16:41:44 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void show_msg(int sig, t_data *data)
{
    if (data->i < 8)
    {
        data->c = (data->c << 1) + (sig == SIGUSR1);
        data->i++;
    }
    if (data->i == 8)
    {
        data->str[data->index++] = data->c;
        if(data->index == (data->len - 1))
        {
            //printf("end\n");
            write(1, data->str,  data->len);
            free(data->str);
            data->str = NULL;
            data->index = 0;
            data->c = 0;
        }
        data->i = 0;
    }
}
void signal_to_bits(int sig)
{
    static t_data data;
    
    if (data.str)
        show_msg(sig, &data);
    else if (data.i < 32)
    {
        data.len = (data.len << 1) + (sig == SIGUSR1);
        data.i++;
    }
    if (data.i == 32)
    {   
       // printf("len: %i\n", data.len);
        data.str = malloc(data.len + 1);
        if (!data.str)
            return;
        data.i = 0;
    }

}

int main(void)
{
    printf("PID: %d\n", getpid());
    signal(SIGUSR1, signal_to_bits);
    signal(SIGUSR2, signal_to_bits);
    while (1)
        pause();
}
