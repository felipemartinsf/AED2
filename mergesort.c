#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int *esq, int *dir, int ne, int nd) {
    int i = 0, j = 0, k = 0;
    while (i < ne && j < nd) {
        if (esq[i] <= dir[j]) {
            vetor[k] = esq[i];
            i++;
        } else {
            vetor[k] = dir[j];
            j++;
        }
        k++;
    }
    while (i < ne) {
        vetor[k] = esq[i];
        i++;
        k++;
    }
    while (j < nd) {
        vetor[k] = dir[j];
        j++;
        k++;
    }
}

void merge_sort(int *vetor, int tamVet, int n, int *maxn) {
    if (tamVet < 2) {
        return;
    }
    int mid = tamVet / 2;
    int esq[mid];
    int dir[tamVet - mid];
    for (int i = 0; i < mid; i++) {
        esq[i] = vetor[i];
    }
    for (int i = mid; i < tamVet; i++) {
        dir[i - mid] = vetor[i];
    }
    merge_sort(esq, mid, n+1, maxn);
    merge_sort(dir, tamVet - mid, n+1,maxn);
    merge(vetor, esq, dir, mid, tamVet - mid);
    if (n > *maxn) {
        *maxn = n;
    }
}

int main() {
    int *vetor, tamVet, i, n, maxn=0;
    scanf("%d", &tamVet);
    vetor = (int *)malloc(sizeof(int) * tamVet);
  for (i = 0; i < tamVet; i++) {
    scanf("%d", &vetor[i]);
  }
  
    merge_sort(vetor, tamVet,1,&maxn);
    for (int i = 0; i < tamVet; i++) {
        printf("%d ", vetor[i]);
    }
  printf("\n %d", maxn);
  free(vetor);
    return 0;
}