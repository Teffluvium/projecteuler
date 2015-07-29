/*
 * Problem 4 from ProjectEuler.net
 * 
 * A palindromic number reads the same both ways. The largest palindrome made 
 * from the product of two 2-digit numbers is 9009 = 91 * 99.
 * 
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * 
 */

#include <iostream>
#include <projectEuler_math.h>

using namespace std;

int main()
{
    unsigned long num1    = 0;
    unsigned long num2    = 0;
    unsigned long numPal  = 0;
    unsigned long bigNum1 = 0;
    unsigned long bigNum2 = 0;
    unsigned long bigPal  = 0;
    bool          flagPal;
    projectEuler_math pe_math;
    
    for (num1 = 999; num1>=100; num1 -= 1)
    {
        for (num2 = num1; num2>=100; num2 -= 1)
        {
            numPal = num1 * num2;
            
            flagPal = pe_math.isPalindromeInt( numPal );

            if (flagPal  &&  bigPal < numPal)
            {
                bigPal  = numPal;
                bigNum1 = num1;
                bigNum2 = num2;
            }
        }
    }
    
    cout << bigNum1 << " * " << bigNum2 << " = " << bigPal << endl;
    return 0;
}
