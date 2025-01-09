#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main()
{

    const int n = 200;
   char linha_in[n], linha_out[n];
    int num_linha = 0;
   FILE *arq_in,*arq_out;  // os dois textos deverão ser criados com os nomes texto1 e texto2 em formato txt na pasta do projeto
   arq_in=fopen("texto1.txt","r");
   arq_out=fopen("texto2.txt","r");

   while (!feof(arq_in) && !feof(arq_out))
   {
       num_linha ++;
       fgets(linha_in, n, arq_in);
       fgets(linha_out, n, arq_out);
       if (strcmp(linha_in, linha_out) != 0) {
            printf("Diferença : %d. %s <=> %d. %s\n", num_linha, linha_in, num_linha, linha_out);
       }
   }
fclose(arq_in);
fclose(arq_out);
    return 0;
}
