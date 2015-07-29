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

/*
 * The solution is 31875000
 */

#include <iostream>
#include <cmath>
#include <projectEuler_math.h>

using namespace std;

const int TARGETSUM = 1000;

int main()
{
    unsigned long a = 0, b = 0, c = 0;
    unsigned long m = 2, n = 1;
    unsigned long sum = 0, mult = 0;
    projectEuler_math pe_math;

    for (n=1; n<TARGETSUM; n++)
    {
        for (m=n+1; m<TARGETSUM; m++)
        {
            if (pe_math.gcd(m,n) == 1)
            {
                pe_math.primitiveTriple(m, n, &a, &b, &c);
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
