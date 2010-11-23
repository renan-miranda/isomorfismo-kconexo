#ifndef __LIBMATRIZ__
#define __LIBMATRIZ__

#define ARESTA 1
#define N_ARESTA 0

int **aloca_linha(int lim);
int * aloca_coluna(int tam);
int ** cria_matriz(int tam);
void destroi_matriz(int **m, int tam);
void insere_aresta(int **m, int i, int j);
void insere_naresta(int **m, int i, int j);

#endif
