#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void limpar_entrada()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int main()
{
    int i, j, iN, iIdades, ret, tString, teste, menores16;
    double N, dIdades, sAlt, mAlt, pMenores;

    printf("Informe o numero de pessoas: ");
    ret = scanf("%lf", &N);

    while (ret == 0 || N!= (int)N || N < 0)
    {
        printf("DADO(S) INVALIDO(S)!");
        printf("Tente novamente: ");
        limpar_entrada();
        ret = scanf("%lf", &N);
    }
    iN = (int)N;
    char nomes[iN][51];
    int idades[iN];
    double alturas[iN];
    for(i=0; i<iN; i++)
    {
        printf("Dados da %da pessoa:\n", i+1);
        printf("Nome: ");
        scanf(" %50[^\n]", nomes[i]);
        tString = strlen(nomes[i]);

        teste  = 0;
        for (j=0; j < tString; j++)
        {
            if (isdigit(nomes[i][j]))
            {
                teste = 1;
                break;
            }
        }
        while (teste == 1)
        {
            teste = 0;
            printf("DADO(S) INVALIDO(S)!\n");
            printf("Tente novamente: ");
            scanf(" %50[^\n]", nomes[i]);
            tString = strlen(nomes[i]);
            for (j=0; j<tString; j++)
            {
                if (isdigit(nomes[i]))
                {
                    teste = 1;
                    break;
                }
            }
        }

        printf("Idade: ");
        ret = scanf("%lf", &dIdades);
        while (ret == 0 || dIdades!= (int)dIdades || dIdades < 0)
        {
            printf("DADO(S) INVALIDO(S)!");
            printf("Tente novamente: ");
            limpar_entrada();
            ret = scanf("%lf", &dIdades);
        }
        iIdades = (int)dIdades;
        idades[i] = iIdades;

        printf("Altura: ");
        ret = scanf("%lf", &alturas[i]);
        while (ret == 0 || alturas[i] < 0)
        {
            printf("DADO(S) INVALIDO(S)!");
            printf("Tente novamente: ");
            ret = scanf("%lf", &alturas[i]);
        }
    }

    printf("\nAltura media: ");
    sAlt = 0;
    for (i=0; i<iN;i++)
    {
        sAlt = sAlt + alturas[i];
    }
    mAlt = sAlt/N;
    printf("%.2lf", mAlt);

    printf("\nMenores de 16 anos: ");
    menores16 = 0;
    for (i=0;i<iN;i++)
    {
        if (idades[i] < 16)
        {
            menores16 = menores16 + 1;
        }
    }
    pMenores = (100 * menores16)/N;
    printf("%.2lf %%", pMenores);
    for (i=0;i<iN;i++)
    {
        if (idades[i] < 16)
        {
            printf("\n%s", nomes[i]);
        }
    }

    return 0;
}
