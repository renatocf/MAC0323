#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INITIAL_BUF_SIZE 100

char *GetLine();
extern char *progname;

/* Fazemos um define que representa um tamanho de código
 * passando para ele um valor. Ele substituirá a entrada.
 * Isso tem uma VANTAGEM sobre criar uma função, pois
 * evita o tempo de chamada de uma delas. */
#define out_of_memory(x) \
    { fprintf(stderr, "%s: Acabou memoria!\n", progname); exit(x); }
