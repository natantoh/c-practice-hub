#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main()
{    int i,n;
    int  m[100];
     char c[30];
    char linha[30];
    FILE *arq_in;
    arq_in = fopen("frase.txt", "r");

    if(arq_in == NULL)
    {
        printf("o arquivo nao existe.");
    }
    i=0;
    fscanf(arq_in,"%s",linha);
    while(!feof(arq_in))
    {c[i] = fgetc(arq_in);
    printf("%c",c[i]);
     i++;
    }
     n = i-3;
    fclose(arq_in);
    arq_in = fopen("frase.txt" ,"r");
     if(arq_in == NULL)
    {
        printf("o arquivo nao existe.");
    }
    for (i=0;i<=n;i++)
    {m[i] = c[i];
    printf("\n \n %c \n",linha[m[i]]);
    }
fclose(arq_in);



    system ("pause");
    return 0;
}
