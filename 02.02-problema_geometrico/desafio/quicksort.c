#include "Point.h"

int compara(point p1, point p2)
{
    if(p1.x < p2.x) return 1;
    if(p1.x == p2.x && p1.y <= p2.y) return 1;
    return 0;
}

int separa(int ini, int fim, point *v)
{
    int i = ini-1, j;
    point aux, pivo = v[fim];
    
    for(j = ini; j <= fim; j++)
    {
        if(compara(v[j],pivo))
        {
            i++; aux = v[i]; v[i] = v[j]; v[j] = aux;
        }
    }
    
    return i;
}

void quicksort(int ini, int fim, point *v)
{
    int esquerda, direita, pivo;
    if(ini < fim)
    {
        /* Organiza o vetor */
        pivo = separa(ini, fim, v);
        esquerda = pivo - 1; direita = pivo + 1;

        /* Chamada recursiva */
        quicksort(ini, esquerda, v);
        quicksort(direita, fim, v);
    }
}
