#include "utils.h"
#include <cmath>

#include <iostream>

using std::cout;
using std::endl;

void primitiveTriple(int M, int N, int *A, int *B, int *C)
{
    /* Given two integers M and N, such that GCD(M,N) = 1, and M > N,
     * return the values of the primitive Pythagorean Triple to A, B, and C,
     * where A^2 + B^2 = C^2
     */

    *A = M * M - N * N;
    *B = 2 * M * N;
    *C = M * M + N * N;
}

// Greatest Common Divisor (GCD)
int gcd(int a, int b)
{
    int Remainder;

    while (b != 0)
    {
        Remainder = a % b;
        a = b;
        b = Remainder;
    }

    return a;
}

// Cumulative sum from M to N
int cumSum(int M, int N)
{
    /* Uses the finite arithmetic sum formula from M to N */
    return (N - M + 1) * (M + N) / 2;
}

// Least Common Multiple (LCD)
int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

unsigned long powMod(int M, int N, unsigned long D)
{
    unsigned long num = M;
    for (int k = 1; k < N; k++)
    {
        num = (num * M) % D;
    }
    return num;
}

inline float areaTri(const float *a, const float *b, const float *c)
{
    return 0.5 * abs((b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]));
}

unsigned long fibonacci(int n)
{
    const long double rt5 = sqrt(5);
    long double Fn = 0;
    long Fn_int = 0;

    Fn = pow(1.0 + rt5, n);
    Fn -= pow(1.0 - rt5, n);
    Fn /= (pow(2.0, n) * rt5);

    Fn_int = static_cast<unsigned long>(Fn);

    return Fn_int;
}
