#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void limpar_entrada()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
void checar_inteiro_positivo_sem_caracteres (double *dN)
{
    int retorno;
    while (retorno == 0 || *dN != (int)*dN || *dN <0)
    {
        printf("Dados invalidos!\n");
        printf("Tente Novamente: ");
        limpar_entrada();
        retorno = scanf("%lf", dN);
    }
}
void checar_caracteres(char mercadorias[][31], int i)
{
    int tString, j, teste;
    tString = strlen(mercadorias[i]);
    teste = 0;
    for (j = 0; j < tString; j++)
    {
        if (isdigit(mercadorias[i][j]))
        {
            teste = 1;
            break;
        }
    }
    while (teste == 1)
    {
        teste = 0;
        printf("Dado(s) Invalido(s)!\n");
        printf("Tente Novamente: ");
        limpar_entrada();
        scanf("%30[^\n]", mercadorias[i]);
        tString = strlen(mercadorias[i]);
        for (j = 0; j < tString; j++)
        {
            if (isdigit(mercadorias[i][j]))
            {
                teste = 1;
                break;
            }
        }
    }
}
int main()
{
    int retorno, i, N;
    double dN;

    printf("Informe a quantidade de produtos: ");
    scanf("%lf", &dN);
    checar_inteiro_positivo_sem_caracteres(&dN);

    N = (int)dN;

    char mercadorias[N][31];
    double pCompra[N], pVenda[N];

    for (i = 0; i < N; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Nome: ");
        limpar_entrada();
        scanf(" %30[^\n]", mercadorias[i]);
        checar_caracteres(mercadorias, i);

        printf("Preco de Compra: ");
        limpar_entrada();
        retorno = scanf("%lf", &pCompra[i]);
        while (retorno == 0 || pCompra[i] < 0)
        {
            printf("Dado(s) Invalido(s)!\n");
            printf("Tente Novamente: ");
            limpar_entrada();
            retorno = scanf("%lf", &pCompra[i]);
        }

        printf("Preco de Venda: ");
        limpar_entrada();
        retorno = scanf("%lf", &pVenda[i]);
        while (retorno == 0 || pVenda[i] < 0)
        {
            printf("Dado(s) Invalido(s)!\n");
            printf("Tente Novamente: ");
            limpar_entrada();
            retorno = scanf("%lf", &pVenda[i]);
        }
    }

    printf("\nRELATORIO:\n");

    double percentLucro;
    int menor10 = 0, entre10e20 = 0, acima20 = 0;

    for (i = 0; i < N; i++)
    {
        percentLucro = ((pVenda[i] - pCompra[i])/pCompra[i])*100;

        if (percentLucro < 10)
        {
            menor10++;
        }
        else if (percentLucro >= 10 && percentLucro <= 20)
        {
            entre10e20++;
        }
        else if (percentLucro > 20)
        {
            acima20++;
        }
    }

    printf("Lucro abaixo de 10%%: %d\n", menor10);
    printf("Produtos abaixo de 10%%:\n");
    for (i = 0; i < N; i++)
    {
        percentLucro = ((pVenda[i] - pCompra[i])/pCompra[i])*100;
        if (percentLucro < 10)
        {
            printf("%s\n", mercadorias[i]);
        }
    }
    printf("Lucro entre 10%% e 20%%: %d\n", entre10e20);
    printf("Produtos entre 10%% e 20%%:\n");
    for (i = 0; i < N; i++)
    {
        percentLucro = ((pVenda[i] - pCompra[i])/pCompra[i])*100;
        if (percentLucro >= 10 && percentLucro <= 20)
        {
            printf("%s\n", mercadorias[i]);
        }
    }
    printf("Lucro acima de 20%%: %d\n", acima20);
    printf("Produtos acima de 20%%:\n");
    for (i = 0; i < N; i++)
    {
        percentLucro = ((pVenda[i] - pCompra[i])/pCompra[i])*100;
        if (percentLucro > 20)
        {
            printf("%s\n", mercadorias[i]);
        }
    }

    double totalCompra = 0;

    for (i = 0; i < N; i++)
    {
        totalCompra = totalCompra + pCompra[i];
    }
    printf("Valor Total de Compras: %.2lf\n", totalCompra);

    double totalVenda = 0;

    for (i = 0; i < N; i++)
    {
        totalVenda = totalVenda + pVenda[i];
    }
    printf("Valor Total de Vendas: %.2lf\n", totalVenda);

    double lucroTotal;
    lucroTotal = totalVenda - totalCompra;

    printf("Lucro Total: %.2lf", lucroTotal);

    return 0;
}
