#include <stdio.h>
#include <stdlib.h>
#include "lib_kcon.h"
#include "fila.h"


int k_conexo(int k, grafo g)
{
	int i,j;
	for (i=0; i < g.n_vertices; i++)
		for (j=1; j < g.n_vertices; j++)
			if ( i<j && !tem_k_caminhos(i,j,k,g) )
				return 0;
	return 1;
}

int tem_k_caminhos(int i, int j, int k, grafo g)
{
	int x;
    grafo *copia;
    
    copia=copia_grafo(g,copia);
	for(x=0;x< k; x++)
		if( !busca(j,i,copia))
			return 0;	
    printf("Tem %d caminhos de %d para %d!\n\n", k, i, j);
    return 1;				
}

int busca(int j, int i, grafo *g)
{
	int v, count, *visitado;
	fila *F;
	F=constroi_fila();
	visitado=(int *) calloc(g->n_vertices,sizeof(int));

	visitado[i]=1;
	enfila(i,F);
	
	while(!vazia_fila(F))
	{
		v=desenfila(F);
		for(count=0; count < g->n_vertices; count++)
			if(!visitado[count] && g->matriz[v][count]==1)//não foi visitado e tem aresta de do vertice v para vertice count
			{
				if(count==j)    // ACHOU! tem caminho de i para j.
				{
					g->matriz[v][count]=0;//retiramos a aresta que nos fez chegar ao vertice j.
                    g->matriz[count][v]=0;
					destroi_fila(F);
					return 1;
				}
				else
				{
					visitado[count]=1;
					enfila(count,F);
				}
			}
	}
	destroi_fila(F);
	return 0;
}

grafo le_grafo()
{
    char c;
    int colunas,i;
    grafo g;

    g.matriz = (int**) malloc(sizeof(int *));
    g.n_vertices = 0;

	while(scanf("%c", &c)!=EOF)
	{
		g.n_vertices++;
		g.matriz=(int**) realloc(g.matriz,sizeof(int*)*g.n_vertices);
		colunas=0;
		while(c!='\n')
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

    for (i=0; i < g.n_vertices; i++)
    {
        printf("Vertice %d: ", i);
        for (j=0; j < g.n_vertices; j++)
        {
			if (g.matriz[i][j])
            	printf("%d ", j);
        }
        printf("\n");
    }
}			

grafo *copia_grafo(grafo g, grafo *novo)
{
    int i, j, tam;
    tam = novo->n_vertices = g.n_vertices;
    novo->matriz=(int**) malloc(sizeof(int*)*tam);
    for(i=0;i< tam ;i++){
        novo->matriz[i]=(int*) malloc(sizeof(int)*tam);
        for(j=0; j < tam ; j++)
            novo->matriz[i][j]=g.matriz[i][j];
    }
    return novo;
}
