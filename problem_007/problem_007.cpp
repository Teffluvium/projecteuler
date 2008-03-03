/* 
 * Find the 10001st prime.
 */
 
 /*
  * Simple brute force search for primes
  */

#include <iostream>
#include <cmath>

using namespace std;

const unsigned int NTHPRIME = 10001;

int main()
{
    unsigned int currPrime = 2, 
                 num = 2, 
                 count = 1;
    bool         isPrime = 1;
    double       root = 0;
    
    do
    {
        num++;
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
        }
    } while (count < NTHPRIME);
    
    cout << "The " << NTHPRIME << " is " << currPrime << endl;
    
    return 0;
}
