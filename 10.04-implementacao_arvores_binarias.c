/* prog 12.7 */

typedef struct STnode *link;
struct STnode { Item item; link l, r; }
static link head, z;

/* Busca: */
static Item searchR(link h, key r)
{
    key t = key(h->item);
    
    /* Nódulo é nódulo externo - acabaram os nódulos externos */
    if(h == z) return NULLItem;
    
    /* Se a key for igual à chave, achamos o elemento */
    if(eq(r,t)) return h->item;
    
    /* Vemos se devemos repetir o processo para a direita 
     * ou para a esquerda, fazendo a recursão */
    if(less(r,t)) return searchR(h->l, r);
    else return searchR(h->r, r);
}

Item STseach(Key r)
{ return (head, r); }
