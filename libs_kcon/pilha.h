#ifndef _pilha_
#define _pilha_

typedef struct no {
  int o;
  struct no *sucessor;
} no;

typedef struct {
  no *primeiro;
  unsigned int tamanho;
} lista;

int int_no(no *p);
no *sucessor_no(no *p, lista *l);
no *primeiro_no(lista *l);
typedef lista pilha;

/* lista */
int vazia_lista(lista *l);
unsigned int tamanho_lista(lista *l);
lista *constroi_lista(void);
void destroi_lista(lista *l);
//no *insere_outra_ponta_lista(int o, lista *l);
int remove_lista(lista *l);
no *insere_lista(int o, lista *l);

/* pilha */
int vazia_pilha(pilha *f);
unsigned int tamanho_pilha(pilha *f);
pilha *constroi_pilha(void);
void destroi_pilha(pilha *f);
int empilha(int o, pilha *f);
int desempilha(pilha *f);
int topo_da_pilha(pilha *f);

#endif
