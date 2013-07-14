/* Esta forma está implementada como tipo simples */

int   length     (void);
int   arr_index  (int i);
char *select     (int i);
int   rank       (char *key);
int   lcp2       (char *s, char *t); /* auxiliar: NÃO EXPORTAR */
int   lcp        (int i);
void  suff_array (char *t)

/* select: devolve o n-ésimo elemento do vetor de sufixos;
 * rank("string"): devolve todas as palavras iniciadas por 
 *                 'string'
 * array_index(n): devolve a posição na tabela de sufixos do
 *                 sufixo iniciado no caractere n da palavra
 * lcp2(s, t): acha o maior prefixo entre s e t
 * lcp(i): comprimento do prefixo comum mais longo entre o i-ésimo 
 *         e o (i-1)-ésimo sufixo ordenados
 * suf_array: monta a tbela.
 */
