#include <stdio.h>
#include <stdlib.h>
#include "lib_kcon.h"

int main()
{
    grafo g;
    int k;

    scanf("%d", &k );
    getchar();
	
    g = le_grafo();

    imprime_grafo(g);

    printf("%d\n", k_conexo(k,g));

    return 0;
}
