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
 * natural numbers and the square of the sum is 3025 385 = 2640.
 * 
 * Find the difference between the sum of the squares of the first one 
 * hundred natural numbers and the square of the sum.
 */
 
 /*
  * Using closed form solutions for the cumlative sum and cumulative sum of squares
  */
 
#include <iostream>
#include <cmath>

unsigned long cumSum(int M, int N);
unsigned long cumSumOfSquares(int M, int N);

const unsigned int NMAX = 100;

using namespace std;
 
int main()
{
    unsigned long sumOfSquares = 0,
                  squareOfSums = 0;
    
    squareOfSums =  cumSum(1, NMAX);
    squareOfSums *= squareOfSums;
    
    cout << squareOfSums << endl;
    
    sumOfSquares = cumSumOfSquares(1, NMAX);
    
    cout << sumOfSquares << endl;
    
    cout << squareOfSums << " - " << sumOfSquares << " = " << squareOfSums - sumOfSquares << endl;
    
    return 0;
}
 
// Cumulative sum from M to N
unsigned long cumSum(int M, int N)
{
    // Uses the finite arithmetic sum formula from M to N
    return (N-M+1)*(M+N)/2;
} 

unsigned long cumSumOfSquares(int M, int N)
{
    // Uses closed form solution
    return (N * (N+1) * (2*N+1) - (M-1) * M * (2*M-1) ) / 6;
}
