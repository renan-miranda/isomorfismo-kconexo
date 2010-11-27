#ifndef _fila_
#define _fila_

typedef struct no {
  int o;
  struct no *sucessor;
} no;

typedef struct {
  no *primeiro, *ultimo;
  unsigned int tamanho;
} lista;

int int_no(no *p);
no *sucessor_no(no *p, lista *l);
no *primeiro_no(lista *l);
typedef lista fila;

/* lista */
int vazia_lista(lista *l);
unsigned int tamanho_lista(lista *l);
lista *constroi_lista(void);
void destroi_lista(lista *l);
no *insere_lista(int o, lista *l);
int remove_lista(lista *l);
no *insere_outra_ponta_lista(int o, lista *l);

/* fila */
int vazia_fila(fila *f);
unsigned int tamanho_fila(fila *f);
fila *constroi_fila(void);
void destroi_fila(fila *f);
int enfila(int o, fila *f);
int desenfila(fila *f);

#endif
