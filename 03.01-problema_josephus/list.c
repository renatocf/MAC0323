#include<stdlib.h>
#include "list.h"

link freelist; /* Variável global para lista vazia */

void initNodes(int N)
{
    int i;
    freelist = malloc((N+1) * sizeof(*freelist));
    /* Para aumentar a velocidade em máquinas mais simples, evi-
     * tamos chamadas de malloc, que são muito lentas. Criamos um
     * vetor de struct nodes, apontados por freelist. Ao alocar
     * este grande bloco, evitamos problemas. */
    
    for(i = 0; i < N+1; i++) /* N+1 para conter a cabeça */
        freelist[i].next = &freelist[i+1];
        /* Inicializamos o 'next' de cada nódulo para apontar
         * para o próximo. */
    
    freelist[N].next = NULL;
}

Node newNode(int i)
{
    link x = deleteNext(freelist);
    x->item = i; x->next = x;
    return x;
}

void freeNode(Node x)
{
    insertNode(freelist, x);
}

void insertNode(Node x, Node t)
{
    t->next = x->next;
    x->next = t;
}

Node deleteNext(Node x)
{
    link t = x->next;
    x->next = t->next;
    return x;
}

Node Next(Node x)
{
    return x->next;
}

int Item(Node x)
{
    return x->item;
}

/* Para que não criemos uma falha de segmentação, 
 * podemos dobrar a memória quando atingimos 50% da
 * capacidade */
