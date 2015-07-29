/* Problem 1 from ProjectEuler.net
 * 
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, 
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * 
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

/* 
 * This solution uses the arithmetic sum formula and the GCM and LCD of 3 and 5
 *
 * The correct solution is 233168
 */

#include <iostream>
#include "../libsrc/projectEuler_math.h"

using namespace std;

// int cumSum(int m, int n);
// int gcd(int a, int b);
// int lcm(int a, int b);

const int NMAX = 999;   // We need to be strictly less than 1000

int main()
{
    projectEuler_math pe_math;
    int Sum = 0;

    // First sum all integer multiples of 3 less than NMAX
    Sum =  3        * pe_math.cumSum(1, NMAX / 3);
    // Add all integer multiples of 5 less than NMAX
    Sum += 5        * pe_math.cumSum(1, NMAX / 5);
    // Subtract the integers with both 3 and 5 as factors less than NMAX  
    Sum -= pe_math.lcm(3,5) * pe_math.cumSum(1, NMAX / pe_math.lcm(3,5));
    
    cout << "The sum of all natural numbers that are divisible ";
    cout << "by 3 or 5 and less than 1000 is ";
    cout << Sum << endl;

	return 0;
}

// // Cumulative sum from M to N
// int cumSum(int M, int N)
// {
//     /* Uses the finite arithmetic sum formula from M to N */
//     return (N-M+1)*(M+N)/2;
// }
//
// // Greatest Common Divisor (GCD)
// int gcd(int a, int b)
// {
//     int Remainder;
//
//     while( b != 0 )
//     {
//         Remainder = a % b;
//         a         = b;
//         b         = Remainder;
//     }
//
//     return a;
// }
//
// // Least Common Multiple (LCD)
// int lcm(int a, int b)
// {
//     return (a * b) / gcd(a, b);
// }
