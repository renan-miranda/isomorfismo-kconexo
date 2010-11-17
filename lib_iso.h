#ifndef __libiso__
#define __libiso__

typedef struct  {
    int *vizinhos;
    int grau;
    } vertice;

typedef struct grafo {
    vertice *v;
    int graus;
    int n_vertices;
    int arestas;
    } grafo;

grafo le_grafo();
int sao_isomorfos(grafo g, grafo f);
void imprime_grafo(grafo g);

#endif
