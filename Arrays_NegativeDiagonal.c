#include <stdio.h>
#include <stdlib.h>

void limpar_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int ler_inteiro_positivo()
{
    double dN;
    int retorno;
    do {
        retorno = scanf("%lf", &dN);
        if (retorno == 0 || dN != (int)dN || dN < 0) {
            printf("Dado(s) Invalido(s)!\n");
            printf("Tente Novamente: ");
            limpar_entrada();
        }
    } while (retorno == 0 || dN != (int)dN || dN < 0);
    return (int)dN;
}
int ler_inteiro()
{
    double dNumero;
    int retorno;
    do {
        retorno = scanf("%lf", &dNumero);
        if (retorno == 0 || dNumero != (int)dNumero) {
            printf("Dado(s) Invalido(s)!\n");
            printf("Tente Novamente: ");
            limpar_entrada();
        }
    } while (retorno == 0 || dNumero != (int)dNumero);
    return (int)dNumero;
}

int main()
{
    int N, M, i, j;

    printf("Informe a ordem da matriz: ");
    N = ler_inteiro_positivo();
    M = N;
    int matrix[M][N];

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("Elemento [%d, %d]: ", i, j);
            matrix[i][j] = ler_inteiro();
        }
    }

    printf("\nDiagonal Principal:\n");
    for (i = 0; i < M; i++)
    {
        printf("%d ", matrix[i][i]);
    }

    int soma = 0;

    printf("\nQuantidade de Negativos = ");
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (matrix[i][j] < 0)
            {
                soma++;
            }
        }
    }
    printf("%d", soma);

    return 0;
}
