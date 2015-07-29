/*
 * Problem 6 from ProjectEuler.net
 * 
 * The sum of the squares of the first ten natural numbers is,
 *      1² + 2² + ... + 10² = 385
 * 
 * The square of the sum of the first ten natural numbers is,
 *      (1 + 2 + ... + 10)² = 55² = 3025
 * 
 * Hence the difference between the sum of the squares of the first ten 
 * natural numbers and the square of the sum is 3025 - 385 = 2640.
 * 
 * Find the difference between the sum of the squares of the first one 
 * hundred natural numbers and the square of the sum.
 */
 
 /*
  * Using closed form solutions for the cumlative sum and cumulative sum of squares
  *
  * The solution is 25164150
  */
 
#include <iostream>
#include "../libsrc/projectEuler_math.h"

const unsigned int NMAX = 100;

using namespace std;

int main()
{
    unsigned long sumOfSquares = 0;
    unsigned long squareOfSums = 0;
    projectEuler_math pe_math;
    
    squareOfSums =  pe_math.cumSum(1, NMAX);
    squareOfSums *= squareOfSums;
    
    cout << squareOfSums << endl;
    
    sumOfSquares = pe_math.cumSumOfSquares(1, NMAX);
    
    cout << sumOfSquares << endl;
    
    cout << squareOfSums << " - " << sumOfSquares << " = " << squareOfSums - sumOfSquares << endl;
    
    return 0;
}
