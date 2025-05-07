/*
 * Problem 9 from ProjectEuler.net
 *
 * A Pythagorean triplet is a set of three natural numbers, abc, for which,
 *          a² + b² = c²
 *
 * For example, 3² + 4² = 9 + 16 = 25 = 5².
 * 
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

void primitiveTriple(int M, int N, int *A, int *B, int *C);
int gcd(int a, int b);

const int TARGETSUM = 1000;

int main()
{
    int a = 0, b = 0, c = 0;
    int m = 2, n = 1;
    int sum = 0, mult = 0;
    
    for (n=1; n<TARGETSUM; n++)
    {
        for (m=n+1; m<TARGETSUM; m++)
        {
            if (gcd(m,n)==1)
            {
                primitiveTriple(m, n, &a, &b, &c);
                sum = a + b + c;
                if ( (TARGETSUM % sum) == 0)
                {
                    mult = TARGETSUM / sum;
                    a *= mult;
                    b *= mult;
                    c *= mult;
                    
                    cout << "The sum of the Pythagorean Triple is ";
                    cout << a << " + " << b << " + " << c << " = " << a+b+c << endl;
                    cout << "The product of the Pythagorean Triple is ";
                    cout << a * b * c << endl;
                    
                    return 0;
                }
            }
        }
    }
    
    return 1;
}

void primitiveTriple(int M, int N, int *A, int *B, int *C)
{
    /* Given two integers M and N, such that GCD(M,N) = 1, and M > N, 
     * return the values of the primitive Pythagorean Triple to A, B, and C, 
     * where A^2 + B^2 = C^2
     */

     *A = M*M - N*N;
     *B = 2 * M * N;
     *C = M*M + N*N;
}

// Greatest Common Divisor (GCD)
int gcd(int a, int b)
{
    int Remainder;

    while( b != 0 )
    {
        Remainder = a % b;
        a         = b;
        b         = Remainder;
    }

    return a;
}
