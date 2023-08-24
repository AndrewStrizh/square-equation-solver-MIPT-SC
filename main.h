/*!
\file
File main.cpp - file with the main function
*/


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


/// Possible number of roots
enum ROOT_KEYS
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS,
};


/*!
Function initializing the parameters of a quadratic equation
\param *params - structure storing the parameters of a quadratic equation
*/
int init_params(struct st_params *params);


/*!
The main function solving the quadratic equation
\param *params - structure storing the parameters of a quadratic equation
\param *roots - structure storing the values of the roots of a quadratic equation
*/
int solver(const struct st_params params, struct st_roots *roots);


/*!
Function that starts the execution of tests
*/
int all_tests(void);


/*!
	\brief This structure stores the parameters of the quadratic equation
*/
struct st_params
{
    double a, b, c;
};


/*!
	\brief This structure storing the values of the roots of a quadratic equation
*/
struct st_roots
{
    double x1, x2;
};


#endif // HEADER_H_INCLUDED
