/* prog 12.15 */

link joinLR(link a, link b)
{ if(b == z) return a;
  b = partR(b,0);
  b->l = a;
  return b;
} /* Exercício: ajustar o campo N */

link deleteR(link h, Key r)
{ link x; Key t = key(h->item); 
  if(h == z) return z;
  if(less(v,t)) h->l = deleteR(h->l, r);
  if(less(t,v)) h->r = deleteR(h->r, r);
  if(eq(v,t)) { x = h; h = joinLR(h->l, h->r); free(x) }          
  return h;
}

item STdelete(Key r)
{ return deleteR(head, r); }
