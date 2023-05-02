#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void swap(char *palavras[], int i, int j) {
    char *temp = palavras[i];
    palavras[i] = palavras[j];
    palavras[j] = temp;
}
 
void heapify(char *palavras[], int tamanho, int indice, int ordem[]) {
    int maior = indice; 
    int esquerda = 2 * indice + 1; 
    int direita = 2 * indice + 2; 
  
if (esquerda < tamanho) {
    if (ordem[palavras[esquerda][0]] == ordem[palavras[maior][0]]) {
        if (strlen(palavras[esquerda]) > 1 && strlen(palavras[maior]) > 1) {
            if (ordem[palavras[esquerda][1]] == ordem[palavras[maior][1]]) {
                if (strlen(palavras[esquerda]) > 2 && strlen(palavras[maior]) > 2 && ordem[palavras[esquerda][2]] > ordem[palavras[maior][2]]) {
                    maior = esquerda;
                }
            } else if (ordem[palavras[esquerda][1]] > ordem[palavras[maior][1]]) {
                maior = esquerda;
            }
        }
    } else if (ordem[palavras[esquerda][0]] > ordem[palavras[maior][0]]) {
        maior = esquerda;
    }
}
 
if (direita < tamanho) {
    if (ordem[palavras[direita][0]] == ordem[palavras[maior][0]]) {
        if (strlen(palavras[direita]) > 1 && strlen(palavras[maior]) > 1) {
            if (ordem[palavras[direita][1]] == ordem[palavras[maior][1]]) {
                if (strlen(palavras[direita]) > 2 && strlen(palavras[maior]) > 2 && ordem[palavras[direita][2]] > ordem[palavras[maior][2]]) {
                    maior = direita;
                }
            } else if (ordem[palavras[direita][1]] > ordem[palavras[maior][1]]) {
                maior = direita;
            }
        }
    } else if (ordem[palavras[direita][0]] > ordem[palavras[maior][0]]) {
        maior = direita;
    }
}
    
    if (maior != indice) {
        swap(palavras, indice, maior);
        heapify(palavras, tamanho, maior, ordem);
    }
}
 
 
void heapSort(char *palavras[], int tam, int ordem[]) {
 
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapify(palavras, tam, i, ordem);
    }
    
    for (int i = tam - 1; i >= 0; i--) {
        swap(palavras, 0, i);
        heapify(palavras, i, 0, ordem);
    }
}
 
 
int main() {  
    char *palavras[100];
    int n,n2,i,j,a,flag=0;
    int ordem[256];
    char *chave;
    
    scanf("%d", &n);
    scanf("%d",&n2);
  chave = (char *)malloc(sizeof(char) * n2);
    scanf("%s", chave);
  
    for (int i = 0; i < strlen(chave); i++) {
        ordem[(int) chave[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        palavras[i] = (char*) malloc(100 * sizeof(char));
        scanf("%s", palavras[i]);
    }
  
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < strlen(palavras[i]); j++) {
            if (!strchr(chave, palavras[i][j])) {
                flag = 1;
                break;
            }
        }
        if (flag==1){
            printf("A palavra %s eh invalida", palavras[i]); break;}
    }
         heapSort(palavras, n, ordem);
  if(flag==0){
   for (int i = 0; i < n; i++)
        printf("%s ", palavras[i]);
  }
    }
  
  
 
    
