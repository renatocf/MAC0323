/* 
 * Ex:
 *      C(2) ( )
 *           / \
 *          /   \
 *         /     \ D(3)
 *  A(0) ( )     ( )
 *       / \B(1) / \
 *      [] ( )  [] []
 *         / \
 *        [] []
 */

Item selectR(link h, int k)
/* A complexidade deste algoritmo é, em média, LINEAR */
{
    int t;
    if(h == z) return NULLitem;
    t = countR(h->l); /* Conta nº de elementos de h->l */
    
    /* Podemos usar a seleção para o k-ésimo elemento, pois temos 
     * que o 'k' começa com 0 sempre na subárvore esquerda */
    if(k < t) return selectR(h->l, k);
    
    /* Se o 'k' for maior que o 't', então precisamos ajustar 
     * o índice, porque o '0' da árvore original já não está lá,
     * mas sim o t+2-ésimo elemento, que será o menor subárvore
     * à direita. (Por isso, tiramos de 'k' o t+1) */
    if(k > t) return selectR(h->r, k-t-1);
    
    /* Caso o k-ésimo for a própria raiz, só devolvemos seu item */
    return h->item;
}

/* Para o cliente, exportamos: */
Item STselect(int k)
{ return selectR(head, k); }
