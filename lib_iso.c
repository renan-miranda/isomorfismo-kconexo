#include <stdio.h>
#include <stdlib.h>
#include "lib_iso.h"

grafo le_grafo()
{
    char i;
    int linhas, colunas, parada;
    int a, b, grau;
    grafo g;

    linhas = colunas = parada = 0;

    g.matriz = cria_matriz(linhas+1);
    g.arestas = 0;
    g.n_vertices = 0;

    grau = 0;

    while(!parada)
    {
        if(scanf("%c", &i) == 1)
        {
            switch(i) {
                case '0':
                    printf("Adicionou 0 em %d,%d\n", linhas, colunas);
                    if(linhas == 0)
                        g.matriz[linhas] = aloca_coluna(colunas+1);
                    g.matriz[linhas][colunas] = 0;
                    colunas++;
                    break;

                case '1':
                    printf("Adicionou 1 em %d,%d\n", linhas, colunas);
                    if(linhas == 0)
                        g.matriz[linhas] = aloca_coluna(colunas+1);
                    g.arestas++;
                    grau++;
                    g.matriz[linhas][colunas] = 1;
                    colunas++;
                    break;

                case '\n':
                    printf("Pulou Linha\n");
                    linhas++;
                    if(linhas == colunas)
                    {
                        g.n_vertices = linhas;
                        g.graus = aloca_vet(g.graus, linhas);
                        g.graus[linhas-1] = grau;
                        parada = 1;
                    }
                    else if(linhas-1 == 0)
                    {
                        realoca_matriz(g.matriz, colunas);
                        printf("Agora matriz e %dx%d\n", colunas, colunas);
                        g.graus = aloca_vet(g.graus, linhas);
                        g.graus[linhas-1] = grau;
                        grau = 0;
                        colunas = 0;
                    }
                    else
                    {
                        g.graus = aloca_vet(g.graus, linhas);
                        g.graus[linhas-1] = grau;
                        grau = 0;
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
    int iso = 0;
    int tam = g.n_vertices;
    int v[tam];

    for(i=0; i < tam; i++)
        v[i] = i;

    if((g.n_vertices != f.n_vertices) || (g.arestas != f.arestas)
       || (!iguais(g, f)))
        iso = 0;

    if(permuta(v, 0, tam, g, f))
        iso = 1;

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
        for (j=0; j < g.n_vertices; j++)
        {
            printf("%d ", g.matriz[i][j]);
        }
        printf("\n");
    }
}

void mostre(int v[], int n)
{
   int i;
   for (i = 0; i < n; i = i + 1) printf("%d", v[i]);
   printf("\n");
}

int permuta(int v[], int k, int n, grafo g, grafo f)
{
    int i, aux;
    int a, b, res = 0;
    int tam = g.n_vertices;
    if (k == n - 1)
        mostre(v, n);
    else
    {
        res = permuta(v, k + 1, n, g, f);
        i = k + 1;
        while (i < n)
        {
            aux = v[k];            // troca
            v[k] = v[i];
            v[i] = aux;
            for(a = 0; a < tam; a++)
            {
                for(b = 0; b < tam; b++)
                {
                    if(g.matriz[a][b] == f.matriz[v[a]][v[b]])
                    {
                        res = 1;
                    }
                }
            }
            /* permuta segmento de k+1 ate n e retorna com
               o segmento restaurado, isto e, da forma como
               foi passado para a funcao */
            if(!res)
            {
                res = permuta(v, k + 1, n, g, f);
                aux = v[k];            // restuara
                v[k] = v[i];
                v[i] = aux;
                i = i + 1;
            }
        }
    }
    return res;
}
