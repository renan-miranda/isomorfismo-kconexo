#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "fila.h"

/* ##########################################################################
                            implementacao da lista
   ########################################################################## */

no *insere_outra_ponta_lista(int o, lista *l){
	no *novo = malloc(sizeof(no));
	if(!novo)
		return NULL;
	if (vazia_lista(l))
		l->primeiro = novo;
	else
		l->ultimo->sucessor = novo;
	novo->o = o;
	novo->sucessor = NULL;
	++l->tamanho;
	return l->ultimo = novo;
}

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
        return 0;
    o=int_no(primeiro);
    l->primeiro=sucessor_no(primeiro, l);
    --l->tamanho;
    free(primeiro);
    return o;
}

/* ##########################################################################
                            implementacao da fila
   ########################################################################## */

int vazia_fila(fila *f) {
    return vazia_lista(f);
}

/*----------------------------------------------------------------------------*/
unsigned int tamanho_fila(fila *f) {
    return tamanho_lista(f);
}

/*----------------------------------------------------------------------------*/
fila *constroi_fila(void) {
    constroi_lista();
}

/*----------------------------------------------------------------------------*/
void destroi_fila(fila *f) {
    destroi_lista(f);
}

/*----------------------------------------------------------------------------*/
int enfila(int o, fila *f) {
    return insere_outra_ponta_lista(o, f) != NULL;
}

/*----------------------------------------------------------------------------*/
int desenfila(fila *f) {
    return remove_lista(f);
}
