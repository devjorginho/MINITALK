#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>

typedef struct s_data
{
    int         bits_received;
    int         len;
    int         i;
	char		c;
    char		*str;
} t_data;

void	char_to_bits(char c);


#endif