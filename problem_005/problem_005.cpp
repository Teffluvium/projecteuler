/* Problem 5 from ProjectEuler.net
 * 
 * What is the smallest number divisible by each of the numbers 1 to 20?
 * 
 * The solution is simply the LCM of all the integers from 1 to 20
 */

#include <iostream>
#include "../libsrc/projectEuler_math.h"

using namespace std;

int main()
{
    unsigned long N = 1;
    projectEuler_math pe_math;
    
    for (unsigned long k=2; k<=20; k++)
    {
        // N = lcm(N, k);
        N = pe_math.lcm( N, k );
    }
    cout << "LCM(1, 2, 3, ... , 20) = " << N << endl;
    
    return 0;
}
