typedef void *objeto;

typedef struct no {
  objeto o;
  struct no *sucessor;
} no;

typedef struct {
  no *primeiro;
  unsigned int tamanho;
} lista;

objeto objeto_no(no *p);
no *sucessor_no(no *p, lista *l);
no *primeiro_no(lista *l);

int vazia_lista(lista *l);
unsigned int tamanho_lista(lista *l);
lista *constroi_lista(void);
void destroi_lista(lista *l);
no *insere_lista(objeto o, lista *l);
objeto remove_lista(lista *l);
