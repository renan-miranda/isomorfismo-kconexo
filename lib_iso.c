#include <stdio.h>
#include <stdlib.h>
#include "lib_iso.h"

grafo le_grafo()
{
    char i;
    int linhas, colunas, parada;
    grafo g;

    linhas = colunas = parada = 0;

    g.v = (vertice*) malloc(sizeof(vertice));
    g.arestas = 0;
    g.n_vertices = 0;

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
                        g.n_vertices = linhas;
                        g.graus = aloca_vet(g.graus, linhas);
                        g.graus[linhas-1] = g.v[linhas-1].grau;
                        parada = 1;
                    }
                    else
                    {
                        g.n_vertices++;
                        g.graus = aloca_vet(g.graus, linhas);
                        g.graus[linhas-1] = g.v[linhas-1].grau;
                        g.v = (vertice*) realloc(g.v, (g.n_vertices+1) * sizeof(vertice));
                        g.v[linhas].grau = 0;
                        colunas = 0;
                    }
                    break;
            }
        }
    }

    g.arestas = g.arestas / 2;
    g.graus = ordena_sel(g.graus, 0, g.n_vertices-1);

    return g;
}

static int iguais(grafo g, grafo f)
{
    int i, menor = g.n_vertices;
    if(f.n_vertices < g.n_vertices)
        menor = f.n_vertices;
    for (i=0; i < menor; i++)
        if (g.graus[i] != f.graus[i])
            return 0;

    return 1;

}

int sao_isomorfos(grafo g, grafo f)
{
    int i = 0;

    if((g.n_vertices != f.n_vertices) || (g.arestas != f.arestas)
       || (!iguais(g, f)))
        return 0;
}

void imprime_grafo(grafo g)
{
    int i, j;

    printf("Vertices = %d, Arestas = %d\n", g.n_vertices, g.arestas);
    printf("Vetor de graus: ");

    for (i=0; i < g.n_vertices; i++)
    {
        printf("%d ", g.graus[i]);
    }
    printf("\n");

    for (i=0; i < g.n_vertices; i++)
    {
        printf("Vertice %d: ", i+1);
        for (j=0; j < g.v[i].grau; j++)
        {
            printf("%d ", g.v[i].vizinhos[j]);
        }
        printf("\n");
    }
}
