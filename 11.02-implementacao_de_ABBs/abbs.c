/* prog 12.7.c */

typedef struct STnode *link;
struct STnode { Item item; link l, r; }

static link head, z;
/* head é um ponteiro para a raiz da árvore. 'z' é um nó geral
 * que representa todos os nósexterdos. Esta implementação ad-
 * mite apenas, e tão somente apenas, 1 árvore. O uso de 'static'
 * é para que estas não sejam acessíveis ao cliente. */

static link NEW(Item item, link l, link r)
{
    link x = malloc(sizeof *x);
    x->item = item; x->l = l; x->r = r;
    return x;
}

void STinit()
{
    head = (z = NEW(NULLitem, NULL, NULL));
}

static int countR(link h)
{
    if(h == z) return 0;
    return 1 + countR(h->l) + countR(h->r);
    /* Algoritmo recursivo para a contagem:
     * 
     *        |---------------|
     *        |      ( )      | Somamos 1 para cada
     *        |      / \      | chamada e também o 
     *        |     /   \     | mesmo resultado para
     *        |    /     \    | as subárvores às quais
     *        |-------|-------| a raiz está ligada 
     *        |  ( )  |  ( )  | (exceto para os nós 
     *        |  / \  |  / \  | externos, que não são
     *        |---|---|---|---| contados).
     *        |[z]|[z]|[z]|[z]|
     *        |---|---|---|---|
     */
}

int STcount() { return countR(head); }

static Item searchR(link h, key v)
{
    Key t = key(h->item);
    if(h == z) return NULLitem;
    if(eq(v,t)) return h->item;
    if(less(v,t)) return searcR(h->l,v);
    else return searchR(h->r,v);
    /* Algoritmo recursivo para busca:
     *
     *      |---------------|
     *      |      ( )      | Vamos olhando o valor
     *      |      / \      | de cada um, a partir
     *      |     /   \     | da raiz, e dividindo
     *      |    /     \    | para uma das subárvores
     *      |-------|-------| conforme o valor.
     *      |  ( )  |  ( )   
     *      |  / \  |  / \   
     *      |---|---| /   \  
     *       [z]|[z]|[z] [z] 
     *          |---|          
     */
}

static Item STsearch(Key v) { return searchR(head,v); }

link insertR(link h, Item item)
{
    Key v = key(item), t = key(h->item);
    
    /* Para inserir num nódulo externo, colocamos
     * 'item' num novo nódulo, sendo que este aponta
     * para os dois nódulos externos. */
    if(h == z) return NEW(item, z, z);
    
    /* Caso o elemento não seja 'h', continua o processo */
    if(less(v,t)) h->l = insertT(h->l, item);
    else h->r = insertT(h->r, item);
    
    /* 
     *      |---------------|   Vamos varrendo a árvore
     *      |      ( )      |   e comparando a key do item
     *      |      / \      |   a ser inserido as chaves
     *      |     /   \     |   das outras também. Quando 
     *      |    /     \    |   chega em algum nó externo,
     *      |-------|-------|   insere a nova árvore neste
     *      |  ( )  |  ( )      ponto.
     *      |  / \  |  / \   
     *      |---|---| /   \  
     *       [z]|( )|[z] [z] 
     *          |/ \|---------> Novo elemento        
     *          |---|
     *      
     *      Esse algoritmo tem um problema, pois pode gerar 
     *      árvores degeneradas (se os elementos forem inse-
     *      ridos em ordem crescente/decrescente):
     *      
     *      |----------------|
     *      |   ( )          |
     *      |   / \          |
     *      | [z]  \         |
     *      |       \        |
     *      |----|-----------|
     *           |  ( )      |
     *           |  / \      |
     *           |[z]  \     |
     *           |---|-------|
     *               |  ( )  |
     *               |  / \  |
     *               |[z] [z]|
     *               |-------|
     */
    
    return h;
}

void STinsert(Item item) { head = insertR(head, item); }

static void sortR(link h, void (*visit)(Item))
{
    if(h == z) return;
    /* Chama a função 'visit' para o nó interno e, 
     * após, fazemos o 'sortR' para as outras */
    sortR(h->l, visit);
    visit(h->item);
    sortR(h->r, visit);
}

void STsort(void (*visit (Item))) { sortR(head, visit); }

/* EXERCÍCIO: fazer a STselect()
 * A construção do STdelete é mais difícil */
