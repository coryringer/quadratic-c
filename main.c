/**
 * Quadratic program
 * main.c
 * Cory Ringer
 */

#include <stdio.h>
#include <stdlib.h>
#include "quadratic.h"

#define NUM_ARGS 3

int main(int argc, char **argv)
{
    double complex * complex_num;
    double a, b, c;

    printf("ax^2 + bx + c = 0\n");
    printf("Enter a, b, and c: ");

    // Input
    scanf("%lf%lf%lf", &a, &b, &c);

    // Send data to solver, send to complex number
    complex_num = quadratic_solver(a, b, c);

    // Print results
    printf("\nSolving for x gives: \n");
    for (int i = 0; i < LIST_SIZE; i++) {
	printf(
	    "x%d = %.4f + %.4f i\n",
	    i + 1,
	    creal(complex_num[i]),
	    cimag(complex_num[i])
	    );
    }
    
    return 0;
}
