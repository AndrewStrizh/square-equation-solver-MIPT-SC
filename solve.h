/**
 *\file
 *File solve.cpp containing functions for solving linear and quadratic equations
 */


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


///Macro for changing text color
#define TEXT_COLOR(color, str)      \
    color str RESET_COLOR

#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define RESET_COLOR "\x1b[0m"

const double EPS_ALL = 1e-6; /**< Accuracy of the numerical data type */


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
ROOT_KEYS solve_linear(const struct st_params p, struct st_roots *r);


/**
 *Function for comparing two numbers of type double
 *\param x,y - compared numbers
 */
int equality_double(const double x, const double y);


/**
 *The main function solving the quadratic equation
 *\param *params - structure storing the parameters of a quadratic equation
 *\param *roots - structure storing the values of the roots of a quadratic equation
 */
int solver(const struct st_params params, struct st_roots *roots);


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
