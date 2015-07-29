//
// Created by tim on 7/28/15.
//

#ifndef PROJECTEULER_PROJECTEULER_MATH_H
#define PROJECTEULER_PROJECTEULER_MATH_H


class projectEuler_math {

public:
    projectEuler_math() { }

    virtual ~projectEuler_math() { }

public:
    // Greatest Common Divisor (GCD)
    unsigned long gcd(    unsigned long a, unsigned long b );

    // Cumulative sum from M to N
    unsigned long cumSum( unsigned long m, unsigned long n );

    // Least Common Multiple (LCM)
    unsigned long lcm(    unsigned long a, unsigned long b );

    // Calculate the Nth Fibonacci number
    unsigned long fibonacci( int N );

    // Check if an integer is a palindrome
    bool isPalindromeInt( unsigned long num );

};


#endif //PROJECTEULER_PROJECTEULER_MATH_H
