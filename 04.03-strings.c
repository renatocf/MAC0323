/* TEXTOS
 * 
 * Uma maneira simples (e trivial) de processar o texto seria 
 * criar uma grande matriz de linhas e colunas, supondo um tamanho
 * máximo. O problema disto é que sobrariam muitos espaços.
 * 
 *    M
 *   |  | --^^
 *          ||
 *    M[1] |  | --> |**|**|**|**|**|**|  |  |  |
 *    M[2] |  | --> |**|**|**|**|**|**|**|**|  |
 *    ...   ..       .. .. .. .. .. .. .. .. ..
 *    M[3] |  | --> |**|**|**|**|**|  |  |  |  |
 *
 * Uma maneira um pouco melhor de representar um texto em C seria
 * alocar uma matriz dinamicamente, usando vetores de char. Mas,
 * diferentemente, para cada linha de caracteres, poderíamos criar
 * uma matriz cujas referências dos ponteiros têm tamanho variável.
 *
 *    M
 *   |  | --^^
 *          ||
 *    M[1] |  | --> |**|**|**|**|**|**|
 *    M[2] |  | --> |**|**|**|**|**|**|**|**|
 *    ...   ..       .. .. .. .. .. .. .. .. ..
 *    M[3] |  | --> |**|**|**|**|**|
 *
 * Mas uma maneira de evitar várias chamadas de malloc seria criar
 * uma matriz de forma LINEAR. Criaríamos um grande vetor e, com ele,
 * poderíamos colocar as linhas sequencialmente.
 * 
 *  |**|**|**|**|**|\0|**|**|**|**|**|**|\0|**|**|**|\0|**|**|**|\0|
 */

/* prog 3.17 */
/* Leitura e ordenação de palavras */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NMAX 1000  /* Máximo de palavras */
#define MMAX 10000 /* Máximo de caracteres */
char buf[MMAX];    /* Vetor para armazenar as palavras */
int M = 0;         /* Posição do primeiro caractere livre */

int compare(void *i, void *j)
{
    return strcmp( *(char **)i, *(char **)j );
    /*      ^ ^^^^^^^-- Faz o cast de void * para char **
     *      |-- deferencia o char ** para uma string (char *) */
}

int main()
{
    int i, N;
    char *a[NMAX];
    for(N = 0; N < NMAX; N++)
    {
        a[N] = &buf[M];
        if(scanf("%s", a[N]) == EOF) break;
        M += strlen(a[N]) + 1;
             /* Tamanho até o \0 mais o \0 */
    }
    
    /* Ex: 
     * ENTRADA: This code is from "Algorithms in C".
     * O scanf lê do primeiro caractere não branco até o
     * último caractere branco. São considerados caracte-
     * res brancos espaços, tabulações e \n.
     * 
     * buf |T |h |i |s |\0|i |s |\0|c |o |d |e | .. |c |" |. |\0|
     *  a[0]/\             /\       /\               /\
     *      || ||----------||       ||               ||
     *      || || ||----------------||               ||
     *      || || ||             ||------------------||
     *  a  |  |  |  |  |  |  |  |  |  |  |  |
     *      00 01 02    03 04 05 06 
     *                           ^^ última palavra
     */
    
    /* Uma ideia bem comum, principalmente para etruturas e dados
     * mais pesados, é criar ponteiros para as estruturas e, em se-
     * guida, ordenar estes ponteiros. Isso é ideal para não alte-
     * rar os dados.
     *
     * Dentre os algoritmos disponíveis, temos algumas quadráticos,
     * como o 'inserction sort'. Este varia muito de acordo com o 
     * número de trocas que devem ser feitas.
     * 
     * Há, porém, uma classe de algoritmos rápidos, O(n*lg n) para a
     * maioria dos casos. É a situação que envolve o merge, heap e 
     * quick sort (que é quadrático no pior caso, mas é mais rápido
     * na prática).
     * 
     * Na biblioteca disponível (stdlib), temos o QSORT, que imple-
     * menta o quicksort para todos os tipos de dados. A stdlib tam-
     * bém bem o BSEARCH, que implementa a busca binária. Estas 
     * funções, feitas com muito cuidado, ajudam.
     * 
     * O radixsort é chamado de "algoritmo de ordenação digital", 
     * que são lineares e podem ser usados para comparar dados
     * mais complexos de maneira mais rápida, como strings.
     */
    
    /* qsort(vetor, Nº_obj, tamanho_objetos, função_de_comparação) */
    qsort(a, N, sizeof(char *), compare);
    
    /* A função compare deve TER COMO ARGUMENTO PONTEIROS para 
     * objetos a serem ordenados. Ele deve devolver <0, =0 ou
     * >0 como o strcomp(). Ainda mais, devemos ter como argu-
     * mentos ponteiros VOID *. */
    
    return 0;
}

/* EXERCÍCIO: Adicionar uma função para alocação dinâmica de memória
 * do buffer. Alocar o 'a' de forma dinâmica. */
