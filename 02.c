#include <stdio.h>
#include <math.h>

int main()
{
    int subnum, num;
    do
    {
        printf("Informe o numero completo: ");
        scanf("%d", &num);
        getchar();

        printf("Informe os ultimos digitos do numero: ");
        scanf("%d", &subnum);
        getchar();

        // Conta o numero de digitos dos numeros inteiros
        int sub_len = 0, num_len = 0;
        int aux_sub = subnum, aux_num = num;
        while (aux_sub != 0)
        {
            aux_sub = aux_sub / 10;
            sub_len++;
        }
        while (aux_num != 0)
        {
            aux_num = aux_num / 10;
            num_len++;
        }

        // Primeiramente verifica se o número que deveria ser subnum é maior
        if (sub_len > num_len)
        {
            printf("%d => nao encaixa\n", subnum);
        }
        // Caso seja igual ou menor, verifica se os numeros sao iguais
        else
        {
            int verifier = 0;
            int divider = round(pow(10, sub_len));

            if (subnum % divider == num % divider)
            {
                verifier = 1;
                printf("%d => encaixa\n", subnum);
            }
            else
            {
                verifier = 0;
                printf("%d => nao encaixa\n", subnum);
            }
        }
    } while (subnum != 0 || num != 0);
}
