/* Problem 5 from ProjectEuler.net
 * 
 * What is the smallest number divisible by each of the numbers 1 to 20?
 * 
 * The solution is simply the LCM of all the integers from 1 to 20
 */

#include <iostream>
#include <cmath>

using namespace std;

unsigned long gcd(unsigned long a, unsigned long b);
unsigned long lcm(unsigned long a, unsigned long b);

int main()
{
    unsigned long N = 1;
    
    for (unsigned long k=2; k<=20; k++)
    {
        N = lcm(N, k);
    }
    cout << "LCM(1, 2, 3, ... , 20) = " << N << endl;
    
    return 0;
}

// Greatest Common Divisor (GCD)
unsigned long gcd(unsigned long a, unsigned long b)
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

// Least Common Multiple (LCM)
unsigned long lcm(unsigned long a, unsigned long b)
{
    return (a * b) / gcd(a, b);
}
