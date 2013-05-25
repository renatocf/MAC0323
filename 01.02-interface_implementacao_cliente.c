/* INTERFACE, IMPLEMENTAÇÃO, CLIENTES
 * (Sedgewick 3.0/3.1/3.2)
 * 
 * Ex: Cálculo de média: dados N números, determinar sua média
 */

/* O enúnciado, inicialmente, é vago (qual o tipo dos N números?)
 * Vamos escrever um programa que recebe INTEIROS e PONTOS-FLUTUANTES,
 *
 *   N números      
 *      \/         
 * .----------.   
 * | prog 3.2 | <- Manipula números do tipo numType  
 * '----------'    typedef int numType;   } Trocaríamos para poder
 *      \/         typedef float numType; } tratar int/float confor-
 *    média                                 me a necessidade
 * 
 * Podemos, porém, fazer uma maneira diferente:
 *
 *   N números 
 *      \/     
 * .-----------.       .--------------.
 * | prog 3.2a | <---> | tipo numType | <- Um outro programa .c que 
 * '-----------'       | -op. def.    |    pode ser usada para defi- 
 *      \/             | -op. leitura |    nir o numType conforme o 
 *     média           '--------------'    caso. Como a sintaxe de 
 *                                         leitura é diferente, também
 *                                         é possível definir nele a
 *                                         leitura do dado (além disso,
 *                                         associamos a este tipo uma
 *                                         DEFINIÇÃO mais uma OPERAÇÃO
 *                                         DE LEITURA).
 * Esquematicamente:
 * .----------.        .--..----------.         
 * |          |        |  ||          |         * INTERFACE: artefato 
 * |  main.c  | <----> |.h||   .c     |         para definir acesso aos
 * |          |        |  ||          |         objetos do tipo criado.
 * '----------'        '--''----------'         * IMPLEMENTAÇÃO: cria as
 *   cliente           ^^  ^^-- implementação   funções definidas pela
 *                      |-- INTERFACE           interface.
 *                                              * CLIENTE: acessa a
 *                                              interface do usuário,
 *                                              nao se preocupando com
 *                                              a implementação do pro-
 *                                              grama.
 */
