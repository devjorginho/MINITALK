/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:26:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 22:37:24 by devjorginho      ###   ########.fr       */
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
            write(1, data->str,  data->len);
            free(data->str);
            data->str = NULL;
            data->index = 0;
            data->c = 0;
        }
        data->i = 0;
    }
}
void signal_to_bits(int sig, siginfo_t *info, void *context)
{
    static t_data data;
    (void) context;
    
    if (data.str)
        show_msg(sig, &data);
    else if (data.i < 32)
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
    if(info && info->si_pid)
        kill(info->si_pid, SIGUSR1);
}

int main(void)
{
    struct sigaction sa;

    printf("PID: %d\n", getpid());
    sa.sa_sigaction = signal_to_bits;
    sa.sa_flags = SA_SIGINFO;
     sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
}
