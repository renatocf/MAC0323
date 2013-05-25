/* Prog 3.13 */
#include<stdio.h>
#include<stdlib.h>
#include "list.h"

int main(int argc, char **argv)
{
    /** VARIÁVEIS *****************************************************/
        int i, N, M;
        Node t, x; link teste;
        
        if(argc != 3)
        {
            printf("USAGE: josephus <n_people> <m>\n");
            return EXIT_FAILURE;
        }
        
        N = atoi(argv[1]); M = atoi(argv[2]);
        printf("Último membro restante: %d\n", N);
        printf("Último membro restante: %d\n", M);
    
    /** INICIA LISTA **************************************************/ 
        initNodes(N); /* Não há mais que N argumentos */
        
        /* 
         * Estamos assumindo que cada nódulo, ao ser criado, 
         * aponta para si mesmo.
         */
        
        /* Inicializamos x com newNode(1) para termos onde 
         * adicionar os próximos elementos */
        for(i = 2, x = newNode(1); i <= N; i++)
        {
            t = newNode(i); insertNode(x,t); x = t;
        }
        
        for(teste = x; Next(teste) != x; teste = Next(teste))
        {
            printf("%d ", Item(teste));
        }
        
        while(x != Next(x))
        {
            for(i = 1; i < M; i++)
            {
                printf("%d ", Item(x));
                x = Next(x);
            }
            freeNode(deleteNext(x));
            /* Cada vez que caminhamos pela lista, vamos 
             * fazendo a remoção dos elementos. Logo, po-
             * demos apenas ir seguindo os argumentos con-
             * forme a necessidade. */
        }
        
        printf("Último membro restante: %d\n", Item(x));
    
    return 0;
}

/* EXERCÍCIO: Tentar implementar usando STRINGS em vez de INTEIROS,
 * criando um Item.h */
