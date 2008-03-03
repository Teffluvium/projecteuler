/*
* Problem 50 from ProjectEuler.net
*
* The prime 41, can be written as the sum of six consecutive primes:
* 41 = 2 + 3 + 5 + 7 + 11 + 13
*
* This is the longest sum of consecutive primes that adds to a prime
 * below one-hundred.
*
* The longest sum of consecutive primes below one-thousand that adds to a
* prime, contains 21 terms, and is equal to 953.
*
* Which prime, below one-million, can be written as the sum of the most
* consecutive primes?
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function prototypes
void getPrimeListV(const int N, vector <unsigned long> & pList);
bool isPrimeV(const unsigned long N, const vector <unsigned long> pList);

const unsigned long MAXSIZE = 1000000;

int main() {
   vector <unsigned long> pListV;
   
   // Generate a list of all primes less than MAXSIZE
   getPrimeListV(MAXSIZE, pListV);

   unsigned int  sumLength = 0,
                 sumInd    = 0,
                 indLimit  = pListV.size()-1;
   unsigned long sum       = 0,
                 sumMax    = 0;

   // Calculate sum of x primes
   for (unsigned int startInd=0; startInd<indLimit; startInd++) {
      sumInd = 0;
      sum    = 0;
      do {
         // Calculate the partial sums
         sum += pListV.at(sumInd + startInd);

         if (isPrimeV(sum, pListV) && sumInd>sumLength) {
            // Update length and value of longest prime chain
            sumLength = sumInd + 1;
            sumMax    = sum;
         }

         sumInd++;
      } while ((sum + pListV.at(sumInd))<MAXSIZE  &&  sumInd<pListV.size());

      if (0==startInd) {
         // Since we are adding all of the small primes first,
         // this is the largest number of primes that can be
         // summed to be less than MAXSIZE
         indLimit = sumInd;
      }
   }  // end of for loop

   cout << endl;
   cout << "Sum length = " << sumLength << endl;
   cout << "Prime sum  = " << sumMax    << endl;

   return 0;
}


// Generate a list of all prime numbers less than N
void getPrimeListV(const int        N,
                   vector <unsigned long> & pList) {

   // Create an array with the uninitialized pointer
   // Initialize the array with the first prime number
   pList.push_back(2);
   
   unsigned int  maxDiv  = 0;
   bool          isPrime = 1;

   for (int k=3; k<N; k += 2) {
      // Look for primes
      maxDiv  = static_cast<unsigned long>(ceil(sqrt(k)));
      isPrime = 1;

      for (unsigned int ind=0; pList[ind]<=maxDiv  &&  ind<pList.size(); ind++) {
         // Compare against known primes
         if (k % pList[ind] == 0) {
            // k is not prime
            isPrime = 0;
            break;
         }
      } // end ind loop

      if (isPrime) {
         // update the list of known primes
         pList.push_back(k);
      }

   } // end k loop
}


// Check if a number, N, is prime by comparing it to a previously generated
// list of prime numbers
bool isPrimeV(const unsigned long N,
              const vector <unsigned long> pList) {

   double rtN = sqrt(N) + 1;
   // Check the list
   for (unsigned int ind=0; ind<(pList.size()-1)  &&  pList.at(ind)<=N; ind++) {
      if (pList.at(ind)<rtN) {
         // Check if the smaller primes divide N
         if ((N % pList.at(ind)) == 0) {
            return 0;
         }
      } else if (N<=pList.at(ind)  &&  (pList.at(ind) % N)) {
         // Check if N is in the list for the larger primes
         return (N==pList.at(ind));
      }
   }

   return 1;
}
