#include <stdio.h>
#include <stdlib.h>
#include "lib_iso.h"

grafo le_grafo()
{
    char i;
    int linhas, colunas, parada;
    grafo g;

    linhas = colunas = parada = 0;

    g.v = (vertice*) malloc((linhas + 1) * sizeof(vertice));
    g.graus = 0;
    g.arestas = 0;

    g.v[linhas].grau = 0;

    while(!parada)
    {
        if(scanf("%c", &i) == 1)
        {
            switch(i) {
                case '0':
                    colunas++;
                    break;

                case '1':
                    g.arestas++;
                    g.v[linhas].grau++;
                    g.v[linhas].vizinhos = (int*) realloc(g.v[linhas].vizinhos, (g.v[linhas].grau) * sizeof(int));
                    g.v[linhas].vizinhos[g.v[linhas].grau-1] = colunas;
                    colunas++;
                    break;

                case '\n':
                    linhas++;
                    if(linhas == colunas)
                    {
                        parada = 1;
                    }
                    else
                    {
                        g.n_vertices = linhas + 1;
                        g.v = (vertice*) realloc(g.v, g.n_vertices * sizeof(vertice));
                        g.v[linhas].grau = 0;
                        colunas = 0;
                    }
                    break;
            }
        }
    }

    g.arestas = g.arestas / 2;

    return g;
}

int sao_isomorfos(grafo g, grafo f)
{
    return 0;
}

void imprime_grafo(grafo g)
{
    int i, j;

    printf("Vertices = %d, Arestas = %d\n", g.n_vertices, g.arestas);

    for (i=0; i < g.n_vertices; i++)
    {
        printf("Vertice %d: Grau %d\n", i+1, g.v[i].grau);
        for (j=0; j < g.v[i].grau; j++)
        {
            printf("%d ", g.v[i].vizinhos[j]);
        }
        printf("\n");
    }
}
