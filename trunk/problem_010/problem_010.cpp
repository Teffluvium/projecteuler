/*
 * Problem 10 from ProjectEuler.net
 * 
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * 
 * Find the sum of all the primes below one million.
 */

#include <iostream>
#include <cmath>

using namespace std;

const unsigned int MaxPrime = 1000000;
int main()
{
    unsigned int currPrime = 2, 
                 num       = 3, 
                 count     = 1;
    unsigned long sum = currPrime;
    bool         isPrime   = 1;
    double       root      = 0;
    
    do
    {
        isPrime = 1;
        root    = sqrt(num);
        
        for (unsigned int k=2; k<=sqrt(num); k++)
        {
            if (num % k == 0)
            {
                isPrime = 0;
                break;
            }
        }
        if (isPrime)
        {
            currPrime = num;
            count++;
            sum += currPrime;
        }
        num += 2;
    } while (num < MaxPrime);
    
    cout << "The sum of primes less than " << MaxPrime << " is " << sum << endl;

    return 0;
}
