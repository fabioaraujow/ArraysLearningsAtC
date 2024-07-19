#include <stdio.h>
#include <stdlib.h>
void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF){}
}
int ler_positivo_inteiro_positivo()
{
    double dN;
    int retorno;
    do
    {
        retorno = scanf("%lf", &dN);
        if (retorno ==0 || dN != (int)dN || dN < 0)
        {
            printf("Dado(s) invalido(s)!");
            printf("Tente Novamente: ");
            limpar_entrada();
            retorno = scanf("%lf", &dN);
        }
    } while (retorno ==0 || dN != (int)dN || dN < 0);
    return (int)dN;
}
double ler_vetor_numerico_double()
{
    double dVet;
    int retorno;
    do
    {
        limpar_entrada();
        retorno = scanf("%lf", &dVet);
        if (retorno == 0)
        {
            printf("Dado(s) invalido(s)!");
            printf("Tente Novamente: ");
            limpar_entrada();
            retorno = scanf("%lf", &dVet);
        }
    }while (retorno == 0);
    return (double)dVet;
}
int main()
{
    int M, N, i, j;

    printf("Informe a quantidade de linhas da matriz: ");
    M = ler_positivo_inteiro_positivo();

    printf("Informe a quantidade de colunas da matriz: ");
    N = ler_positivo_inteiro_positivo();

    double matrix[M][N], soma, somaV[M];

    for (i = 0; i < M; i++)
    {
        printf("Digite os elementos da %da linha:\n", i+1);
        soma = 0;
        for (j = 0; j < N; j++)
        {
            matrix[i][j] = ler_vetor_numerico_double();
            soma = soma + matrix[i][j];
        }
        somaV[i] = soma;
    }

    printf("VETOR GERADO:\n");

    for (i = 0; i < M; i++)
    {
        printf("%.1lf\n", somaV[i]);
    }

    return 0;
}
