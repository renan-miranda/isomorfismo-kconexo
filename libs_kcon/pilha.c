#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "pilha.h"

/* ##########################################################################
                            implementacao da lista
   ########################################################################## */

/*----------------------------------------------------------------------------*/
int int_no(no *p) {
    return p->o;
}

/*----------------------------------------------------------------------------*/
no *primeiro_lista(lista *l) {
    return l->primeiro;
}

/*----------------------------------------------------------------------------*/
no *primeiro_no(lista *l) {
    return vazia_lista(l) ? NULL : l->primeiro;
}

/*----------------------------------------------------------------------------*/
no *sucessor_no(no *p, lista *l) {
    return p->sucessor;
}

/*----------------------------------------------------------------------------*/
int vazia_lista(lista *l) {
    return l->tamanho == 0;
}

/*----------------------------------------------------------------------------*/
unsigned int tamanho_lista(lista *l) {
    return l->tamanho;
}

/*----------------------------------------------------------------------------*/
lista *constroi_lista(void) {
    lista *l = malloc(sizeof(lista));
    if (!l) 
        return NULL;
    l->primeiro = NULL;
    l->tamanho = 0;
    return l;
}

/*----------------------------------------------------------------------------*/
void destroi_lista(lista *l) {
    no *p;
    while ((p = primeiro_no(l))) {
        l->primeiro = sucessor_no(p, l);
        free(p);
    }
    free(l);
}

/*----------------------------------------------------------------------------*/
no *insere_lista(int o, lista *l) {
    no *novo = malloc(sizeof(no));
    if(!novo)
        return NULL;
    novo->o = o;
    novo->sucessor = primeiro_no(l);
    ++l->tamanho;
    return l->primeiro = novo;
}

/*----------------------------------------------------------------------------*/
int remove_lista(lista *l) {
    no *primeiro = primeiro_no(l);
    int o;
    if (!primeiro)
        return -1;
    o=int_no(primeiro);
    l->primeiro=sucessor_no(primeiro, l);
    --l->tamanho;
    free(primeiro);
    return o;
}

/* ##########################################################################
                            implementacao da pilha
   ########################################################################## */

int vazia_pilha(pilha *f) {
    return vazia_lista(f);
}

/*----------------------------------------------------------------------------*/
unsigned int tamanho_pilha(pilha *f) {
    return tamanho_lista(f);
}

/*----------------------------------------------------------------------------*/
pilha *constroi_pilha(void) {
    constroi_lista();
}

/*----------------------------------------------------------------------------*/
void destroi_pilha(pilha *f) {
    destroi_lista(f);
}

/*----------------------------------------------------------------------------*/
int empilha(int o, pilha *f) {
    return insere_lista(o, f) != NULL;
}

/*----------------------------------------------------------------------------*/
int desempilha(pilha *f) {
    return remove_lista(f);
}

int topo_da_pilha(pilha *f) {
    return f->primeiro->o;
}
