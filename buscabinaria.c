// FELIPE MARTINS FRANCISCO 163714
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int *vet, int valor, int ini, int fim, int *cont) { // funcao que faz a busca binaria
  int mid = (ini + fim) / 2;
  if (ini > fim)
    return -1;
  if (valor == vet[mid])
    return mid;
  if (valor > vet[mid]) {
        *cont = *cont + 1;
    return binarySearch(vet, valor, mid + 1, fim, cont);
  }
   else if (valor < vet[mid]) {
           *cont = *cont + 1;
    return binarySearch(vet, valor, ini, mid - 1, cont);
  }
}

int main() {
  int tamVet, i, valor,f,d;
  int *vet, cont;
  scanf("%d", &tamVet);
  vet = (int *)malloc(sizeof(int) * tamVet);
  for (i = 0; i < tamVet; i++) {
    scanf("%d", &vet[i]);
  }
  scanf("%d", &valor);
  if (binarySearch(vet, valor, 0, tamVet, &cont)< 0)
    printf("%d nao foi encontrado", valor);
  else
    printf("%d", cont);

  free(vet);
  return 0;
}  
