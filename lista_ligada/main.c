#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
FILE *arq_dados;
struct tipo_lista
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
{   struct tipo_lista *aux;
    aux = (struct tipo_lista*)malloc(sizeof(struct tipo_lista));
    aux->n_usp = aluno.n_usp;
    aux->matematica = aluno.matematica;
    aux->fisica = aluno.fisica;
    aux->quimica = aluno.quimica;
    aux->nome[40] = aluno.nome[40];
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
              printf("\n NOTA DE QUIMICA: %.2f",aux->quimica);
              printf("\n NOTA DE FISICA: %.2f",aux->fisica);

              aux = aux->prox;
        }
}

void inserir_na_lista()
    {
    arq_dados = fopen("Controle de notas","rb");
    if(arq_dados == NULL)
       {printf("erro ao abrir o arquivo \n");}

    while(fread(&m,sizeof(m),1,arq_dados))  // fread retorna 0 quando chegar no final do arquivo.
    {   struct tipo_lista *aux;
        aux = (struct tipo_lista*)malloc(sizeof(struct tipo_lista));
        aux->n_usp = m.n_usp;
        aux->matematica = m.matematica;
        aux->fisica = m.fisica;
        aux->quimica = m.quimica;
        aux->nome[40] = m.nome;
        ultimo->prox = aux;
        ultimo = ultimo->prox;
        aux->prox = NULL;

        printf("NOME: %s \n ",m.nome);
        printf("NUMERO USP: %d \n ",m.n_usp);
        printf("NOTA DE MATEMATICA: %.2lf \n",m.matematica);
        printf("NOTA DE FISICA: %.2lf \n ",m.fisica);
        printf("NOTA DE QUIMICA: %.2lf \n ",m.quimica);
        printf("\n \n \n ------------------------------------------------------------------ \n \n \n ");
    }

    }

int main()
{   struct tipo_lista x;
    int opcao;
    flvazia();
    do
       {
        printf(" \n MENU: \n");
        printf(" 0 - Pegar o conteudo do arquivo e passar pra lista \n ");
        printf("1 - Inserir \n ");
        printf("2 - Remover \n ");
        printf("3 - Alterar \n ");
        printf("4 - mostrar todos \n ");
        printf("5 - sair \n ");
        scanf("%d",&opcao);

        switch (opcao)
        {   case 0: inserir_na_lista();
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
            break;

            case 3:
            break;

            case 4: imprime();
            break;

            case 5: printf(" \n Saindo... \n ");
            break;

            default: printf("Opcao inválida. Tente novamente. ");


        }
        }while (opcao!=5);
    system ("pause");
    return 0;
}


