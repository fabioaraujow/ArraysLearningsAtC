#include <stdio.h>
#include <stdlib.h>
void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int main()
{
    int i, iN, iNum,retorno, cont;
    double N, num;

    printf("Informe a quantidade de dados que serao inseridos: ");
    retorno = scanf("%lf", &N);

    while (retorno == 0 || N != (int)N || N < 0)
    {
        printf("Dado(s) Invalido(s)!");
        printf("Tente novamente: ");
        limpar_entrada();
        retorno = scanf("%lf", &N);
    }

    iN = (int)N;
    int vetNum[iN];

    for(i=0;i<iN;i++)
    {
        printf("Digite um numero: ");
        retorno = scanf("%lf", &num);
        while (retorno == 0 || num != (int)num)
        {
            printf("Dado(s) Invalido(s)!");
            printf("Tente novamente: ");
            limpar_entrada();
            retorno = scanf("%lf", &num);
        }
        iNum = (int)num;
        vetNum[i] = iNum;
    }

    printf("\n");
    printf("Numeros pares: \n");
    cont = 0;
    for(i=0;i<iN;i++)
    {
        if (vetNum[i] % 2 == 0)
        {
            printf("%d ", vetNum[i]);
            cont = cont + 1;
        }
    }
    printf("\n\nQuantidade de Pares = %d \n", cont);

    return 0;
}
