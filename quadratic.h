/**
 * Quadratic program
 * quadratic.h
 * Cory Ringer
 */

#ifndef QUADRATIC_H
#define QUADRATIC_H

#include <complex.h>

// Constant definitions
#define LIST_SIZE 2
#define DENOMINATOR_CONST 2.0
#define NUMERATOR_CONST 4.0

// Utility functions
double descriminant(double, double, double);

// Quadratic solutions
double real_quadratic_one_sol(double, double);
double complex * real_quadratic_two_sol(double, double, double);
double complex * complex_quadratic_two_sol(double, double, double);

// Quadratic solver
double complex * quadratic_solver(double, double, double);

#endif /* QUADRATIC_H */
