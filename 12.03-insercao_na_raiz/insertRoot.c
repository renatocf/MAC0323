/* prog 12.12 */

void STinsert(Item item)
{ head = insertR(head, item); }

link insertR(link h, Item item)
{   
    Key v = key(item);
    if(h == z) return NEW(item, z, z);
    
    if(less(v,key(h->item))) { 
        h->l = insertR(h->l, item); h = rotR(h);
    } else {
        h->r = insertR(h->r, item); h = rotL(h);
    }
    
    return h;
}

/* EXERCÍCIO
 * Criar uma versão ITERATIVA deste algoritmo */

/* Se quiséssemos, porém, manter os dois tipos, poderíamos criar mu-
 * dar os nomes para 'insertT' (inserindo, além de na raiz, em um 
 * nódulo qualquer e mantendo o elemento lá). */
