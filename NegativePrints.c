#include <stdio.h>
#include <stdlib.h>
void limpar_entrada() {
char c;
while ((c = getchar()) != '\n' && c != EOF) {}
}
int main()
{
    int i, ret, iN;
    double N, vN;

    printf("Informe a quantidade de entradas: ");
    ret = scanf("%lf", &N);

    while (ret == 0 || N != (int)N || N < 0 || N > 10)
    {
        printf("Dado(s) Invalido(s).\n");
        printf("Tente novamente: ");
        limpar_entrada();
        ret = scanf("%lf", &N);
    }

    iN = (int)N;
    int x[iN];
    for (i=0;i<iN;i++)
    {
        printf("Digite um numero inteiro: ");
        ret = scanf("%lf", &vN);

    while (ret == 0 || vN != (int)vN)
    {
            printf("Dado(s) Invalido(s).\n");
            printf("Tente novamente: ");
            limpar_entrada();
            ret = scanf("%lf", &vN);
        }
        x[i] = vN;
    }

    printf("\nNUMEROS NEGATIVOS:\n");
    for (i=0;i<iN;i++)
    {
        if (x[i] < 0)
        {
            printf("%d\n", x[i]);
        }
    }

    return 0;
}
