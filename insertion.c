// FELIPE MARTINS FRANCISCO 163714
#include <stdio.h>
#include <stdlib.h>

void organiza(int tam, int *vetd) {
  int i, j, tmp;

  for (i = 1; i < tam; i++) {
    tmp = vetd[i];
    for (j = i - 1; j >= 0 && tmp < vetd[j]; j--) {
      vetd[j + 1] = vetd[j];
    }
    vetd[j + 1] = tmp;
  }
}

int verifica(int *micro, int* doses, int tam) {
  for (int i = 0; i < tam; i++)
    if (micro[i] >= doses[i])
      return 0;
  return 1;
}

int main(void) {
  int *vetmicro, *vetdoses;
  int tamVet, i, j, tmp,resp;
  scanf("%d", &tamVet);

  vetmicro = (int *)malloc(sizeof(int) * tamVet);
  for (i = 0; i < tamVet; i++) {
    scanf("%d", &vetmicro[i]);
  }
  vetdoses = (int *)malloc(sizeof(int) * tamVet);
  for (i = 0; i < tamVet; i++) {
    scanf("%d", &vetdoses[i]);
  }

  organiza(tamVet, vetmicro);
  organiza(tamVet, vetdoses);
  
  if (verifica(vetmicro, vetdoses, tamVet))
    printf("sim");
  else
    printf("nao");
  return 0;
}
