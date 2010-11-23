#ifndef __libiso__
#define __libiso__

#include "lib_ord.h"
#include "lib_matriz.h"

typedef struct grafo {
    int *graus, **matriz;
    int n_vertices;
    int arestas;
    } grafo;

grafo le_grafo();
int sao_isomorfos(grafo g, grafo f);
void imprime_grafo(grafo g);
void mostre(int v[], int n);
int permuta(int v[], int k, int n, grafo g, grafo f);

#endif
