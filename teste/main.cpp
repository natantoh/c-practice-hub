#include <iostream>

using namespace std;

 int funcao(int n)
 {   n=2;
     return n;
 }

void main()
{  int n;
    printf("Digite um numero: \n \n ");
    scanf("%d",&n);
    printf("O numero ser: %d \n \n ",funcao(n));
}
