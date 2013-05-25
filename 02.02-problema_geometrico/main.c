/* (cliente) Programa Principal 
 * 
 * Uso: $ prog3.8 N d
 *          ^ ^ ^-- distância (argv[2])
 *          | |-- nº pontos (argv[1])
 *          |-- Programa (argv[0])
 */

/* 
 * COMPLEXIDADE
 * Temos de calcular C_n,2 para o programa. Temos:
 * C_n,2 = [n*(n-1)]/2 ~ n²/2 = O(n²)
 * Logo, a ordem do algoritmo é quadrático.
 * O programa é bom para N pequenos, mas será muito ruim para 
 * qualquer N pontos grandes.
 *
 * DESAFIO: Implementar uma forma melhor que quadrática de calcular
 *          este algoritmo.
 */

#include<stdio.h>
#include<stdlib.h>
#include "Point.h"

int main(int argc, char **argv)
{
    /** VARIÁVEIS *****************************************************/
        int N, count = 0;  /* Nº de pontos / Contador       */
        point *a;          /* Lista de pontos               */
        int i, j;          /* Batedores                     */ 
        float d;           /* Distância                     */
        
        /* Checa se há argumentos ou sai */
        if(argc != 3) return EXIT_FAILURE;
        
        N = atoi(argv[1]);
        d = atof(argv[2]);
        a = (point *) malloc(N * sizeof(*a));

    /** CRIA PONTOS/DISTÂNCIA ****************************************/
        for(i = 0; i < N; i++)
            a[i] = r_point();
        
        for(i = 0; i < N; i++)
            for(j = i+1; j < N; j++)
                if(distance(a[i], a[j]) < d) count++;

    printf("%d pares distam menos que %g\n", count, d);

    return 0;
}
