#include <math.h>
#include "lcg.h"

unsigned long find_product_of_unique_prime_factors(unsigned long m)
{
    unsigned long p = 1;
    unsigned long i = 2;

    while (m > 1)
    {
        if (m % i == 0)
        {
            p *= i;
            while (m % i == 0)
            {
                m /= i;
            }
        }
        i++;
    }

    return p;
}

struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c)
{
    struct LinearCongruentialGenerator lcg = {0, 0, 0, 0};

    if (m == 0 || c == 0)
    {
        return lcg;
    }

    unsigned long p = find_product_of_unique_prime_factors(m);
    unsigned long a = 1 + (m % 4 == 0 ? 2 * p : p);

    if (a >= m)
    {
        return lcg;
    }

    lcg.m = m;
    lcg.c = c;
    lcg.a = a;
    lcg.x = c; 

    return lcg;
}


unsigned long getNextRandomValue(struct LinearCongruentialGenerator *lcg)
{
    if (lcg->m == 0 || lcg->c == 0 || lcg->a == 0)
    {
        return 0;
    }

    lcg->x = (lcg->a * lcg->x + lcg->c) % lcg->m;
    int y;
    y=lcg->x;
    lcg->x=0;
    return y;
    
}
