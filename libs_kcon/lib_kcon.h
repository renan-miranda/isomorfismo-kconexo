#ifndef __libkcon__
#define __libkcon__

#define ENTROU_PILHA 1
#define SAIU_PILHA 2

typedef struct grafo {
    int **matriz;
    int n_vertices;
    } grafo;

grafo le_grafo();
void imprime_grafo(grafo g);
int k_conexo(int k, grafo g);
int tem_k_caminhos(int i, int j, int k, grafo g);
int busca(int j, int i, grafo *g);

#endif

