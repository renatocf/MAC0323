/* Funções de hashing alternativas: */

/* Função de hash universal:
 * Pode ser usado caso, ao mostrar os 
 * histogramas, virmos algum viés sobre
 * as distribuições. Ele é mais lento 
 * que a outra forma. */
int hashU(char *v, int M)
{
    int h = 0, a = 31415, b = 27183;
    for(; *v != '\0'; v++, a = a * b % (M-1))
        h = (a*h + *v) % M;
    return h;
}

/* Função de hash criada por Knuth,
 * do Stanford GraphBase, que usa
 * algumas técnicas para acelerar
 * o cálculo (como shifts e outros
 * truques dependentes da implementa-
 * ção da máquina) */
long hash_Knuth(char *t);
