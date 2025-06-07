#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>

// server functions

unsigned char   bits_to_char(int *arr_bits);
void    signal_to_bits(int signal);

// client functions

int	av_to_pid(char	*av);
int	*char_to_bits(unsigned char c);
void	msg_to_server(int sv_pid, int *bits);

#endif