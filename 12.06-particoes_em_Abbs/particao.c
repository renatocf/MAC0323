/* Prog 12.14 */

/* Não precisaremos verificar se houve ou não algum tipo de 'k'
 * inválido. Como ele será de utilização interna, não exporta-
 * remos ele */
link partR(link h, int k)
{ int t = h->l->N; 
  if(k < t) { h->l = partR(h->l, k); h = rotR(h->l); }
  if(k > t) { h->r = partR(h->r, k-t-1); h = rotL(h); }
  return h;
}
