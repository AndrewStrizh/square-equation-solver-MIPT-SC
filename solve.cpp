#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "solve.h"
int equality_double(const double x, const double y)
{
    assert(isfinite (x));
    assert(isfinite (y));
    assert(!isnan (x));
    assert(!isnan (y));

    return fabs(x - y) < EPS_ALL;
}


ROOT_KEYS solve_square (const struct st_params p, struct st_roots *r)
{
    assert(isfinite (p.a));
    assert(isfinite (p.b));
    assert(isfinite (p.c));
    assert(isfinite (r -> x1));
    assert(isfinite (r -> x2));
    assert(!isnan (p.a));
    assert(!isnan (p.b));
    assert(!isnan (p.c));
    assert(!isnan (r -> x1));
    assert(!isnan (r -> x2));

    if(equality_double(p.a, 0))
        return solve_linear(p, r);
    else
    {
        double a2 = p.a * 2;
        const double discr = p.b * p.b - 2 * a2 * p.c;
        if(equality_double(discr, 0))
        {
            if (equality_double(p.b, 0))
                r -> x1 = p.b;
            else
                r -> x1 = -p.b / a2;
            return ONE_ROOT;
        }
        else if(discr > EPS_ALL)
        {
            const double sq_discr = sqrt(discr);
            r -> x1=(-p.b - sq_discr) / a2;
            r -> x2=(-p.b + sq_discr) / a2;
            return TWO_ROOTS;
        }
        else
            return ZERO_ROOTS;
    }
}


ROOT_KEYS solve_linear(const struct st_params p, struct st_roots *r)
{
    assert(isfinite (p.b));
    assert(isfinite (p.c));
    assert(isfinite (r->x1));
    assert(!isnan (p.b));
    assert(!isnan (p.c));
    assert(!isnan (r->x1));

    if(equality_double(p.b, 0))
    {
        if(equality_double(p.c, 0))
            return INF_ROOTS;
        else
            return ZERO_ROOTS;
    }
    else
    {
        if (equality_double(p.c, 0))
            r->x1 = p.c;
        else
            r->x1 = -p.c / p.b;
        return ONE_ROOT;
    }
}

int solver(const struct st_params params, struct st_roots *roots)
{
    assert(isfinite (params.a));
    assert(isfinite (params.b));
    assert(isfinite (params.c));
    assert(isfinite (roots->x1));
    assert(isfinite (roots->x2));
    assert(!isnan (params.a));
    assert(!isnan (params.b));
    assert(!isnan (params.c));
    assert(!isnan (roots->x1));
    assert(!isnan (roots->x2));


    int nRoots = solve_square (params, roots);
    switch (nRoots)
        {
        case ZERO_ROOTS: printf("There are no roots\n");
                break;

        case ONE_ROOT: printf("x = %lf\n", roots->x1);
                break;

        case TWO_ROOTS: printf("x1 = %lf\tx2 = %lf\n", roots->x1, roots->x2);
                break;

        case INF_ROOTS: printf("Number of roots: infinity");
                break;

        default:
                break;

        }

    return 0;
}
