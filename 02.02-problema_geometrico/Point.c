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
    new.x = rand()/RAND_MAX;
    new.y = rand()/RAND_MAX;
    
    return new;
}
