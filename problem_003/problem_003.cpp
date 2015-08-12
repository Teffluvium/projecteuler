/*
 * Problem 3 from ProjectEuler.net
 *  * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143?
 * 
 * The algorithm is a brute force check for all factors.  Each factor is then
 * checked for its own factors, thereby testing for primality.
 */
/*
 * The solution is 6857
 */

#include <iostream>
#include <cmath>

unsigned long getFactor(unsigned long n);

const unsigned long BIGNUM = 600851475143;

using namespace std;

int main() {
    unsigned long BigNum = BIGNUM;

    getFactor(BigNum);

    return 0;
}

unsigned long getFactor(unsigned long n) {
    unsigned long Test = 0;
    unsigned long rtN = static_cast<unsigned long>(ceil(sqrt(n)));

    for (Test = 2; Test <= rtN; Test++) {

        if ((n % Test) == 0) {
            cout << Test << " is a factor of " << n << endl;
            getFactor(Test);
        }

    }

    return 0;
}
