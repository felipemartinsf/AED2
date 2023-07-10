#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct No {
    int destino;
    int peso;
    struct No* prox;
} No;


typedef struct {
    int nV;
    No** listaAdj;
} Grafo;


No* criarno(int destino, int peso) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->destino = destino;
    novoNo->peso = peso;
    novoNo->prox = NULL;
    return novoNo;
}


Grafo* criargrafo(int nV) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->nV = nV;

  
    grafo->listaAdj = (No**)malloc(nV * sizeof(No*));
    for (int i = 0; i < nV; i++) {
        grafo->listaAdj[i] = NULL;
    }

    return grafo;
}


void addAresta(Grafo* grafo, int origem, int destino, int peso) {

    No* novoNo = criarno(destino, peso);

    if (grafo->listaAdj[origem] == NULL || grafo->listaAdj[origem]->destino > destino) {
        novoNo->prox = grafo->listaAdj[origem];
        grafo->listaAdj[origem] = novoNo;
    } else {
        No* atual = grafo->listaAdj[origem];
        while (atual->prox != NULL && atual->prox->destino < destino) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}


int verticeminimo(int* distancia, int* visitado, int nV) {
    int minimo = INT_MAX;
    int indiceMinimo = -1;

    for (int v = 0; v < nV; v++) {
        if (visitado[v] == 0 && distancia[v] <= minimo) {
            minimo = distancia[v];
            indiceMinimo = v;
        }
    }

    return indiceMinimo;
}

void print(int* distancia, int* antecessor, int nV, int inicio) {
    for (int i = 0; i < nV; i++) {
        if (i != inicio) {

            if (distancia[i] == INT_MAX) {
            } else {
                int j = i;
                do {
                    j = antecessor[j];
                } while (j != inicio);
                printf("%d ", distancia[i]);
            }
        } else {
            printf("0 ");
        }
    }
}

void di(Grafo* grafo, int inicio, int r) {
    int nV = grafo->nV;

    int* distancia = (int*)malloc(nV * sizeof(int));
    int* visitado = (int*)malloc(nV * sizeof(int));
    int* antecessor = (int*)malloc(nV * sizeof(int));

    for (int i = 0; i < nV; i++) {
        distancia[i] = INT_MAX;
        visitado[i] = 0;
    }

    distancia[inicio] = 0;

    for (int count = 0; count < nV - 1; count++) {
        int u = verticeminimo(distancia, visitado, nV);
        visitado[u] = 1;

        No* atual = grafo->listaAdj[u];
        while (atual != NULL) {
            int v = atual->destino;
            int peso = atual->peso;

            if (!visitado[v] && distancia[u] != INT_MAX &&
                distancia[u] + peso < distancia[v] && peso <= r) {
                distancia[v] = distancia[u] + peso;
                antecessor[v] = u;
            }

            atual = atual->prox;
        }
    }

    print(distancia, antecessor, nV, inicio);

    free(distancia);
    free(visitado);
    free(antecessor);
}

int main() {
  
   int inicio;
    scanf("%d", &inicio);
    int r;
    scanf("%d", &r);
  
    int nV, nA;
    scanf("%d %d", &nV,  &nA);
    Grafo* grafo = criargrafo(nV);
    for (int i = 0; i < nA; i++) {
        int origem, destino, peso;
        scanf("%d %d %d", &origem, &destino, &peso);
        addAresta(grafo, origem, destino, peso);
    }

    di(grafo, inicio, r);

    return 0;
}
