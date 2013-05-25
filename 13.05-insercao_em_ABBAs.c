/* Lembrando: insertT(): inserção na raiz */
link insertI(link h, Item item)
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
