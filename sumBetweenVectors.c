#include <stdio.h>
#include <stdlib.h>
void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int main()
{
    double dN;
    int N, retorno;

    printf("Informa a quantidade de valores dos vetores: ");
    retorno = scanf("%lf", &dN);

    while (retorno == 0 || dN != (int)dN || dN < 0)
    {
        printf("Dado(s) invalido(s)!\n");
        printf("Tente Novamente: ");
        limpar_entrada();
        retorno = scanf("%lf", &dN);
    }

    N = (int)dN;
    double vetA[N], vetB[N];

    printf("\nDigite os valores do vetor A:\n");
    for (int i = 0; i<N; i++)
    {
        retorno = scanf("%lf", &vetA[i]);
        while (retorno == 0)
        {
            printf("Dado(s) invalido(s)!\n");
            printf("Tente Novamente:\n");
            limpar_entrada();
            retorno = scanf("%lf", &vetA[i]);
        }
    }

    printf("\nDigite os valores do vetor B:\n");
    for (int i = 0; i<N; i++)
    {
        retorno = scanf("%lf", &vetB[i]);
        while (retorno == 0)
        {
            printf("Dado(s) invalido(s)!\n");
            printf("Tente Novamente:\n");
            limpar_entrada();
            retorno = scanf("%lf", &vetB[i]);
        }
    }

    double vetResult[N];

    printf("\nVetor Resultante:\n");
    for (int i = 0; i<N; i++)
    {
        vetResult[i] = vetA[i] + vetB[i];
        printf("%.1lf\n", vetResult[i]);
    }

    return 0;
}
