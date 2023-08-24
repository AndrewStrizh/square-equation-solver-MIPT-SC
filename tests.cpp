#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "tests.h"

int equality_double_test(const double x, const double y)
{
    assert(isfinite (x));
    assert(isfinite (y));
    assert(!isnan (x));
    assert(!isnan (y));

    return fabs(x - y) < EPS_TEST;
}


int run_test_solve_square (const struct test_solve_square t, int *correct_answers, int *all_answers)
{
    if (test_solver(t) == 0)
    {
          printf(TEXT_COLOR(GREEN_TEXT, "test passed\n"));
          ++(*correct_answers);
    }
    ++(*all_answers);
    return 0;
}

int test_solver(const struct test_solve_square t)
{
    struct st_roots x;
    int nRoots = solve_square(t.p, &x);
    if (!equality_double_test(x.x1, t.r.x1) ||
        !equality_double_test(x.x2, t.r.x2) ||
        t.nRootsRef != nRoots)
    {
        printf(TEXT_COLOR(RED_TEXT,"FAILURE: a=%lf; b = %lf; c = %lf\n"), t.p.a, t.p.b, t.p.c);
        return 1;
    }
    else
        return 0;
}

int all_tests(void)
{
    BEGIN_TEST;
    MAC_TEST_SOLVE_SQUARE(0, 1, 0, 0, 0, 1);
    MAC_TEST_SOLVE_SQUARE(1, 0, 0, 0, 0, 1);
    MAC_TEST_SOLVE_SQUARE(0, 0, 1, 0, 0, 0);
    MAC_TEST_SOLVE_SQUARE(-1, 0, 0, 0, 0, 1);
    MAC_TEST_SOLVE_SQUARE(0, -1, 0, 0, 0, 1);
    MAC_TEST_SOLVE_SQUARE(1, 2, -3, -3, 1, 2);
    MAC_TEST_SOLVE_SQUARE(1, 2, -4, -3.2361, 1.2361, 2);
    //MAC_TEST_SOLVE_SQUARE(1, 0, -16, -4, 4, 1);
    END_TEST;
    return 0;
}
