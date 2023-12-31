/**
 *\file
 * File main.cpp - file with the main function
 */


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


/**
 *\enum
 * Possible number of roots
 */
enum ROOT_KEYS
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};


/**
 *Function initializing the parameters of a quadratic equation
 *\param *params - structure storing the parameters of a quadratic equation
 */
int init_params(struct Params *params);


/**
 *\brief The main function solving the quadratic equation
 *\param *params - structure storing the parameters of a quadratic equation
 *\param *roots - structure storing the values of the roots of a quadratic equation
 */
int solve(const struct Params params, struct Roots *roots);


/**
 *Function that starts the execution of tests
 *\param *filename - the address of the file, name entered by the user
 */
int all_tests(const char* filename);


/**
 *\brief This structure stores the parameters of the quadratic equation
 */
struct Params
{
    double a, b, c;
};


/**
 *\brief This structure storing the values of the roots of a quadratic equation
 */
struct Roots
{
    double x1, x2;
};


/**
 *\brief Structure storing the test parameters of the quadratic equation, the correct roots and their number
 */
struct test_solve_square
{
    struct Params p;
    struct Roots r;
    int nRootsRef;
};


#endif // HEADER_H_INCLUDED
