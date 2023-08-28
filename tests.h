/**
 *\file
 * File test.cpp a file storing functions for testing
 */


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED



/// Macro for changing text color
#define TEXT_COLOR(color, str)  \
    color str RESET_COLOR


/// Macro that creates the test_solve_square structure and starts testing
#define MAC_TEST_SOLVE_SQUARE(a,b,c,x1,x2,nRoots) ({                    \
    struct test_solve_square t = {{a,b,c},{x1,x2},nRoots};              \
    run_test_solve_square(t, &correct_answers, &all_answers);})


/// Macro that creates variables for the number of all tests and valid tests
#define BEGIN_TEST             \
    int correct_answers = 0;   \
    int all_answers = 0;


/// Macro that outputs variable numbers of all tests and valid tests to the console
#define END_TEST                                                                                   \
    printf(GREEN_TEXT "passed %d tests out of %d" RESET_COLOR, correct_answers, all_answers);


#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define RESET_COLOR "\x1b[0m"


const double EPS_TEST = 1e-3;/**< Accuracy of numeric data type in test comparisons */


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
 *Function for solving a quadratic equation
 *\param p - structure stores the parameters of the quadratic equation
 *\param *r - structure storing the values of the roots of a quadratic equation
 */
ROOT_KEYS solve_square (const struct st_params p, struct st_roots *r);


/**
 *Function for solving a quadratic equation
 *\param p - structure stores the parameters of the quadratic equation
 *\param *r - structure storing the values of the roots of a quadratic equation
 */
ROOT_KEYS solve_linear(const double b, const double c, double *x1);


/**
 *Function for comparing two answers (the correct answer and the answer of the function) of type double
 *\param x,y are the numbers being compared
 */
int equality_double_test(const double x, const double y);


/**
 *Function that checks whether the test results match the results of the solve_square function
 *\param t - structure storing the test parameters of the quadratic equation, the correct roots and their number
 */
int test_solver(const struct test_solve_square t);


/**
 *Function that outputs information about the test to the console
 *\param t - structure storing the test parameters of the quadratic equation, the correct roots and their number
 *\param *correct_answers - number of valid tests
 *\param *correct_answers - number of all tests
 */
int run_test_solve_square (const struct test_solve_square t, int *correct_answers, int *all_answers);


int all_tests(void); /**< Function that starts the execution of tests */

/**
 *\brief Structure storing the test parameters of the quadratic equation, the correct roots and their number
 */
struct test_solve_square
{
    struct st_params p;
    struct st_roots r;
    int nRootsRef;
};

/**
 *\brief This structure stores the parameters of the quadratic equation
 */
struct st_params
{
    double a, b, c;
};



/**
 *\brief This structure storing the values of the roots of a quadratic equation
 */
struct st_roots
{
    double x1, x2;
};


#endif // HEADER_H_INCLUDED
