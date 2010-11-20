#include <stdio.h>
#include <stdlib.h>
#include "lib_kcon.h"
#include "fila.h"


int k_conexo(int k, grafo g)
{
	int i,j;
	for (i=0; i < g.n_vertices; i++)
	{
		for (j=0; j < g.n_vertices; j++)
			if ( i!=j && !tem_k_caminhos(i,j,k,g) )
				return 0;
	}
	return 1;
}

int tem_k_caminhos(int i, int j, int k, grafo g)
{
	int x;

	for(x=0;x< k; x++)
	{
	//A busca em largura retira a aresta de arvore que incide no vertice j
	// portanto ela destroi o grafo, temos que passar uma copia do grafo!!
	//   Falta implementar isto.
		if( busca_largura(j,i,&g) == 0 )
			return 0;					
	}					
}

int busca_largura(int j, int i, grafo *g)
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
			if(!visitado[count])
				if(g->matriz[v][count]=='1')//tem aresta de do vertice v para vertice count
				{
					if(count==j)    // ACHOU! tem caminho de i para j.
					{
						g->matriz[v][count]='0';//retiramos a aresta que nos fez chegar ao vertice j.
						destroi_fila(F);
						return 1;
					}
					else
					{
						visitado[count]=1;
						enfila(count,F);
					}
				}
		destroi_fila(F);
		return 0;
	}
}

grafo le_grafo()
{
    char i;
    int colunas;
    grafo g;

    g.matriz = (int**) malloc(sizeof(int *));
    g.n_vertices = 0;

	while(scanf("%c", &i)!=EOF)
	{
		g.n_vertices++;
		g.matriz=(int**) realloc(g.matriz,sizeof(int*)*g.n_vertices);
		colunas=0;
		while(i!='\n')
		{
			colunas++;
    	    g.matriz[g.n_vertices-1]=(int*) realloc(g.matriz[g.n_vertices-1], sizeof(int)*colunas);
        	g.matriz[g.n_vertices-1][colunas-1]=i;
			
			scanf("%c", &i);
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
			if (g.matriz[i][j]=='1')
            	printf("%d ", j);
        }
        printf("\n");
    }
}			
