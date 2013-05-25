/* prog 12.2.c - Exemplo de programa cliente para o dicionário */
#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "St.h"

int main(int argc, char *argv[])
{
    int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Key v; Item item;
    
    STinit(maxN);
    for(N = 0; N < maxN; N++)
    {
        if(sw) { item = ITEMrand(); }
            /* Geramos pontos aleatoriamente quando a 
             * opção sw é diferente de 0. Caso contrário, 
             * usamos a opção passado como argumento e 
             * recebemos da entrada até o fim de arquivo. */
        else if(ITEMscan(&item) == EOF) break;
        
        if(STsearch(key(item)) == NULLitem) STinsert(item);
            /* Se a posição da chave na tabela não estiver 
             * preenchida, inserimos o símbolo */
    }
}
