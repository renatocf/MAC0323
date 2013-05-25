/* EP1: Quadrado [0,1]² com N pontos, p1 .. pn:
 * 
 * Arestas ligam os vértices do grafo
 * --------------------------
 * |  *        *            |
 * |            \      *    |
 * |          *--*          |
 * |   *          \         |
 * |    \          *      * |
 * |     *                  |
 * |    /                   |
 * |   *        *     *     |
 * |                        |
 * |       *                |
 * --------------------------
 * 
 * Grafo F = (V,E), sendo:
 * V: conjunto de vértices; E: conjunto de arestas;
 * Uma aresta é um par não ordenado de vértices di-
 * ferenciáveis.
 *
 * No EP1: G=(p,d)
 *         p = (p1, p2, ..., pn)
 *         V = [N] = {1, ..., N}
 *         E = {(i,j): i != j, ||pi-pj|| <= d}
 * 
 * Ex:
 * -----------  
 * | *  *    |  Neste exemplo:
 * |  \  \   |  G é CONEXO:
 * |   *--*  |  Existe um CAMINHO
 * |  /    \ |  de qualquer i ∈ V
 * | *      *|  para qualquer j ∈ V
 * -----------  
 *  N = 6, d
 *  G(V, E), V = {1,2,3,4,5,6}
 *  E = {{1,2},{1,6},{2,3},{2,5},{3,5},{3,5},{5,6}}
 *  
 * PROBLEMAS:
 * (1) Dado p = (p1,p2,..,pn) e 'd', decidir de G(p,d) é conexo.
 * (2) Dado p = (p1,p2,..,pn), determinar o menor 'd' tal que 
 *     G(p,d) é conexo. [d(*p) = d]
 * 
 * Densidade normalizada crítica: d*(p)² x N/lgN
 * Calcular a média destes valores para 'M' instâncias.
 * 
 * PONTOS TÉCNICOS:
 * (1) Modo de operação TESTE DE CONEXIDADE:
 * $ep1 -N100 -d0.1              --> receber argumentos
 * $ep1 -N1000 -d0.01 -s323      --> receber argumentos + semente para
 *                                   números aleatórios.
 * $ep1 -N10000 -d0.001 -s323 -v --> lista os pontos gerados
 * 
 * (2) Modo de operação TESTE DE DENS. NORMALIZADA CRÍTICA:
 * $ep1 -N100 -M1              --> número de vezes que executa (-M)
 * $ep1 -N100 -M100 -s323      --> colocando semente
 * $ep1 -N10000 -M100 -s323 -v --> imprime os M d* calculados 
 * $ep1 -N20 -M10 -s323 -V     --> imprime os d* e os pontos calculados
 *                                 (para depuração). 
 *
 * INTERFACES:
 * Criar Point.c e Point.h para abstrair a ideia de pontos. 
 * Criar um .zip com os código-fonte.
 * 
 * 100.000 pontos é factível, executado 100 vezes.
 */
