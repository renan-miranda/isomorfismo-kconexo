#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib_kcon.h"
#include "pilha.h"

int k_conexo(int k, grafo g) {
        int i, j;
        /*grafo g_temp;
        g_temp.matriz = (int **) malloc(sizeof(int *) * g.n_vertices);
        for (i=0; i<g.n_vertices; i++) {
            g_temp.matriz[i] = (int *) malloc(sizeof(int) * g.n_vertices);
            memcpy(g_temp.matriz[i], g.matriz[i], sizeof(g.matriz[i]));
        }
        g_temp.n_vertices = g.n_vertices;*/

        for (i=0; i<g.n_vertices; i++) {
                for (j=1; j<g.n_vertices; j++)
                        if (i<j && !tem_k_caminhos(i,j,k,g))
                                return 0;
        }
        return 1;
}

int tem_k_caminhos(int i, int j, int k, grafo g) {
        int x;
        for(x=0; x<k; x++) {
                imprime_grafo(g);
                printf("\n %dº BUSCA: Indo do vertice %d para o %d\n", i, j, x+1);
                if (!busca(j, i, &g))
                        return 0;
        }
        return 1;
}

int busca(int j, int i, grafo *g) {
        int v, u, *visitado, k;
        pilha *P;
        P = constroi_pilha();
        cor = (int *) calloc(g->n_vertices, sizeof(int));

        cor[i] = 1;
        empilha(i, P);

        while(!vazia_pilha(P)) {
                v = topo_da_pilha(P);
                for (u = 0; u < g->n_vertices; u++) {
                        //tem aresta de do vertice v para vertice count
                        if(!visitado[count] && (g->matriz[v][u])) {
                                        if (count == j) {    // ACHOU! tem caminho de i para j.
                                                printf("Destruindo arestas\n");
                                                while(v>=0){
                                                    g->matriz[v][count] = 0;//retiramos a aresta que nos fez chegar ao vertice j.
                                                    g->matriz[count][v] = 0;
                                                    count=v;
                                                    v=desempilha(P);
                                                }
                                                destroi_pilha(P);
                                                return 1;
                                        }
                                        else {
                                                visitado[count] = 1;
                                                empilha(count,P);
                                        }
                        }
                }
                printf("Imprimindo vertice");
                for (i = 0; i < g->n_vertices; i++) 
                        printf("%d->", visitado[i]);
                printf("\n");
        }
                destroi_pilha(P);
                return 0;
}

grafo le_grafo() {
    char c;
    int i;
    int colunas;
    grafo g;

    g.matriz = (int**) malloc(sizeof(int *));
    g.n_vertices = 0;

        while(scanf("%c", &c) != EOF)
        {
                g.n_vertices++;
                g.matriz=(int**) realloc(g.matriz,sizeof(int*)*g.n_vertices);
                colunas=0;
                while (c!='\n')
                {
                        i = (int) c - 48;
                        colunas++;
                        g.matriz[g.n_vertices-1]=(int*) realloc(g.matriz[g.n_vertices-1], sizeof(int)*colunas);
                        g.matriz[g.n_vertices-1][colunas-1]=i;                  
                        scanf("%c", &c);
                }

    }
    return g;
}

void imprime_grafo(grafo g)
{
    int i, j;

    printf("Numero de vertices = %d.\n", g.n_vertices);

    for (i=0; i < g.n_vertices; i++) {
        printf("Vertice %d: ", i);
        for (j=0; j < g.n_vertices; j++) {
            //    if (g.matriz[i][j])
                        printf("%d ", g.matriz[i][j]);
        }
        printf("\n");
    }
}                       
