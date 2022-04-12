#include <stdio.h>

int main()
{
    int subnum, num;
    do{
        scanf("%d %d", &num, &subnum);
        
        //Conta o numero de digitos dos numeros inteiros
        int sub_len=0, num_len=0;
        int aux_sub = subnum, aux_num = num;
        while(aux_sub != 0)  
        {  
            aux_sub = aux_sub/10;  
            sub_len++;  
        }
        while(aux_num != 0)
        {
            aux_num = aux_num/10;
            num_len++;
        }
        
        //Primeiramente verifica se o número que deveria ser subnum é maior
        if (sub_len > num_len)
        {
            printf("%d => nao encaixa", subnum);
        }
        //Caso seja igual ou menor, verifica se os numeros sao iguais
        else
        {
            int count = 1, divider = 10, verifier = 0;
            while(sub_len!=0)
            {
                for (int i = 0; i < count-1; i++)
                {
                    divider *= 10;
                }
                if (subnum % divider == num % divider)
                {
                    verifier = 1;
                }
                else
                {
                    verifier = 0;
                    sub_len = 0;
                    printf("%d => nao encaixa\n", subnum);
                    break;
                }
                sub_len--;
            }
            
            if (verifier == 1)
            {
                printf("%d => encaixa\n", subnum);
            }
        }
    }while(1);
}

