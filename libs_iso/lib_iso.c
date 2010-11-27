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
                    if(linhas == 0)
                        g.matriz[linhas] = realoca_coluna(g.matriz[linhas], colunas+1);
                    g.matriz[linhas][colunas] = 0;
                    //printf("Adicionou 0 em %d,%d\n", linhas, colunas);
                    colunas++;
                    break;

                case '1':
                    if(linhas == 0)
                        g.matriz[linhas] = realoca_coluna(g.matriz[linhas], colunas+1);
                    g.arestas++;
                    grau++;
                    g.matriz[linhas][colunas] = 1;
                    //printf("Adicionou 1 em %d,%d\n", linhas, colunas);
                    colunas++;
                    break;

                case '\n':
                    //printf("Pulou Linha\n");
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
                        //printf("Agora matriz e %dx%d\n", colunas, colunas);
                        g.matriz = realoca_matriz(g.matriz, colunas);
                        g.graus = aloca_vet(g.graus, linhas);
                        g.graus[linhas-1] = grau;
                    }
                    else
                    {
                        g.graus = aloca_vet(g.graus, linhas);
                        g.graus[linhas-1] = grau;
                    }
                    grau = 0;
                    colunas = 0;
                    break;
            }
        }
    }

    g.arestas = g.arestas / 2;
    g.graus = ordena_sel(g.graus, 0, g.n_vertices-1);

    return g;
}

void limpa_grafo(grafo g)
{
    destroi_matriz(g.matriz, g.n_vertices);
    free(g.graus);
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
    int j, k;
    int iso = 0;
    int tam = g.n_vertices;
    int *tmp = (int*) malloc(sizeof(int));
    int v[tam], t_perm = 0;
    lista *perm;

    perm = constroi_lista();

    for(i=0; i < tam; i++)
    {
        v[i] = i;
    }

    if((g.n_vertices != f.n_vertices) || (g.arestas != f.arestas)
       || (!iguais(g, f)))
        return iso;

    perm = nova_permuta(perm, v, 0, tam);
    t_perm = tamanho_lista(perm);

    for(i=0; i < t_perm; i++)
    {
        tmp = (int*) remove_lista(perm);
        //mostre(tmp, tam);
        iso = 1;
        for(j=0; j < tam; j++)
        {
            for(k=0; k < tam; k++)
            {
                if(g.matriz[j][k] != f.matriz[tmp[j]][tmp[k]])
                {
                    iso = 0;
                    /*printf("Nao e isomorfo - ");
                    mostre(tmp, tam);*/
                    break;
                }
            }
            if(!iso)
                break;
        }
        if(iso)
        {
            /*printf("E isomorfo - ");
            mostre(tmp, tam);*/
            destroi_lista(perm);
            return 1;
        }
    }
    destroi_lista(perm);
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

void permuta(int v[], int k, int n, grafo g, grafo f)
{
    int i, aux;
    int a, b;
    int tam = g.n_vertices;
    if (k == n - 1)
    {
        mostre(v, n);
    }
    else
    {
        permuta(v, k + 1, n, g, f);
        i = k + 1;
        while (i < n)
        {
            aux = v[k];            // troca
            v[k] = v[i];
            v[i] = aux;
            /* permuta segmento de k+1 ate n e retorna com
               o segmento restaurado, isto e, da forma como
               foi passado para a funcao */
            permuta(v, k + 1, n, g, f);
            aux = v[k];            // restuara
            v[k] = v[i];
            v[i] = aux;
            i = i + 1;
        }
    }
}

lista * nova_permuta(lista *l, int *v, int k, int n)
{
    int i, aux;
    if (k == n - 1)
    {
        //mostre(v, n);
        /*Insere na lista de permutacoes*/
        int *tmp = (int*) malloc(sizeof(int));
        for(i=0; i < n; i++)
            tmp[i] = v[i];
        insere_lista((void*)tmp, l);
        return l;
    }
    else
    {
        l = nova_permuta(l, v, k + 1, n);
        i = k + 1;
        while (i < n)
        {
            aux = v[k];            // troca
            v[k] = v[i];
            v[i] = aux;
            /* permuta segmento de k+1 ate n e retorna com
               o segmento restaurado, isto e, da forma como
               foi passado para a funcao */
            l = nova_permuta(l, v, k + 1, n);
            aux = v[k];            // restuara
            v[k] = v[i];
            v[i] = aux;
            i = i + 1;
        }
    }
    return l;
}
