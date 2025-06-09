/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-carv <jde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:26:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/09 21:23:41 by jde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_data *get_data(void)
{
    static t_data data;
    return (&data);
}
void    show_msg(int sig)
{
    t_data *data = get_data();

    data->c = (data->c << 1) | (sig == SIGUSR2);
    data->j++;

    if (data->j == 8)
    {
        data->str[data->index++] = data->c;
        write(1, &data->c, 1);
        data->j = 0;
        data->c = 0;
    }
}

void    signal_to_bits(int sig)
{
    t_data *data = get_data();

    data->len = (data->len << 1) | (sig == SIGUSR2);
    data->i++;

    if (data->i == 32)
    {
        data->str = malloc(data->len + 1);
        if (!data->str)
            exit(1);
        data->str[data->len] = '\0';
        signal(SIGUSR1, show_msg);
        signal(SIGUSR2, show_msg);
    }
}

int main(void)
{
    ft_printf("PID: %d\n", getpid());
    signal(SIGUSR1, signal_to_bits);
    signal(SIGUSR2, signal_to_bits);
    while (1)
        pause();
}
