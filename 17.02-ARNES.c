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
 * a)   |         |                 :
 *     (B)       (B)               (B)
 *     : \  +C   : :   colorFlip   / \
 *   (A)    →  (A) (C)     →     (A) (C)
 *   / \       / \ / \           / \ / \
 * 
 * b)    |         |        |                 :
 *      (C)  +A   (C)      (B)   colorFlip   (B)
 *      : \  →    : \ →    : :      →        / \
 *    (B)       (B)      (A) (C)           (A) (C)
 *    / \       : \      / \ / \           / \ / \
 *            (A)
 *            / \
 * 
 * + Inserção em um 2-nó no fundo de árvore
 *  
 *      | |    Como se fosse 2-nó 
 *      | |    o único nó na árvore
 *      / \
 *    ( )
 *    / \
 */

/* 
 * Para as situações mostradas, teremos o 'colorFlip',
 * que representa transformar um 4-nó de uma árvore 2-3
 * e transformá-lo em 3 2-nó. A situação intermediária
 * de um 4-nó é representada, nas ARNEs, como:
 * 
 *                |                     :
 *  (A B C)  ↔   (B)   →    (B)   ↔    (B)
 *  / | | \      : :        / \        / \
 *             (A) (C)    (A) (C)    (A) (C)
 *             / \ / \    / \ / \    / \ / \
 *    2-3       ARNEs       2-3       ARNEs
 * 
 * Esse color-flip ajuda a justificar a existência destas
 * rotações, porque se adicionássemos um elemento maior
 * e ficasse na configuração de um 4-nó, teríamos:
 * 
 *  (C)      | Para tentar manter a 
 *  / :      | propriedade ESQUERDISTA,
 *    (L)    | precisaríamos fazer uma
 *    / \    | rotação desse nó vermelho
 *  (J) (M)  | para mantermos a proprieda-
 *  / \ / \  | de das ARNEs
 */

void colorFlip(link h)
{
    h->red  = 1-h->red;
    hl->red = 1-hl->red;
    hr->red = 1-hr->red;
}

/* O algoritmo de inserção SIMULARÁ o mesmo processo de 
 * inserção para árvores 2-3: usando uma recursão, pri-
 * meiro BUSCAMOS a posição do nódulo. Ela PODE, ou não,
 * gerar uma árvore insetizfeita, que fere as proprie-
 * dades. Ela pode, então, passar o seu problema para
 * o pai (o que acontece quando há color-flip). Assim,
 * a recursão vai lidando de uma maneira down-top. */

void STinsert(Item item)
{
    head = LLRBinsert(head, item);
    head->red = 0;
    /* Esta inserção é necessária porque uma ARNE só
     * aumenta de altura quando ocorre a geração de 
     * um 4-nó (na abstração de árvore 2-3) / execu-
     * ção de um color-flip (no pensamento de ARNE).
     * O resultado da função color-flip seria um ár-
     * vore cuja raiz tem conexão com aresta vermelha.
     * Como, na última recursão, essa aresta não liga
     * a nada (pois o filho é a raiz), precisamos cor-
     * rigí-la para uma aresta negra. */
}

link LLRBinsert(link h, Item item)
{
    Key v = key(item);
    /* Inserção de um nó novo no fundo (BASE DA RECURSÃO):
     * 
     *      (C)          (C)     } 
     *      / \    ↔     / \     } Árvore a ser
     *    (A) (H)      (A) (H)   } devolvida pe-
     *    / \ / \      / \ / :   } la base do al-
     *                       (L) } goritmo.
     *                       / \ } 
     */
    if(h == z) return NEW(item, z, z, 1); /* Nó vermelho */
    
    /* Inserção recursiva dos nós (PASSO DA RECURSÃO):
     * (vai procurando até encontrar onde será o nó-externo
     * em que inseriremos. Essa estratégia vai 'DESCENDO' da
     * árvore a partir da raiz): */
    if(less(v,key(h->item)))
        hl = LFRBinsert(hl,item);
    else hr = LLRBinsert(hr,item); 
    
    /* Correção dos nós: CORREÇÕES
     * a)    h        
     *      ( )        ( )
     *      / :   →   h: \
     *        ( )    ( )
     *        / \    / \
     *       
     * b)
     *        |          
     *       ( ) h        
     *      .:.            |    
     *      |:|<-.        ( ) hl
     *      ':'  |        : :
     *  hl  ( )  x  →   ( ) ( ) h
     *      :.-. |      / \ / \
     *      :|\|<'
     *      :'-'       
     *    ( )
     *    / \  
     * 
     * (hl->r = h; h->l = NULLItem)
     * 
     * c)    |          :
     *      ( ) h      ( )
     *      : :   →    / \
     *    ( ) ( )    ( ) ( )
     *    / \ / \    / \ / \
     */
    
    /* Casos que podem ocorrer e que, após as
     * recursões, precisam de correções para
     * que se mantenham as propriedades de 
     * ARNEs */
    if(hr->red && !hl->red) h = rotL(h); /*a*/
    if(hl->red && hll->red) h = rotR(h); /*b*/
    if(hl->red && hr->red) colorFlip(h); /*c*/
    
    return h;
}

/* REMOÇÃO em ARNEs*/
/* Algoritmos auxiliares para RETIRAR
 * os 2-nó, criando 4-nó ou 3-nó con-
 * forme os casos */

/* Transforma 2-nó em 3-nó ou 4-nó,
 * levando um ponteiro vermelho para
 * a esquerda */
static link mvRedL(link h)
{
    colorFlip(h);
    if(hrl->red)
        { hr = rotR(hr); h = rotL(h); }
    return h;
}

static link mvRedR(link h)
{
    colorFlip(h);
    if(hll->red) h = rotR(h);
    return h;
}

/* Pega uma árvore com 3-nó e 4-nó
 * e a transforma de volra numa ARNE
 * correta ('balanceando' os ponteiros) */
static link balance(link h)
{
    /* Fazemos ROTAÇÕES e COLORFLIPS para
     * podermos tornar a árvore ESQUERDISTA
     * novamente */
    
    /* Filho à direita é vermelho? */
    if(hr->red) h = rotL(h);
    
    /* Filho à esquerda é vermelho e o 
     * filho esquerdo deste também é 
     * vermelho (sobre o filho incidem
     * 2 ponteiros vermelhos?) */
    if(hl->red && hll->red) h = rotR(h);
    
    /* Ambos os filhos são vermelhos? 
     * (Temos um 4-nó?) */
    if(hl->red && hr->red) colorFlip(h);
    return h;
}

/* Algoritmo RECURSIVO para ir indo 
 * até o MENOR elemento da árvore e 
 * fazedo as modificações que RETIRAM 
 * os 2-nó e que devolve a árvore final 
 * (sem o elemento). */
static link deleteMin(link h)
{
    if(hl == z) { free(h); return z; }
    if(!hl->red && !hll->red) h = mvRedL(h);
    hl = deleteMin(hl);
    return balance(h);
}

void STdeleteMin()
{
    /* Para criarmos os algoritmos no caso
     * de um 2-nó raiz com 2 filhos 2-nó,
     * precisamos das cores invertidas para
     * os color-flips. Assim, trocamos esta
     * cor caso isso ocorra. */
    if(!head->l->red && !head->r->red)
        head->red = 1;
    head = deleteMin(head);
    /* Em algum problema, CORRIGE o ponteiro
     * para a raiz para um ponteiro preto */
    head->red = 0;
}
