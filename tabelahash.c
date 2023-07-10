#include <stdio.h>
#include <stdlib.h>

void inicializar(int *born, int tam) {
  int i;
  for (i = 0; i < tam; i++) {
    born[i] = -27;
  }
}

void insercao(int *vet, int tam, int *born) {
  int r1, r2, i, j;
  for (i = 0; i < tam; i++) {
    r1 = vet[i] % tam;
    r2 = (vet[i] % (tam - 1)) + 1;
    if (born[r1] == -27) {
      born[r1] = vet[i];
    } else {
      for (j = 0; j < tam; j++) {
        if (born[(r1 + j * r2) % tam] == -27) {
          born[(r1 + j * r2) % tam] = vet[i];
          break;
        }
      }
    }
  }
}

int remocao(int *born, int n, int tam) {
  int r1, r2, i, j,cont=0;

  r1 = n % tam;
  r2 = (n % (tam - 1)) + 1;

  for (j = 0; j < tam; j++) {
    if (born[(r1 + j * r2) % tam] == n) {
      born[(r1 + j * r2) % tam] = -30;
      cont++;
    }
  }
  return cont;
}

int main() {
  int *isabella, schone, i, n, *born, f;
  scanf("%d", &schone);
  born = (int *)malloc(sizeof(int) * schone);
  isabella = (int *)malloc(sizeof(int) * schone);
  inicializar(born, schone);
  inicializar(isabella, schone);
  for (i = 0; i < schone+1; i++) {
    scanf("%d", &isabella[i]);
    if (isabella[i] == -1) {
      isabella[i] = -27;
      break;
    }
  }
  scanf("%d", &n);
  insercao(isabella, schone, born);
  f = remocao(born, n, schone);
  if (f != 0) {
    for (i = 0; i < schone; i++) {
      if (born[i] != -30 && born[i] != -27)
        printf("%d ", born[i]);
      else if (born[i] == -30)
        printf("D ");
      else if (born[i] == -27)
        printf("\\");
    }
  } else {
    printf("Valor nao encontrado \n");
    for (i = 0; i < schone; i++) {
      if (born[i] != -30 && born[i] != -27)
        printf("%d ", born[i]);
      else if (born[i] == -30)
        printf("D ");
      else if (born[i] == -27)
        printf("\\ ");
    }
  }
}
