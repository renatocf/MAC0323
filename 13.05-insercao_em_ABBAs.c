/* Lembrando: insertT(): inserção na raiz */
link insertR(link h, Item item)
{
    Key v = key(item), t = key(h->item);
    if(h == z) return NEW(item, z, z, 1);
    /* Gera um número aleatório entre 0 <= x < argumento */
    if(gb_unif_rand(h->N+1) == 0) /* evento de probabilidade 1/(h->N+1) */
        return insertI(h, item);
    if(less(v,t)) h->l = insertR(h->l, item);
    else h->r = insertR(h->r, item);
    (h->N)++; return h;
}

void STinsert(Item item)
{ head = insertR(head, item); }

/* INSERÇÃO EM ABBAs:
 * Ao inserir em árvores de busca aleatoriezadas, temos duas possibi-
 * lidades, que ocorrem de acordo com uma probabilidade:
 * 
 * 1) Inserir na raiz (com prob. 1/N)
 *      Usamos, neste caso, o algoritmo de reinserção da raiz.
 *      A raiz antiga NUNCA volta mais a ser raiz daquela subárvore.
 * 2) Inserir nas subárvores (com prob. 1 - 1/N)
 *      O algoritmo é repetido recursivamente na subárvore esquerda
 *      ou direita. A decisão de para qual subárvore iremos depende
 *      de se a chave do item é menor ou maior que a raiz.
 * 
 * Ex: Inserir os números 44 11 33 22 para gerar:
 *                       
 *                            (44)
 *                            /
 *                          (22)
 *                          /  \
 *                       (11)  (33)    
 *        
 * ∅  →  (44)  →      (44)          (44)
 *            1/2      /    1/3      /
 *                 (11)     →    (33)
 *                               /
 *                            (11)
 *                1/3 ↓             ↓  1/4
 *                                
 *                    (44)          (44)
 *                    /    1/4      /
 *                 (11)     →     (22)
 *                    \           /  \
 *                    (33)     (11)  (33)   
 * 
 * Para gerar a última árvore, temos que:
 * 1) O 44 não pode ter sido inserido senão na raiz, pois caso 
 *    contrário não voltaria a ser raiz. (probabilidade 1)
 *  
 * 2) Inserimos o 11 não na raiz, mas na subárvore.
 *    (probabilidade 1/2)
 * 
 * 3) Temos duas possibilidades:
 *    3.1) Inserimoso 33 na raiz (com prob. 2/3*1/2);
 *    3.2) Inserimos 33 na subárvore (com prob. 2/3*1/2).
 *  
 * 4) Para cada caso, só temos uma possibilidade:
 *    Inserimos 22 na raiz (com probabilidade 3/4*1/3).
 *  
 * A conformação desa árvore é o Σ dessas probabilidades:
 *                  2 * (1/2 * 1/6 * 1/4) = 1/12
 */

