#include <stdio.h>
#include <stdlib.h>
#include "lib_matriz.h"

int **aloca_linha(int lim)
{
    int **vetor = NULL;
    vetor = (int**) realloc(vetor, lim * sizeof(int*));
    return vetor;
}

int * aloca_coluna(int tam)
{
    int *vetor = NULL, i;
    vetor = (int*) realloc(vetor, tam * sizeof(int));
    for(i = 0; i < tam; i++)
    {
        vetor[i] = 0;
    }
    return vetor;
}

int ** cria_matriz(int tam)
{
    int **matriz, i;

    matriz = aloca_linha(tam);
    for(i=0; i < tam; i++)
    {
        matriz[i] = aloca_coluna(tam);
    }

    return matriz;
}

void realoca_matriz(int **matriz, int tam)
{
    int i;

    matriz = (int**) realloc(matriz, tam * sizeof(int*));
    for(i=0; i < tam; i++)
    {
        matriz[i] = (int*) realloc(matriz[i], tam * sizeof(int));
    }
}

void destroi_matriz(int **m, int tam)
{
    int i;
    for(i=0; i<tam ;i++)
    {
        free(m[i]);
    }
    free(m);
}


void insere_aresta(int **m, int i, int j)
{
    m[i][j] = ARESTA;
}

void insere_naresta(int **m, int i, int j)
{
    m[i][j] = N_ARESTA;
}
