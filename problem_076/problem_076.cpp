/* 
 * Problem 76 from ProjectEuler.net
 * 
 * It is possible to write five as a sum in exactly six different ways:
 *
 *    4 + 1
 *    3 + 2
 *    3 + 1 + 1
 *    2 + 2 + 1
 *    2 + 1 + 1 + 1
 *    1 + 1 + 1 + 1 + 1
 * 
 * How many different ways can one hundred be written as a sum of at least two 
 * positive integers?
 * 
 * Tip: Consider solving by Euler's partition funciton ...
 *      P(n,k) īs the number of ways that an integer, n, can be written as a sum
 *      of exactly k terms.
 *      P(n,k) = P(n-1,k-1) + P(n-k,k)
 *
 *      Similarly, Q(n,k) is the number of partitions of integer, n, with no
 *      element greater than k.
 *      Q(n,k) = Q(n,k-1) + Q(n-k,k)
 *
 * Example:
 *      P(5,3) = 2, since the partitions of 5 of length 3 are {3,1,1} and {2,2,1}
 *
 *      Q(5,3) = 5, since the partitions of 5 of length <= 3 are {3,2}, {3,1,1},
 *                  {2,2,1}, {2,1,1,1,1}, and {1,1,1,1,1}
 */
/*
 * The solution is 190569291
 * Solved via the partition function q(100,99)
 */

#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

long partQ( long n, long k );

// const long SOLVENUM = 100;
const long SOLVENUM = 7;

int main(int argc, char **argv)
{
    long n = 5;
    long k = 4;
    long tmp = 0;

    // Update n using input
    if ( 1 < argc )
    {
        n = atoi( argv[1] );
        k = n;      // Assume calculating Q( n, n )
    }
    // Update k using input
    if ( 2 < argc )
    {
        k = atoi( argv[2] );
    }

    cout << "Q(" << n << ", " << k << ") = ";
    tmp = partQ( n, k );

    cout << tmp << endl;

    return 0;
}

long partQ( long n, long k )
{
    /*
     * Partition function q, recursive implementation
     *
     *      Q(n,k) = Q(n,k-1) + Q(n-k,k)
     *
     * Q(n,k) is the number of partitions of integer, n, with no element greater than k.
     *
     * Example:
     *      Q(5,3) = 5, since the partitions of 5 of length <= 3 are {3,2}, {3,1,1},
     *                  {2,2,1}, {2,1,1,1,1}, and {1,1,1,1,1}
     */

    if ( 0==k )
    {
        return 0;
    }
    if ( 0==n )
    {
        return 1;
    }
    if ( 0>n )
    {
        return 0;
    }

    return partQ( n, k-1 ) + partQ( n-k, k );
}
