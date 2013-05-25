/* Listas ligadas - recapitulação
 * 
 * EXEMPLO: O problema de Josephus
 *
 * Dados inteiros positivos N e M, dispomos N objetos em uma ordem
 * circular. Removemos o M-ésimo elemento sucessivamente. QUem sobra?
 * 
 * EX: N = 10, M = 2
 *                  
 *        *1                *1               *-                -
 *      10   2             -   -            -   -            -   -
 *    9         3        9        3       9        -       -        -
 *  8             4    -            -   -            -   -            -
 *     7       5          7      5         -      5         -     *5
 *         6                 -                -                -   ^
 *                                              sobra o elemento 5 |
 *
 * N = 10, M = 3
 * 
 *        *1               *-                -                -       
 *      10   2           10   2           -   *2           -     -     
 *    9         3      -         -      -         -      -         -  
 *  8             4  8             4  8             4  8             4
 *     7       5        7       5        7       -        -       -   
 *         6                -                -                -       
 *
 *         -       
 *      -     -    
 *    -         -  
 *  -            *4 <- sobra o elemento 4
 *     -       -   
 *         -       
 *
 * Para M fixo, temos uma função f:IN^+->IN^+
 *                                  N |-> f_m(N) = quem sobra
 * 
 * Ex: f_2(10) = 5, f_3(10) = 4
 * Desafio: Encontre uma fórmula para f_2(N)
 */

/* VEREMOS: simulação de Josephus p/ N e M gerais.
 * Possibilidades: vetor de bits;
 *                 lista ligada;
 *                 [lista circular] 
 */
