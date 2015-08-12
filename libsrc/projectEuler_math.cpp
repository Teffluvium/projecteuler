//
// Created by tim on 7/28/15.
//

#include "projectEuler_math.h"
#include <cmath>

// Greatest Common Divisor (GCD)
unsigned long projectEuler_math::gcd(unsigned long a, unsigned long b) {
    unsigned long Remainder;

    while( b != 0 )
    {
        Remainder = a % b;
        a         = b;
        b         = Remainder;
    }

    return a;
}

// Cumulative sum from M to N
unsigned long projectEuler_math::cumSum(unsigned long M, unsigned long N) {
    /* Uses the finite arithmetic sum formula from M to N */
    return (N-M+1)*(M+N)/2;
}

// Cumulative sum of squares from M to N
unsigned long projectEuler_math::cumSumOfSquares(unsigned long M, unsigned long N) {
    /* Uses closed form solution */
    return (N * (N+1) * (2*N+1) - (M-1) * M * (2*M-1) ) / 6;
}

// Least Common Multiple (LCD)
unsigned long projectEuler_math::lcm(unsigned long a, unsigned long b) {
    return (a * b) / projectEuler_math::gcd(a, b);
}

// Calculate the Nth Fibonacci number
unsigned long projectEuler_math::fibonacci( const int N ) {
    // Uses closed-form solution of Binet's formula:
    //     Fn = ( phi^N - psi^N ) / sqrt(5);
    const long double rt5    = sqrt(5);
    const long double phi    = ( 1.0 + rt5 ) / 2.0;
    const long double psi    = ( 1.0 - rt5 ) / 2.0;
    long double       Fn     = 0;
    unsigned long     Fn_int = 0;

    Fn  = pow( phi, (double) N );
    Fn -= pow( psi, (double) N );
    Fn /= rt5;

    // Round to the nearest integer
    Fn = round( Fn );

    // Re-cast as unsigned long
    Fn_int = static_cast<unsigned long> (Fn);

    return Fn_int;
}

// Check if an integer is a palindrome
bool projectEuler_math::isPalindromeInt(unsigned long num) {
    int powerOfTen     = 0;
    int k              = 0;
    unsigned long high = 0;
    unsigned long low  = 0;

    powerOfTen = static_cast<int>(floor(log10(num)));

    do
    {
        low  = num / static_cast<int>(pow(10.0, k))              % 10;
        high = num / static_cast<int>(pow(10.0, powerOfTen - k)) % 10;

        k++;
    } while (low == high  &&  k<ceil(powerOfTen/2.0));

    return ( low == high );
}

void projectEuler_math::primitiveTriple(unsigned long M, unsigned long N, unsigned long *A, unsigned long *B, unsigned long *C) {
    /* Given two integers M and N, such that GCD(M,N) = 1, and M > N,
     * return the values of the primitive Pythagorean Triple to A, B, and C,
     * where A^2 + B^2 = C^2
     */

    *A = M*M - N*N;
    *B = 2 * M * N;
    *C = M*M + N*N;
}

unsigned long projectEuler_math::powMod(int M, int N, unsigned long D)
{
    /*
     * Calculate mod( M^N, D )
     */
    unsigned long num = M;
    for (int k=1; k<N; k++)
    {
        num = (num * M) % D;
    }
    return num;
}
