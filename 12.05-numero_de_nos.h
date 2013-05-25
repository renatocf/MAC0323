/* Cada vez mais, a partir de agora, nos preocuparemos em saber qual 
 * o número de nós abaixo de um dado nó. O 'countR' implementado agora
 * usando sempre um algoritmo recursivo é muito ruim. O que podemos
 * fazer, neste caso, é colocar nas structs de nossos nódulos um cam-
 * po N, inteiro, para armazenar a quantidade de nódulos na árvore
 * enraizada naquele nódulo. */

struct STnode { Item item; link r, l; int N; }

/* Em nosso último exemplo, temos:
 *
 *      C(4) ( )
 *           / \
 *          /   \
 *         /     \ D(1)
 *  A(2) ( )     ( )
 *       / \B(1) / \
 *      [] ( )  [] [] z(0)
 *         / \
 *        [] []
 * Nesse caso, cada nódulo externo será considerado como
 * uma árvore de 0 elementos, as folhas como contendo N = 1 
 * elementos e a raiz com o TOTAL de elementos.
 * 
 * Precisamos adaptar TODOS os algoritmos vistos até agora.
 * Os algoritmos de rotação vistos hoje são muito importantes
 * principalmente para que possamos realizar remoções. Mesmo
 * para a seleção, não precisaríamos contar, mas sim só pode-
 * ríamos examinar o conteúdo do campo N.
 * 
 * Adicionar algo à estrutura pode ou não ser custoso. Quando
 * criamos mais um elemento para que possamos aumentar a efici-
 * ência, perdemos na eficiência de memória. Neste nosso caso,
 * para 10^9 dados, teríamos aproximadamente 4GB de uso de me-
 * mória a mais. Porém, graças a este campo, temos uma efici-
 * ência de tempo muito melhor.
 */
