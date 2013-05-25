/* (1) Dados N pontos no plano e um 'limiar' d > 0, distar quantos
 *     pontos distam menos de 'd'.
 *     Inicialmente, já sabemos que temos C_n,2 checagens para fazer,
 *     comparando a distância com 'd'.
 *
 * Variante: geramos N pontos uniformemente ao acaso no quadrado 
 * unitário [0,1]x[0,1]. N,d = dados pelo usuário.
 * 
 * Podemos representar os pontos de duas maneiras:
 *
 * * Coordenadas cartesianas:   * Coordenadas polares
 *  ^                           ^                        
 *  |                           |                        
 *  |__. P=(x_p,y_p)            |  . P=(r,θ)     
 *  |  |                        | /                       
 *  |  |                        |/                       
 *  o------------>              o------------>           
 * 
 * Para o programa, precisaremos:
 * TIPO: point
 * FUNÇÕES: distance() # Dá a distância entre dois pontos
 *          r_point()  # Gera os pontos aleatoriamente no quadrado
 *                     # unitário [0,1]x[0,1] 
 */

/* ESQUEMA CLIENTE/INTERFACE/IMPLEMENTAÇÃO
 *
 * .----------.        .--..----------.      
 * |          |        |  ||          |      
 * |  main.c  | <----> |.h||   .c     |      
 * |          |        |  ||          |      
 * '----------'        '--''----------'      
 *   cliente           ^^  ^^-- implementação
 *                      |-- INTERFACE        
 *
 * Neste caso, não estamos escondendo, realmente, a implementação
 * de point, mas às vezes é importante fazê-lo.
