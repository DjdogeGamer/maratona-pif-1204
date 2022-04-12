#include <stdio.h>

int main ()
{
    /*
    Essa e a questao mais simples, e era uma pegadinha.
    Não necessariamente precisa implementar uma matriz,
    essa seria a implementacao mais rapida e eficiente
    dado o tempo da maratona. As proximas tem implementacoes
    mais sofisticadas.
    */
    
    int pedras_brancas, pedras_pretas;
    
    scanf("%d %d", &pedras_brancas, &pedras_pretas);
    
    if (pedras_brancas > pedras_pretas)
    {
        printf("O jogador de pedras brancas esta vencendo\n");
    }
    else if (pedras_brancas == pedras_pretas)
    {
        printf("O jogo está empatado\n");
    }
    else
    {
        printf("O jogador de pedras pretas esta vencendo\n");
    }
}
