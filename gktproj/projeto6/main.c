#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int main()
{
    int n_usp,idade;
    char nome[40];
    long tamanho;
    FILE *arq_in;
    arq_in = fopen("texto","wb");
    if(arq_in != NULL)
    {   printf("Digite um Nome: \n");
        gets(nome);
        fwrite(&nome,sizeof(nome),1,arq_in);
        printf("Digite o seu numero usp: \n");
        scanf("%d",&n_usp);
        fwrite(&n_usp,sizeof(n_usp),1,arq_in);
        printf("Digite sua idade: \n");
        scanf("%d",&idade);
        fwrite(&idade,sizeof(idade),1,arq_in);
        fclose(arq_in);
        arq_in = fopen("texto","rb");

        fread(&nome,sizeof(nome),1,arq_in);
        printf("%s \n ",nome);
        fread(&n_usp,sizeof(n_usp),1,arq_in);
        printf("%d \n ",n_usp);
        fread(&idade,sizeof(idade),1,arq_in);
        printf("%d \n",idade);
        fseek(arq_in,(long)0,SEEK_END);
        tamanho = ftell(arq_in);
        printf(" TAMANHO: %ld",tamanho);

        //fseek(arq_in,0,SEEK_END);
        //tamanho = ftell(arq_in);

       // printf("%ld",tamanho);
























    }
    else
    {
        printf("arquivo não existe \n");
    }
    return 0;
}
