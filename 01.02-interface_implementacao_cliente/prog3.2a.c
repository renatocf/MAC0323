#include<stdio.h>
#include<stdlib.h>
#include "Num.h"

int main(int argc, char **argv)
{
    int i, N = atoi(argv[1]);
    float m = 0.0;
    numType x;
    
    for(i = 0; i < N; i++)
    {
        x = leia(); m+= x;
    }
    
    printf("Media = %g", n/N);
    
    return 0;
}
