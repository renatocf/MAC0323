#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "Point.h"
#include "quicksort.h"

long long count_less(point *pontos, int ini, int fim, 
                     int N, float d, int verbose);
long long count_more(point *pontos, int ini, int fim, 
                     int N, float d, int verbose);

int main(int argc, char **argv)
{
    /** VARIÁVEIS *****************************************************/
        int N;          /* Número de pontos                          */
        int i;          /* Batedor para o vetor                      */
        float d;        /* Distância máxima entre pontos             */
        int semente;    /* Semente para geração de nºs aleatórios    */
        int half = 0;   /* Booleano para valor de distância > 0.5    */
        point *pontos;  /* Vetor para armazenar os pontos gerados    */
        long long count = 0; /* Contador de pontos com distância <= 'd'   */
        
    /** OPÇÕES ********************************************************/
        char option;     /* Auxiliar para capturar opções            */
        int verbose = 0; /* Opção de output com informações extras   */
        char usage[] = "desafio [-v] n_points distance rand_seed\n";

        opterr = 0; /* Não imprime mensagem padrão e sai do programa
                       ao encontrar opção desconhecida */
        while((option = getopt(argc, argv, "v")) != -1)
        {
            switch(option) 
            {
                case 'v': 
                    verbose = 1;
                    break;
                case '?':
                    fprintf(stderr, "Unknown option -%c\n", option);
                    fprintf(stderr, "%s\n", usage);
                    break;
            }
        }

        for(i = 0; i < argc; i++)
            printf("argv[%d] == %s ", i, argv[i]);
        
        if(argc-optind+1 != 4) 
        {
            printf("%s\n", usage);
            return EXIT_FAILURE;
        }
       
    /** ALOCAÇÃO ******************************************************/ 
        N = atoi(argv[optind]);
        d = atof(argv[optind+1]);
        
        if(d > sqrt(2)) 
        {
            count = (long long) N*(N-1)/2;
            printf("Nº de pontos com distância < %g: %lli\n", d, count);
            return EXIT_SUCCESS;
        }
        if(d < 0.4 * sqrt(2)) 
            half = 0;
        else if(d > 0.8 * sqrt(2)) 
            half = 1;
        else 
            half = 2;
        
        semente = atoi(argv[optind+2]);
        if(verbose) printf("N:%d, d:%g, semente: %d\n", N, d, semente);
        
        /* Aloca vetor de pontos: */
        pontos = (point *) malloc(N * sizeof(*pontos));
        set_seed(semente);
        for(i = 0; i < N; i++) pontos[i] = r_point();

    /** QUICKSORT *****************************************************/
        if(verbose)
        {
            for(i = 0; i < N; i++) 
                printf("i:%d i.x:%g i.y:%g\n", i, 
                        pontos[i].x, pontos[i].y);
            printf("\n");
        } 
        
        quicksort(0, N-1, pontos); /* Pré-processamento */
        
        if(verbose)
        {
            for(i = 0; i < N; i++) 
                printf("i:%d i.x:%g i.y:%g\n", i, 
                        pontos[i].x, pontos[i].y);
            printf("\n");
        } 
            
    /** CONTAGEM ******************************************************/
        printf("%d\n", half);
        if(half == 0)
            count = count_more(pontos, 0, N, N, d, verbose);
        else if(half == 1)
            count = count_less(pontos, 0, N, N, d, verbose);
        else 
        {
            count += count_more(pontos, N/2, N, N, d, verbose);
            printf("count_more:%lld\n", count);
            count += count_less(pontos, 0, N/2+1, N, d, verbose);
        }

        printf("Nº de pontos com distância < %g: %lli\n", d, count);
            
    /** LIBERAÇÃO DE MEMÓRIA ******************************************/
        free(pontos); pontos = NULL;
        
    return 0;
}

long long count_less(point *pontos, int ini, int fim, 
                     int N, float d, int verbose)
{
    int i, j;            /* Variáveis auxiliares */
    long long count = 0; /* Número de pontos com distância > d */
    long long combs = (long long) N*(N-1)/2;
    
    for(i = fim; i > ini; i--) 
    {
        for(j = i-1; j > 0; j--) 
        {
            if(verbose) printf("distancia(%dx%d): %g\n", i, j,
                        distance(pontos[i], pontos[j]));
            if(d > distance(pontos[i], pontos[j])) break;
            count++;
        }
    }
    return combs - count;
}

long long count_more(point *pontos, int ini, int fim, 
                     int N, float d, int verbose)
{
    int i, j;            /* Variáveis auxiliares */
    long long count = 0; /* Número de pontos com distância > d */
    
    for(i = ini; i < fim; i++) 
    {
        for(j = i+1; j < N; j++) 
        {
            if(verbose) printf("distancia(%dx%d): %g\n", i, j,
                        distance(pontos[i], pontos[j]));
            if(d < distance(pontos[i], pontos[j])) break;
            count++;
        }
    }
    return count;
}
