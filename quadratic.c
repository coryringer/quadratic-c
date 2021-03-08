/**
 * Quadratic program
 * quadratic.c
 * Cory Ringer
 */

#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include "quadratic.h"

double descriminant(double a, double b, double c)
{ return b * b - (NUMERATOR_CONST * a * c); }

double real_quadratic_one_sol(double a,  double b)
{ return -b / (DENOMINATOR_CONST * a); }

double complex * real_quadratic_two_sol(double a, double b, double c)
{
    static double complex num[LIST_SIZE];
    double sqrt_desc = sqrt(descriminant(a, b, c));
    
    /* Send first real root to first index
     * in array, then change sign of descriminant,
     * move pointer to next index and send second
     * real root to next index in array.
     */
    for (int i = 0; i < LIST_SIZE; i++) {
        num[i] = (-b + sqrt_desc) /
	    (DENOMINATOR_CONST * a);
	
        sqrt_desc = -sqrt_desc;
    }
    
    return num;
}

double complex * complex_quadratic_two_sol(double a, double b, double c)
{
    static double complex num[LIST_SIZE];
    double sqrt_desc = sqrt(fabs(descriminant(a, b, c)));
    
    /* Send first complex root to first index
     * in array, then change sign of descriminant,
     * move pointer to next index and send second
     * real root to next index in array.
     */
    for (int i = 0; i < LIST_SIZE; i++) {
	num[i] = real_quadratic_one_sol(a, b) +
	    (sqrt_desc /
	     (DENOMINATOR_CONST * a)) * I;

        sqrt_desc = -sqrt_desc;
    }
    
    return num;
}

double complex * quadratic_solver(double a, double b, double c)
{
    double complex * num = calloc(
        LIST_SIZE,
        LIST_SIZE * sizeof(double complex)
	);
    double desc = descriminant(a, b, c);
    
    if (a == 0) {
	return num;
    } else if (desc == 0) {
	num[0] = real_quadratic_one_sol(a, b);
    } else if (desc > 0) {
	num = real_quadratic_two_sol(a, b, c);
    } else if (desc < 0) {
	num = complex_quadratic_two_sol(a, b, c);
    }

    return num;
}
