#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include "Point.h"

float distance(point a, point b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;

    return sqrt(dx*dx + dy*dy);
}

point r_point()
{
    point new;
    new.x = 1.0 * rand()/RAND_MAX;
    new.y = 1.0 * rand()/RAND_MAX;
    
    return new;
}

void set_seed(int seed)
{
    srand(seed);
}
