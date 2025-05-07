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
#include <cmath>

bool isPalindrome(unsigned long num);

using namespace std;

int main()
{
    long num1    = 0, num2    = 0, numPal = 0, 
         bigNum1 = 0, bigNum2 = 0, bigPal = 0;
    bool flagPal;
    
    for (num1 = 999; num1>=100; num1 -= 1)
    {
        for (num2 = num1; num2>=100; num2 -= 1)
        {
            numPal = num1 * num2;
            
            flagPal = isPalindrome(numPal);
            
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

bool isPalindrome(unsigned long num)
{    
    int powerOfTen = 0;
    int high = 0, low = 0;
    int k = 0;
    
    powerOfTen = static_cast<int>(floor(log10(num)));
    
    do
    {
        low  = num / static_cast<int>(pow(10.0, k))              % 10;
        high = num / static_cast<int>(pow(10.0, powerOfTen - k)) % 10;

        k++;
    } while (low == high  &&  k<ceil(powerOfTen/2.0));
        
    if (low == high)
    {
        return 1;
    } else {
        return 0;
    }
}
