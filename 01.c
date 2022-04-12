#include <stdio.h>

int main ()
{
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
