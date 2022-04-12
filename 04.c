#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 4

typedef struct
{
    char nome[50];
    float nota;
} Aluno;

// Retorna o calculo da media das notas dos alunos
double getMedia(Aluno turma[])
{
    double sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum += turma[i].nota;
    }
    double media = sum / (double)SIZE;

    return media;
}

// Retorna a posicao no vetor do aluno com nota mais alta
int getHigh(Aluno turma[])
{
    int pos_maior = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (turma[i].nota > turma[pos_maior].nota)
        {
            pos_maior = i;
        }
    }

    return pos_maior;
}

// Retorna a posicao no vetor do aluno com nota mais baixa
int getLow(Aluno turma[])
{
    int pos_menor = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (turma[i].nota < turma[pos_menor].nota)
        {
            pos_menor = i;
        }
    }

    return pos_menor;
}

int main()
{
    Aluno turma[SIZE];

    srand(time(NULL));

    // Cadastra os alunos
    for (int i = 0; i < SIZE; i++)
    {
        char nome[50];
        printf("Insira o nome do aluno: ");
        scanf("%s", nome);
        strcpy(turma[i].nome, nome);

        int nota = rand() % 10;
        turma[i].nota = nota;
        printf("Nota do aluno: %d\n", nota);
    }

    printf("Media da turma: %.2lf\n", getMedia(turma));
    int pos_maior = getHigh(turma);
    printf("Nota mais alta: %s, com %.2lf\n", turma[pos_maior].nome, turma[pos_maior].nota);
    int pos_menor = getLow(turma);
    printf("Nota mais baixa: %s, com %.2lf\n", turma[pos_menor].nome, turma[pos_menor].nota);

    return 0;
}
