#ifndef MINITALK_H
# define MINITALK_H

# include "../ft_printf/ft_printf.h"
# include <signal.h>


typedef struct s_data {
    int     i;
    int     j;
    int     len;
    int     index;
    char    c;
    char    *str;
} t_data;

int     ft_strlen(char *s);
int     ft_atoi(char *s);
void	len_to_bits(int len, int pid);
void	char_to_bits(char c, int pid);
void    show_msg(int sig);
void    signal_to_bits(int sig);


#endif