/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 06:58:26 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 23:17:54 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int receive_sig = 0; // aqui a gente cria uma variavel global e seta ela como zero
// zero pq a gente vai usar ela la na frente

void    receive(int sig) // o carai da struct do sigaction recebe uma funcao
{                       // toda vida que a gente receber um sinal ele vai chamar isso aqui e vai setar a global pra 1
    (void)sig;              // ou seja quando ela for chamada e pq existe um sinal
    receive_sig = 1;
}
int	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int	ft_atoi(char *s)
{
	int result;

	result = 0;
	while(*s >=  '0' && *s <= '9')
	{
		result = result * 10;
		result = result + *s - '0';
		s++;
	}
	return (result);
}
void	send_len(int len, int pid)
{
	
	int	i = 31;
	
	while(i >= 0)
	{
        receive_sig = 0;  // aqui a gente vai zerar pra enviar o primeiro bit 
		if (len >> i & 1)
			kill(pid , SIGUSR1); // envia aqui
		else
			kill(pid, SIGUSR2); // ou aqui
		while (!receive_sig) // aqui vai ficar pausado enquanto nao receber o sinal, quando receber o receive_sig vai ser 1
            pause();
		i--;
	}
}
void	send_char(char c, int pid)
{
	int	i = 7;

	while(i >= 0)
	{
        receive_sig = 0; // mesma logica de cima
		if (c >> i & 1)
			kill(pid , SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while(!receive_sig) // mesma coisa
            pause();
		i--;
	}
} // entao, o client vai mandar de um e so vai mandar o proximo quando receber um sinal
int main(int ac, char **av)
{
    struct sigaction sa; // essa struct e a base do sigaction ali embaixo eu digo porque
	int i;
            // porque
            // brincadeira, mais embaixo
	i = 0;
    sa.sa_handler = receive; // o sa handler e um membro da struct sa, ele serve pra executar uma acao quando receber um sinal
    sa.sa_flags = 0; // no nosso caso ele chama aquela funcao la em cima
    sigemptyset(&sa.sa_mask); // dentro da sa_mask tem um conjunto de sinais, essa funcao limpa todos exceto o que chamou ela, no caso na linha debaixo
    sigaction(SIGUSR1, &sa, NULL); // aqui a gente sabe que quem chamou a struct foi o SIGUSR1, entao o sigempytset limpa todos os sinais e bloqueia todos os sigursr1 enquanto o primeiro nao foi tratado
    // limpando a set, qualquer sinal sem ser o sigusr1 vai ser recebido e tratado
	if(ac != 3)
		return (-1); // se nao tiver o uso ./client pid str
	if(ft_atoi(av[1]) < 1)
		return (-1); // se alguem quiser crashar o pc dando um pid invalido
	send_len(ft_strlen(av[2]) + 1, ft_atoi(av[1])); // manda a len primeiro
	while (av[2][i])
	{
		send_char(av[2][i], ft_atoi(av[1])); // mmanda o char
		i++;
	}
}