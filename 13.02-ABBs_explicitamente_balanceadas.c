/* O algoritmo de balanceamento pega a mediana
 * do conjunto e a coloca na raiz, usando o 'partR'
 * para fazer as trocas necessárias e colocá-la na
 * raiz. Continuamos assumindo que há o campo 'N'
 * da aula anterior. */

/* prog */
link balanceR(link h)
{
    if(h->N < 2) return h;
    h = partR(h, h->N/2);
    h->l = balanceR(h->l);
    h->r = balanceR(h->r);
    return h;
}

/* É interessante balancear as árvores esporadicamente
 * para que mantenhamos o tempo logarítmico. */

void STbalance()
{ head = balanceR(head); }
