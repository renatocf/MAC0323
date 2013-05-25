link joinLR(link a, link b)
{
    if(a == z) return b;
    if(b == z) return a;
    if(gb_unif_rand(a->N + b->N) < a->N) /* Evento de probabilidade 
                                            a->N/(a->N + b->N) */
    { a->r = joinLR(a->r, b);     /* Mesca subárvore direita com b */
      a->N = a->l->N + a->r->N+1; /* Campo N */ 
      return a; 
    } else { 
      a->l = joinLR(a->l, b);
      b->N = b->l->N + b->r->N+1; 
      return b; }
}

link deleteR(link h, key v)
{
    link x; Key t = key(item);
    if(h == z) return z;
    if(less(v,t)) h->l = deleteR(h->l, v);
    if(less(t,v)) h->r = deleteR(h->r,v);
    if(eq(v,t))
    {
        x = h; h = joinR(h->l, h->r); free(x);
        if(h != z) h->l->N + h->r->N + 1;
        return h;
    }
}

void STdelete(Key v)
{ head = deleteR(head, v); }
