/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:26:29 by jde-carv          #+#    #+#             */
/*   Updated: 2025/06/11 23:44:07 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void show_msg(int sig, t_data *data) // esse e um ponteiro pra struct t_data, tudo que a gente altera por ele altera la na struct pois e static
{
    if (data->i < 8)
    {
        data->c = (data->c << 1) + (sig == SIGUSR1); // trata o sinal
        data->i++;
    }
    if (data->i == 8) // recebi 8 entao ja sei o caractere
    {
        data->str[data->index++] = data->c; // str recebe o char e pula pro proximo index 
        if(data->index == (data->len - 1)) // se o index tiver o tamanho da string fora o nulo
        {
            write(1, data->str,  data->len); // printa
            free(data->str); // da free
            data->str = NULL; // inicializamos o str, nao sei se precisaria
            data->index = 0; // zeramos, caso precisemos povoar uma nova str
            data->c = 0; // zeramos tambem pra tratar o proximo char
        }
        data->i = 0; // zeramos pra tratar os proximos bits
    }
}
void signal_to_bits(int sig, siginfo_t *info, void *context)
{
    static t_data data; // aquele ponteiro pra struct aponta pra essa aqui, a gente criou aqui
    (void) context; // isso aqui serve pra ver o estado do processo quando recebemos o primeiro sinal
    // ele salva isso pra que possa tratar em algum caso, no nosso caso nao é necessario
    
    
    if (data.str)  // ve se a str ja foi alocada
        show_msg(sig, &data); // se sim ela vai chamar a funcao show msg, recebendo o sinal e o endereco da struct que queremos tratar
    else if (data.i < 32) // aqui e pra tratar os primeiros 32 que vao ser o tamanho da string pois um int tem 32 bits
    {
        data.len = (data.len << 1) + (sig == SIGUSR1); // mesma coisa de la em cima
        data.i++;
    }
    if (data.i == 32) // chegou no 32 ja temos o tamanho
    {   
        data.str = malloc(data.len + 1); // aloca memoria
        if (!data.str) // protege o mallocao
            return;
        data.i = 0; // zera pra tratar os proximos bits, pois trata-se de uma estrutura statica precimos
        // compartilhar o dados entre elas.
    }
    if(info && info->si_pid) // aqui e o show da miada, ele ve se o ponteiro info e nulo ou se o tem algum pid ali dentro do s1_pid
        // se tiver um pid dentro do si_pid ele manda a mensagem embaixo usando o kill com o pid do client
        kill(info->si_pid, SIGUSR1);

        // como isso funciona e como o pid foi parar ali ? vou te mostrar na main
}

int main(void)
{
    struct sigaction sa;

    printf("PID: %d\n", getpid());
    sa.sa_sigaction = signal_to_bits; // aqui ja chama a funcao que vai ser chamada quando ele receber algum sinal dos sigurs1 ou sigusr2
    sa.sa_flags = SA_SIGINFO; // em vez de a gente usar o sa_handler igual o outro a gente vai usar o SA_SIGINFO ela permite que eu consiga usar o meu handle com 3 parametros.
    // ou seja, agora ao inves de so chamar uma funcao ele vai receber informacoes extras sobre aquele sinal que ele receber, se nao, ele so vai tratar o sinal
    // sem SA_SIGINFO a gente nao receberia o pid do client
    sigemptyset(&sa.sa_mask); // mesma coisa do client, ele bloqueia o proximo sinal do tipo que ele acabou de receber e abre o resto
    sigaction(SIGUSR1, &sa, NULL); // quando ele receber isso ele vai chamar o signal to bits
    sigaction(SIGUSR2, &sa, NULL); // same
    while (1) // fica pausado enquando nao recebe o proximo bit
        pause(); // so acorda se for pra tratar sinais
}
