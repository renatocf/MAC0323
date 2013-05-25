/* Faremos um modelo padrão para tabelas de símbolo.
 * Chamamos de SÌMBOLOS DE 1ª CLASSE uma implementação de
 * tabelas de símbolo que permitam que haja mais de uma
 * tabela ao mesmo tempo. Aqui temos a implementação para
 * apenas UMA:
 */

void STinit(int);
int  STcount();
void STinsert(Item);
Item STsearch(Key);
void STdelete(Item);
Item STselect(int);
void STsort(void(*visit)(Item));

/* Às vezes, quando os 'itens' são estruturas muito pesadas,
 * poe ser interessante fazer uma implementação usando PONTEIROS,
 * e não referências para elas. Isso é muito útil porque torna
 * as operações muito mais rápidas. Ainda assim, é necessário 
 * tomar alguns cuidados, pois ao ceder um ponteiro, podemos mo-
 * dificar a tabela de símbolos externamente. 
 *
 * As tabelas de símbolos são úteis porque permitem uma abstra-
 * ção, dada a utilização das funções. Isso é muito útil porque
 * ignoramos o que é feito na implementação para facilitar a 
 * utilização dos elementos. */
