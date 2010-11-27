#ifndef __libkcon__
#define __libkcon__

typedef struct grafo {
    int **matriz;
    int n_vertices;
    } grafo;

grafo le_grafo();
void imprime_grafo(grafo g);
int k_conexo(int k, grafo g);
int tem_k_caminhos(int i, int j, int k, grafo g);
int busca(int j, int i, grafo *g);
grafo *copia_grafo(grafo g, grafo *novo);

#endif

