#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <conio.h>
FILE *arq_dados;
struct tipo_lista   // tem que criar o arquivo com o nome Controle de notas.
{   char nome[40];
    int n_usp;
    float matematica;
    float fisica;
    float quimica;
    struct tipo_lista *prox;
};
struct tipo_lista m;
struct tipo_lista *primeiro;
struct tipo_lista *ultimo;

void flvazia()
{
    struct tipo_lista *aux;
    aux = (struct tipo_lista*)malloc(sizeof(struct tipo_lista));
    primeiro = aux;
    ultimo = primeiro;
}

void insere(struct tipo_lista aluno)
{   int i;
    struct tipo_lista *aux;
    aux = (struct tipo_lista*)malloc(sizeof(struct tipo_lista));
    aux->n_usp = aluno.n_usp;
    aux->matematica = aluno.matematica;
    aux->fisica = aluno.fisica;
    aux->quimica = aluno.quimica;
    for(i=0;i<=40;i++)
    {aux->nome[i] = aluno.nome[i];}
    ultimo->prox = aux;
    ultimo = ultimo->prox;
    aux->prox = NULL;
}
void imprime()
{
    struct tipo_lista *aux;
    aux = primeiro->prox;
    while (aux != NULL)
        {
              printf("\n NOME: %s",aux->nome);
              printf("\n NUMERO USP:%d",aux->n_usp);
              printf("\n NOTA DE MATEMATICA: %.2f",aux->matematica);
              printf("\n NOTA DE FISICA: %.2f",aux->fisica);
              printf("\n NOTA DE QUIMICA: %.2f",aux->quimica);

              printf("\n \n ");
              aux = aux->prox;
        }
}

void pegar_do_arquivo()
    {
    arq_dados = fopen("Controle de notas","rb");
    if(arq_dados == NULL)
       {printf("erro ao abrir o arquivo! O ARQUIVO NAO EXISTE \n");}

    while(!feof(arq_dados))  // fread retorna 0 quando chegar no final do arquivo.
    {   fread(&m.nome,sizeof(m.nome),1,arq_dados);
        fread(&m.n_usp,sizeof(m.n_usp),1,arq_dados);
        fread(&m.matematica,sizeof(m.matematica),1,arq_dados);
        fread(&m.fisica,sizeof(m.fisica),1,arq_dados);
        fread(&m.quimica,sizeof(m.quimica),1,arq_dados);
        int i;
        struct tipo_lista *aux;
        aux = (struct tipo_lista*)malloc(sizeof(struct tipo_lista));
        for(i=0;i<=40;i++)
        {aux->nome[i] = m.nome[i];}
        aux->n_usp = m.n_usp;
        aux->matematica = m.matematica;
        aux->fisica = m.fisica;
        aux->quimica = m.quimica;
        ultimo->prox = aux;
        ultimo = ultimo->prox;
        aux->prox = NULL;
    }
     fclose(arq_dados);
     printf("Concluido. \n ");
    }

void remover(int nusp)
{
    struct tipo_lista *aux;
    struct tipo_lista *sentinela;
    int flag = 0;
    aux = primeiro->prox;
    sentinela = primeiro;
    while(aux!= NULL)
    {
        if(aux->n_usp == nusp)
        {
            printf("O aluno %d foi removido. \n ",nusp);
            sentinela->prox = aux->prox;
            aux = NULL;
            flag = 1;
        }
        else
            aux = aux->prox;
            sentinela = sentinela->prox;
    }
    if(flag == 0)
        printf("O aluno %d não existe na lista! \n ",nusp);
}

void alterar()
{   int numerousp;
    printf("Digite o numero usp do aluno que se deseja alterar: \n ");
    scanf("%d",&numerousp);
    struct tipo_lista ALUNO;
    struct tipo_lista *aux;
    struct tipo_lista *sentinela;
    int flag = 0;
    aux = primeiro->prox;
    sentinela = primeiro;
    while(aux!= NULL)
    {
        if(aux->n_usp == numerousp)
        {
            sentinela->prox = aux->prox;
            aux = NULL;
            flag = 1;
        }
        else
            aux = aux->prox;
            sentinela = sentinela->prox;
    }
    if(flag == 0)
        printf("O aluno %d não existe na lista! \n ",numerousp);

    fflush(stdin);
    printf("Digite o novo nome: \n");
    gets(ALUNO.nome);
    fflush(stdin);
    printf(" \n Entre Com o novo numero usp:");
    fflush(stdin);
    scanf("%d",&ALUNO.n_usp);
    fflush(stdin);
    printf("\n Digite a nova nota de matematica: \n ");
    fflush(stdin);
    scanf("%f",&ALUNO.matematica);
    fflush(stdin);
    printf("\n Digite a nova nota de fisica: \n");
    fflush(stdin);
    scanf("%f",&ALUNO.fisica);
    fflush(stdin);
    printf("\n Digite a nova nota de quimica: \n");
    fflush(stdin);
    scanf("%f",&ALUNO.quimica);
    fflush(stdin);
    insere(ALUNO);


}

void gravar_dados()
{   arq_dados = fopen("Controle de notas","ab");
    if(arq_dados == NULL)
    {
        printf("erro ao abrir o arquivo,ele pode nao existir!\n ");
    }

    struct tipo_lista *aux;
    aux = primeiro->prox;
    while (aux != NULL)
        {
              fwrite(&aux->nome,sizeof(aux->nome),1,arq_dados);
              fwrite(&aux->n_usp,sizeof(aux->n_usp),1,arq_dados);
              fwrite(&aux->matematica,sizeof(aux->matematica),1,arq_dados);
              fwrite(&aux->fisica,sizeof(aux->fisica),1,arq_dados);
              fwrite(&aux->quimica,sizeof(aux->quimica),1,arq_dados);

              aux = aux->prox;
        }


   printf("Concluido! \n ");
   fclose(arq_dados);
}
int main()
{   struct tipo_lista x;
    int opcao,n;
    flvazia();
    do
       {
        printf(" \n MENU:  \n");
        printf(" 0 - Pegar o conteudo do arquivo e passar pra lista \n ");
        printf("1 - Inserir \n ");
        printf("2 - Remover \n ");
        printf("3 - Alterar \n ");
        printf("4 - mostrar todos \n ");
        printf("5 - gravar lista no arquivo. \n ");
        printf("6 - sair \n ");
        printf("==>>");
        scanf("%d",&opcao);

        switch (opcao)
        {   case 0: pegar_do_arquivo();
            break;
            case 1:         fflush(stdin);
                            printf("Digite o nome: \n");
                            gets(x.nome);
                            fflush(stdin);
                            printf(" \n Entre com numero usp:");
                            fflush(stdin);
                            scanf("%d",&x.n_usp);
                            fflush(stdin);
                            printf("\n Digite a nota de matematica: \n ");
                            fflush(stdin);
                            scanf("%f",&x.matematica);
                            fflush(stdin);
                            printf("\n Digite a nota de fisica: \n");
                            fflush(stdin);
                            scanf("%f",&x.fisica);
                            fflush(stdin);
                            printf("\n Digite a nota de quimica: \n");
                            fflush(stdin);
                            scanf("%f",&x.quimica);
                            fflush(stdin);
                            insere(x);
            break;

            case 2:
                    printf("Digite o numero usp do aluno que se deseja remover: \n ");
                    scanf("%d",&n);
                    remover(n);
            break;

            case 3: alterar();
            break;

            case 4: system("cls");
                    imprime();

            break;
            case 5: gravar_dados();
            break;

            case 6: printf(" \n Saindo... \n ");
            break;

            default: printf("Opcao inválida. Tente novamente. ");


        }
        }while (opcao!=6);
    system ("pause");
    return 0;
}


