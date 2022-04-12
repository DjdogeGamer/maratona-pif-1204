#include <stdio.h>

// Funcao que verifica se o caracter passado é x ou o
void verifyChar(char option)
{
    char caracter;
    do
    {
        scanf("%c", &caracter);
        getchar();
        if (caracter != option)
        {
            printf("Informe um caracter valido\n");
        }
    } while (caracter != option);
}

// Printa o board em seu estado atual
void printBoard(int tam, char matriz[][tam])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Repete até a posicao informada ser valida
void setPosition(int tam, char board[][tam], char option)
{
    int verifier = 0;
    do
    {
        int x, y;
        printf("Informe a posicao da jogada: \n");
        scanf("%d %d", &x, &y);
        getchar();
        if (board[x][y] == '_')
        {
            board[x][y] = option;
            verifier = 1;
        }
        else
        {
            printf("Insira uma posicao valida\n");
        }
    } while (verifier == 0);
}

// Verifica se ainda ha algum espaco vazio na matriz
int isFull(int tam, char board[][tam])
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (board[i][j] == '_')
            {
                return 0;
            }
        }
    }
    return 1;
}

// Compara se ha algum caso de vitoria
int verifyWin(int tam, char board[][tam], char option)
{
    // Diagonal principal
    if (board[0][0] == option && board[1][1] == option && board[2][2] == option)
    {
        return 1;
    }
    // Diagonal secundaria
    else if (board[0][2] == option && board[1][1] == option && board[2][0] == option)
    {
        return 1;
    }
    // Horizontal e vertical
    else
    {
        int sum_x = 0;
        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (board[i][j] == option)
                {
                    sum_x += 1;
                }
                if (sum_x == 3)
                {
                    return 1;
                }
            }
            sum_x = 0;
        }

        int sum_y = 0;
        for (int i = 0; i < tam; i++)
        {
            for (int j = 0; j < tam; j++)
            {
                if (board[j][i] == option)
                {
                    sum_y += 1;
                }
                if (sum_y == 3)
                {
                    return 1;
                }
            }
            sum_y = 0;
        }
    }
    return 0;
}

int main()
{
    char board[3][3];

    // Preenche board
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '_';
        }
    }

    printBoard(3, board);

    // Vai executar enquanto o tabuleiro nao estiver cheio
    do
    {
        verifyChar('x');
        setPosition(3, board, 'x');
        printBoard(3, board);
        if (verifyWin(3, board, 'x') == 1)
        {
            printf("O jogador X venceu");
            break;
        }

        verifyChar('o');
        setPosition(3, board, 'o');
        printBoard(3, board);
        if (verifyWin(3, board, 'o') == 1)
        {
            printf("O jogador O venceu");
            break;
        }

        if (isFull(3, board) == 1)
        {
            printf("Deu empate\n");
        }

    } while (isFull(3, board) == 0);

    return 0;
}
