#include <stdio.h>
#include <stdlib.h>
#include "lib_iso.h"

int main()
{
    grafo g, f;
    char c;

    g = le_grafo();

    scanf("%c", &c);

    f = le_grafo();

    imprime_grafo(g);
    imprime_grafo(f);

    printf("%d\n", sao_isomorfos(g,f));

    return 0;
}
