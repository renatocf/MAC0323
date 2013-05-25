/* Implementação de ARNE */
typedef struct STnode *link;
struct STnode { Item item; link l, r; /*int N*/ int /*OU char*/ red;
/* Não colocaremos, AINDA, o campo que diz quantos filhos temos
 * abaixo de um certo nódulo da árvore. A campo RED (char ou int)
 * age como um booleano para explicitar a forma de inserção. */

static link head /*cabeça*/, z /*nó externo*/;

link NEW(Item item, link l, link r, int red)
{
    link x = malloc(sizeof *x);
    x->item = item; x->l = l; x->r = r;
    x->red = red;
    return x;
}

void STinit()
{ head = (z = NEW(NULLitem, NULL, NULL, 0)); }

/* BUSCA: como em ABBs usuais (vejam código na página) */

/* INSERÇÃO
 * Queremos implementar o algoritmo de inserção em árvores
 * 2-3, diretamente na camada de ARNEs. Novamente, rotações
 * serão importantes, e os utilizaremos. Porém, temos de
 * fazer com que as ARNEs mantenham as 3 propriedades (prin-
 * cipalmente com relação à cor dos ponteiros). */

/* ALGORITMOS DE ROTAÇÃO */
/* Na rotação à esquerda, fazermos voltas APENAS quando
 * houver um ponteiro vermelho na DIREITA. Vamos, então,
 * preservar a distância negra. AS árvores não serão vá-
 * lidas, mas será uma árvore INTERMEDIÁRIA.
 *
 *        |                  |
 *     h (E)                (S) x
 *       / :                : \
 *      /   :     rotL     :   \
 *    | |   (S) x  →   h (E)    | |
 *    | |   / \          / \    | |
 *    []  | | | |      | | | |  [] 
 *      hr| | | |      | | | |hr
 *        []  []       []  []
 * 
 *          |               |          
 *       h (S)             (E) h       
 *         : \             / :         
 *        :   \    rotR   /   :    
 *    x (E)    | |  →   | |   (S) h
 *      / \    | |      | |   / \      
 *    | | | |  []       []  | | | |    
 *    | | | |xr           xr| | | |    
 *    []  []                []  []     
 * 
 * Apesar de violar algumas regras, o RotL será útil para
 * criar a inserção.
 * */

/* Definiremos algumas macros para nos referirmos aos 
 * filhos/netos das árvores: */
#define hl  (h->l)
#define hr  (h->r)
#define hll (h->l->l)
#define hrl (h->r->l)

link rotL(link h)
{
    /* Troca árvores de lugar */
    link x = hr; hr = x->l; x->l = h; 
    /* PRESERVA a cor do nó superior, 
     * colocando como cor do nó supe-
     * rior de 'x' a mesma cor de 'h',
     * que depois da mudança já se 
     * tornou a árvore esquerda de 
     * 'x' (por isso x->l). */
    x->red = x->l->red; x->l->red = 1;
    return x;
}

link rotR(link h)
{
    /* Troca árvores de lugar */
    link x = hr; hr = x->l; x->l = h; 
    /* PRESERVA a cor do nó superior, 
     * colocando como cor do nó supe-
     * rior de 'x' a mesma cor de 'h',
     * que depois da mudança já se 
     * tornou a árvore direita de 
     * 'x' (por isso x->r). */
    link x = hl; hl = x->r; x->r = h;
    x->red = x->r->red; x->r->red = 1;
    return x;
}

/* INSERÇÃO: teremos 3 CASOS:
 * + Inserção em um único 2-nó:
 * a) (B)  TA    (B)
 *    / \  →     : \
 *             (A)
 *             / \
 *
 * b) (A)   (A)          (C)
 *    / \   / :   rotL   : \
 *            (C)  →   (A)
 *            / \      / \
 *
 * + Inserção em árvore com 2 objetos (em um 3-nó)
 *
 * a)   |         |          :
 *     (B)       (B)        (B)
 *     : \  +C   : :        / \
 *   (A)    →  (A) (C) →  (A) (C)
 *   / \       / \ / \    / \ / \
 * 
 * b)    |         |        :          :
 *      (C)  +A   (C)      (B)        (B)
 *      : \  →    : \ →    : :   →    / \
 *    (B)       (B)      (A) (C)    (A) (C)
 *    / \       : \      / \ / \    / \ / \
 *            (A)
 *            / \
 * 
 * + Inserção em um 2-n´o no fundo de árvore
 *  
 *      | |    Como se fosse 2-nó 
 *      | |    o único nó na árvore
 *      / \
 *    ( )
 *    / \
 */
