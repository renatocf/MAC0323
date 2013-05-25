/* ALOCAÇÃO DINÂMICA DE MEMÓRIA P/ MATRIZES
 *
 * vetores: int *v;
 *          ... ,,,,,,- opcional (o C o faz sozinho)
 *          v = (int *) malloc(100 * sizeof(int));
 *          ...
 *   v
 * |   |     |       |
 *   ^-----> |       | 0  }
 * ponteiro  |       | 1  } Bloco para 100 inteiros
 *  p/ 1º    |       | 2  }
 * elemento  |       | 3  }
 *    do        ...             8º elemento == v[7] ≡ *(v+7)
 *  bloco    |       | 99 }
 * 
 * --------------------------------------------------------------------
 * matrizes: int M[3][4];
 * 
 *   Matrizes estáticas
 *    __ __ __ __
 *   [  |  |  |  ] } Matriz 3x4 feito com inteiros. Cada posição
 *   [  |  |  |  ] } na localização M[x][y], estamos acessando a
 *   [  |  |  |  ] } posição [x][y] na "tabela" criada.
 *    ¨¨ ¨¨ ¨¨ ¨¨
 *   Na realidade, a real aparência delas é:
 *   
 *    M
 *   |  | --^^
 *          ||
 *    M[1] |  | --> |  |  |  |  |  |  |  |  |  |
 *    M[2] |  | --> |  |  |  |  |  |  |  |  |  |
 *    ...   ..       .. .. .. .. .. .. .. .. ..
 *    M[3] |  | --> |  |  |  |  |  |  |  |  |  |
 *    
 *   Sendo que o ponteiro criado aponta para um vetor de ponteiros
 *   para inteiros, que por sua vez aponta para um vetor de inteiros.
 */

/* prog3.16 */
int ** malloc2d(int r, int c)
{
    int i;
    int **t = (int **) malloc(r * sizeof(int *));
    for(i = 0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    
    return t;
}
