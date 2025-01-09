#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <windows.h>
#include <conio.h>

struct tipo_lista
{   char nome[30];
    int idade;
    struct tipo_lista *prox;
};
typedef struct tipo_lista celula;

celula *primeiro,*domeio,*ultima;

void inserir(celula **p) //p = &inicial
{   celula *nova;
    celula *aux;
    aux = (celula*)malloc(sizeof(celula));

    fflush(stdin);
    printf("Digite o nome: \n");
    gets(aux->nome);
    fflush(stdin);
    printf(" \n Digite sua idade: \n ");
    fflush(stdin);
    scanf("%d",&aux->idade);
    fflush(stdin);

    aux = *p;
    nova = aux->prox;
    nova->prox = NULL;


}

void imprime(celula *p)
{

while(p!=NULL)
{
              printf("\n NOME: %s",p->nome);
              printf("\n NUMERO USP:%d",p->idade);

              printf("\n \n ");
              p = p->prox;
}
}
int main(void)
{
    celula *inicial = NULL;

    inserir(&inicial);
    imprime(&inicial);
    return 0;
}
