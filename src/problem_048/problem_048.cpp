/*
 * Problem 48 from ProjectEuler.net
 *
 * The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
 *
 * Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000
 */

#include <iostream>
#include <utils.h>
// #include <cmath>

using namespace std;
int main()
{
    unsigned long divisor = 10000000000,
                  num = 0;
    int k = 0;

    for (k = 0; k < 1000; k++)
    {
        num = (powMod(k, k, divisor) + num) % divisor;
    }

    cout << num << endl;

    return 0;
}
