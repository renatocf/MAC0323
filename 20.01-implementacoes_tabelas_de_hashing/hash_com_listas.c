/* pro14.3.c */

#include <string.h>
#include "Item.h"
#include "ST.h"

typedef struct STnode *link;
struct STnode { Item item; link next; };

/* HEADS será um vetor com cabeças de listas ligadas
 * para o primeiro elemento da lista ligada */
static link *heads, z;
static int N, M; /* Número de elementos/tamanho da tabela */

static link NEW(Item item, link next)
{ link x = malloc(sizeof(*x)); 
  x->item = item; x->next = next; 
  return x; }

int STcount { return N; }

/* prog. 14.1 - já mostrado, implementa uma função 
 * de hashing para strings considerando-os como inteiros
 * na base 127. */
int hash (char *v, int M)
{
    int h = 0; a = 127;
    for(; *v != '\0'; v++)
        h = (a*h + *v) % M;
    return h;
}

vois STinit(int max)
{
    /* Exemplos na página 251. Tabela de primos
     * disponível no livro do Sedgewick */
    int i; N = 0; M = 97;
    
    /* Criando o vetor de listas */
    heads = malloc(M * sizeof(link));
    
    /* Inicializa a cauda */
    z = NEW(NULLitem, NULL); 
    
    /* Inicializa cada lista apenas com a cauda */
    for(i= 0; i < M; i++) heads[i] = z;
}

Item searchR(link t, Key k)
{
    if(t == z) return NULLitem; /* base da recursão */
    if(eq(key(t->item), k)) return t->item;
    return searchR(t->next, k);
}

Item STsearch(Key k)
    { return searchR(heads[hash(k,M)],k); }

void STinsert(Item item)
{
    int i = hash(key(item),M);
    heads[i] = NEW(item,heads[i]); N++;
}

/* Na página, há a função 'STdump()' que imprime
 * todas as palavras na ordem em que estão mostradas
 * na lista. Porém, a função de hashing não mantém
 * as listas ordenadas. Por esse motivo, as tabelas
 * de hashing não são boas quando se quer usar ta-
 * belas ordenadas em tempo ótimo (para tanto, as
 * ARNEs são mais práticas). */
