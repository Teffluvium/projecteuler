/*
 * Problem 50 from ProjectEuler.net
 * 
 * The prime 41, can be written as the sum of six consecutive primes:
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 * 
 * This is the longest sum of consecutive primes that adds to a prime below one-hundred.
 * 
 * The longest sum of consecutive primes below one-thousand that adds to a 
 * prime, contains 21 terms, and is equal to 953.
 * 
 * Which prime, below one-million, can be written as the sum of the most 
 * consecutive primes?
 */

#include <iostream>
#include <cmath>

using namespace std;

void getPrimeList(int N, unsigned long *& pList, int *numPrimes);
bool isPrime(unsigned long N, unsigned long *pList, int pListSize);

const int MAXSIZE = 1000000;
int main()
{
    unsigned long *pList     = 0;   // Create pointer to array to hold primes
    int           numPrimes  = 0;   // Actual number of primes less than MAXSIZE
    
    // Generate all primes less than MAXSIZE
    getPrimeList(MAXSIZE, pList, &numPrimes);
    
    int           sumLength = 0,
                  sumInd    = 0,
                  indLimit  = numPrimes;
    unsigned long sum       = 0,
                  sumMax    = 0;
                  
    // Calculate sum of x primes
    for (int startInd=0; startInd<indLimit; startInd++)
    {
        sumInd = 0;
        sum    = 0;
        do
        {// Calculate the partial sums
            sum += pList[sumInd + startInd];

            if (isPrime(sum, pList, numPrimes) && sumInd>sumLength)
            {// Update length and value of longest prime chain
                sumLength = sumInd + 1;
                sumMax    = sum;
            }
            
            sumInd++;
            
        } while ((sum+pList[sumInd])<MAXSIZE  &&  sumInd<numPrimes);
        
        if (0==startInd)
        {
            // Since we are adding all of the small primes first, 
            // this is the most primes that you can sum to be less than MAXSIZE
            indLimit = sumInd;
        }
        
    }

    cout << endl;
    cout << "Sum length = " << sumLength << endl;
    cout << "Prime sum  = " << sumMax    << endl;
    
    return 0;
}


void getPrimeList(int N, unsigned long *& pList, int *numPrimes)
{
    // Estimate number of primes less than N using prime number thrm
    *numPrimes  = static_cast<int>(N / log(N));
    // Add 10 percent to try and make numPrimes to be an upper bound
    *numPrimes  = static_cast<int>(ceil((*numPrimes)*1.2));
    
    // Create an array with the uninitialized pointer
    pList    = new unsigned long[*numPrimes];
    pList[0] = 2;  // Initialize the array with the first prime number
    
    unsigned int  currInd = 0,
         maxDiv  = 0;
    bool isPrime = 1;
    
    for (int k=3; k<N; k += 2)
    {   // Look for primes
        maxDiv  = static_cast<unsigned long>(ceil(sqrt(k)));
        isPrime = 1;
        
        for (unsigned int ind=0; pList[ind]<=maxDiv  &&  ind<currInd; ind++)
        {   // Compare against known primes
            if (k % pList[ind] == 0)
            {   // k is not prime
                isPrime = 0;
                break;
            }
        } // end ind loop
        
        if (isPrime)
        {   // update the list of known primes
            currInd++;
            pList[currInd] = k;
        }

    } // end k loop
    *numPrimes = currInd;
}

bool isPrime(unsigned long N, unsigned long *pList, int pListSize)
{
    double rtN = ceil(sqrt(N));
    // Check the list
    for (int ind=0; ind<pListSize  &&  pList[ind]<=rtN; ind++)
    {
        if (N<=pList[ind])
        {
            return (N==pList[ind]);
        }
    }

    return 1;
}
