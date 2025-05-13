/* Problem 1 from ProjectEuler.net
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5,
 * we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 */

/*
 * This solution uses the arithmetic sum formula and the GCM and LCD of 3 and 5
 */

#include <iostream>
#include <utils.h>

using namespace std;

const int NMAX = 999; // We need to be strictly less than 1000

int main()
{
    int Sum = 0;

    // First sum all integer multiples of 3 less than NMAX
    Sum = 3 * cumSum(1, NMAX / 3);
    // Add all integer multiples of 5 less than NMAX
    Sum += 5 * cumSum(1, NMAX / 5);
    // Subtract the integers with both 3 and 5 as factors less than NMAX
    Sum -= lcm(3, 5) * cumSum(1, NMAX / lcm(3, 5));

    cout << "The sum of all natural numbers that are divisible ";
    cout << "by 3 or 5 and less than 1000 is ";
    cout << Sum << endl;

    return 0;
}
