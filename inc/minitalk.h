#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data {
    int     i;
    int     j;
    int     len;
    int     index;
    char    c;
    char    *str;
} t_data;

void    receive(int sig);
int	ft_strlen(char *s);
int     ft_atoi(char *s);
void	send_len(int len, int pid);
void	send_char(char c, int pid);
void    show_msg(int sig, t_data *data);
void    signal_to_bits(int sig, siginfo_t *info, void *context);


#endif