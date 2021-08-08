/* sqrt_eq.c */
/* Program solves quadratic equations of the form ax^2 + bx +c = 0 */
/* After starting, enter three numbers (equation coefficients a, b and c) */
/* If the equation has a solution, the roots will be displayed. */
/* Roots are displayed with 5-digit precision. */
/* Library is used for compilation: -lm */
#include <stdio.h>
#include <math.h>

double discrim (double a, double b, double c)
{
    return b * b - 4 * a * c;
}
int main()
{
    double a, b, c, d;
    int n;
    n = scanf ("%lf %lf %lf", &a, &b, &c);
    if (n != 3) {
        printf ("Error: wrong input.\n");
        return 2;
    }
    if (a == 0) {
        printf ("It's not a quadratic equation!\n");
        return 2;
    }
    d = discrim (a,b,c);
    if (d < 0) {
        printf ("No roots\n");
        return 0;
    }
    d = sqrt (d);
    printf ("%.5f %.5f\n", ( - b - d ) / (2 * a ), ( - b + d ) / ( 2 * a ));
    return 0;
}
