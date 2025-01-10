#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insercaoDireta(int numeros[], int N)
{
int ivet, numeroAInserir, isubv;
// cada passo considera que o array à esquerda de i está ordenado
for (ivet=1; ivet < N; ivet++) // percorre vetor principal
{
// tenta inserir mais um número na porção inicial do array que
// já está ordenado empurrando para a direita todos os elementos
// maiores do que numeroAInserir
// número que será encaixado no vetor ordenado
numeroAInserir = numeros[ivet];
isubv = ivet;
while ((isubv > 0) && (numeros [isubv -1] > numeroAInserir))
// desloca vetor ordenado até encontrar posição para o número a inserir
{
numeros[isubv] = numeros[isubv - 1];
isubv--;
}
numeros[isubv] = numeroAInserir;
}
}


int main()
{
int tam, i;
clock_t init, end;
int *vet;

   // aloca vetor com tamanhos comecando em 500 e incrementando de 200 em 200
   for (tam = 1000; NULL != (vet = malloc(tam * sizeof(int) )) ; tam *= 1.1 )
   {
      // preenche  vetor com numeros aleatorios
      printf("Tamanho do vetor: %d \n", tam );
      for (i = 0; i < tam; i++)
      {
         vet[i] = rand();

      }
       insercaoDireta(vet, tam);
      // conta o tempo decorrido em micro segundos

      init = clock();

      insercaoDireta(vet, tam);
      end = clock();

      end = (end - init) / (CLOCKS_PER_SEC / 1000);

      // mostra o tempo decorrido
      printf("\tTempo decorrido (1/1000 s): %ld\n", end);
/*      for (i = 0; i < tam; i++)
      {
         printf("%d ", vet[i]);
      }
      printf("\n");
*/
    // libera o vetor
     free(vet);
   }
   return 0;
}

