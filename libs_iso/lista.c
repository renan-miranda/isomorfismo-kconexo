#include <malloc.h>
#include "lista.h"

/*----------------------------------------------------------------------------*/
int vazia_lista(lista *l) { return tamanho_lista(l) == 0; }

/*----------------------------------------------------------------------------*/
unsigned int tamanho_lista(lista *l) { return l->tamanho; }

/*----------------------------------------------------------------------------*/
no *primeiro_no(lista *l) { return l->primeiro; }

/*----------------------------------------------------------------------------*/
objeto objeto_no(no *p) { return p->o; }

/*----------------------------------------------------------------------------*/
no *sucessor_no(no *p, lista *l) { return p->sucessor; }

/*----------------------------------------------------------------------------*/
lista *constroi_lista(void) {

  lista *l = malloc(sizeof(lista));

  if ( ! l ) return NULL;

  l->primeiro = NULL;
  l->tamanho = 0;

  return l;
}
/*----------------------------------------------------------------------------*/
objeto remove_lista(lista *l) { 

  no *primeiro = primeiro_no(l);
  objeto o;

  if ( ! primeiro ) return NULL;

  o = objeto_no(primeiro);

  l->primeiro = sucessor_no(primeiro,l);
  --l->tamanho;
  free(primeiro);

  return o;
}
/*----------------------------------------------------------------------------*/
void destroi_lista(lista *l) { 
  
  no *p;

  while ( (p = primeiro_no(l)) ) {
    
    l->primeiro = sucessor_no(p,l);
    free(p);
  }

  free(l);
}
/*----------------------------------------------------------------------------*/
no *insere_lista(objeto o, lista *l) { 

  no *novo = malloc(sizeof(no));

  if ( ! novo ) return NULL;

  novo->o = o;
  novo->sucessor = primeiro_no(l);
  ++l->tamanho;
  
  return l->primeiro = novo;
}
/*============================================================================*/
