#include <stdio.h>
#include <stdlib.h>
void limpar_entrada()
{
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
}
int main()
{
    int i, N, retorno;
    double dN, menorAltura, maiorAltura;

    printf("Informe a quantidade de pessoas: ");
    retorno = scanf("%lf", &dN);

    while (retorno == 0 || dN != (int)dN || dN < 0 || dN > 10)
    {
        printf("Dados invalidos!\n");
        printf("Informe a quantidade de pessoas: ");
        limpar_entrada();
        retorno = scanf("%lf", &dN);
    }

    N = (int)dN;
    double alturas[N];
    char genero[N];

    for (i=0; i<N; i++)
    {
        printf("Altura da %da pessoa: ", i+1);
        retorno = scanf("%lf", &alturas[i]);
        while (retorno == 0 || alturas[i] < 0)
        {
            printf("Dados invalidos!\n");
            printf("Altura da %da pessoa: ", i+1);
            limpar_entrada();
            retorno = scanf("%lf", &dN);
        }
        printf("Genero da %da pessoa: ", i+1);
        limpar_entrada();
        scanf("%c", &genero[i]);
        while (genero[i] != 'M' && genero[i] != 'm' && genero[i] != 'F' && genero[i] != 'f')
        {
            printf("Dados invalidos!\n");
            printf("Genero da %da pessoa: ", i+1);
            limpar_entrada();
            scanf("%c", &genero[i]);
        }
    }
    printf("\nMenor Altura = ");
    menorAltura = alturas[0];
    for (i=1;i<N;i++)
    {
        if (menorAltura > alturas[i])
        {
            menorAltura = alturas[i];
        }
    }
    printf("%.2lf", menorAltura);

    printf("\nMaior Altura = ");
    maiorAltura = alturas[0];
    for (i=1;i<N;i++)
    {
        if (maiorAltura < alturas[i])
        {
            maiorAltura = alturas[i];
        }
    }
    printf("%.2lf", maiorAltura);

    printf("\nMedia das Alturas das Mulheres = ");

    double somaAlt, altMedM;
    int qntM;
    somaAlt = 0;
    qntM = 0;

    for (i=0;i<N;i++)
    {
        if (genero[i] == 'M' || genero[i] == 'm')
        {
            somaAlt = somaAlt + alturas[i];
            qntM = qntM + 1;
        }
    }
    altMedM = somaAlt / qntM;
    printf("%.2lf", altMedM);

    printf("\nNumero de Homens = ");

    int qntH;
    qntH = 0;

    for (i=0;i<N;i++)
    {
        if (genero[i] == 'M' || genero[i] == 'm')
        {
            qntH = qntH + 1;
        }
    }
    printf("%d\n", qntH);

    return 0;
}
