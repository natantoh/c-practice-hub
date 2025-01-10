#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main()
{   int cont_linha=0;
    char linha[200],nome[40];
    FILE *arq_x;
    arq_x = fopen("texto.txt","r"); // tem que criar o arquivo com um texto qualquer com o nome "texto".
    if ((fopen("texto.txt","r"))== NULL)
        printf("um erro ocorreu. o arquivo nao existe.");
    else
    {
        printf("digite uma palavra a pesquisar: ");
        gets(nome);

        while(!feof(arq_x))
        {   cont_linha++;
            fgets(linha,200,arq_x);
            strstr(linha,nome);
            if(strstr(linha,nome)!=NULL)
            {
                printf("%d: %s",cont_linha,linha);
            }

        }
    }
    fclose(arq_x);
    return 0;
}

