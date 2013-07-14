/* prog 14.4 */

#define null(A) ((st[(A)]) == (NULLitem))

static int N, M;
static Item *st; /* Vetor para o probing linear */

void STinit(int max)
{
    int i;
    N = 0; M = 2*max;
    /* Para evitar viés, seria ideal usar um 'M' primo.
     * Para tanto, é interessante utilizar a função 'prime_m',
     * do livro do Sedgewick, que busca um primo próximo (maior)
     * desse número */
    
    st = malloc(M * sizeof(Item));
    for(i = 0; i < M; i++)
        st[i] = NULLitem;
    /* Padrão de inicialização: NULLitem */
}

/* CONTAGEM */
int  STcount() { return N; }

/* INSERÇÃO */
void STinsert(Item item)
{
    Key v = key(item); int i = hash(v,M);
    /* AS funções de hashing são as mesmas de outros módulos */
    while(!null(i)) i = (i+1) % M;
    /* Percorremos até achar NULLitem. Supomos que NÃO há 
     * mais que N itens (e nem haverá), ou entramos em loop */
    st[i] = item; N++:
    /* Inserimos o item na posição */
}

/* BUSCA */
Item STsearch(Key v)
{
    int i = hash(v, M);
    /* Buscamos no bloco contíguo iniciado
     * pela chave até encontrarmos um NULLitem
     * ou o objeto. Se o objeto o estiver, re-
     * tormamos. Caso contrário, ao chegar em
     * NULLitem, devolvemos NULLitem. */
    while(!null(i))
        if(eq(v,key(st[i])))
            return st[i];
        else i = (i+1) % M;
    return NULLitem;
}

/* REMOÇÃO 
 *
 * A remoção natural seria colocar um NULLitem
 * que quebraria o bloco.
 * Isso, entretanto, não funcionaria: os objetos
 * de mesma chave que estavam no bloco contíguo
 * não seriam encontrados mais (pois pararíamos 
 * no NULLitem). Além disso, não poderíamos ape-
 * nas trocar o último elemento do bloco porque
 * ele não necessariamente teria a mesma chave,
 * dado que eles podem se misturar. 
 * 
 * Precisamos supor que o objeto esteja presente
 */
void STdelete(Item item)
{
    int j, i = hash(key(item),M); Item v;
    
    /* Faz a busca do elemento */
    while(!null(i))
        if(eq(key(item)),key(st[i])) 
            break;
        else i = (i+1) % M;
    
    /* Faz a remoção do item */
    st[i] = NULLitem; N--; /* PROBLEMA: N-- */
    
    /* Remove/reinsere os elementos */
    for(j = i+1; !null(j); j = (j+1) % M, N--)
        { v = st[j]; st[j] = NULLitem; STinsert(v); }
}
