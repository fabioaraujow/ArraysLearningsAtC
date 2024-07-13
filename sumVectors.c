#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main()
{
    int iN, i, ret;
    double N, x, soma, media;

    printf("Informe a quantidade de dados a sererm inseridos: ");
    ret = scanf("%lf", &N);

    while (ret == 0 || N != (int)N || N < 0 || N > 100)
    {
        printf("DADO(S) INVALIDO(S).\n");
        printf("Tente novamente: ");
        limpar_entrada();
        ret = scanf("%lf", &N);
    }

    iN = (int)N;
    double vet[iN];

    for (i=0;i<iN;i++)
    {
        printf("Insira um numero: ");
        ret = scanf("%lf", &x);
        while (ret == 0)
        {
            printf("DADO(S) INVALIDO(S).\n");
            printf("Tente novamente: ");
            limpar_entrada();
            ret = scanf("%lf", &x);
        }
        vet[i] = x;
    }

    soma = 0;
    printf("Valores =");
    for (i=0;i<iN;i++)
    {
        printf(" %.1lf ", vet[i]);
        soma = soma + vet[i];
    }
    printf("\nSoma = %.2lf\n", soma);
    media = soma/N;
    printf("Media = %.2lf", media);

    return 0;
}
