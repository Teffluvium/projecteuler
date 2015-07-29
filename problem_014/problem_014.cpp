/*
 * Problem 14 from ProjectEuler.net
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 * 
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 * 
 * Using the rule above and starting with 13, we generate the following sequence:
 *      13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 * 
 * It can be seen that this sequence (starting at 13 and finishing at 1) 
 * contains 10 terms. Although it has not been proved yet (Collatz Problem), 
 * it is thought that all starting numbers finish at 1.
 * 
 * Which starting number, under one million, produces the longest chain?
 * 
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 */

/*
 * The solution is 837799
 */

#include <iostream>

using namespace std;

const unsigned int INITSEED = 999999;
int main()
{
    unsigned long currSeed  = INITSEED,
                  maxSeed   = currSeed,
                  seqLength = 1,
                  maxLength = 0,
                  value     = 0;
    
    do 
    {
        value     = currSeed;
        seqLength = 1;
        
        //cout << "Testing:  " << currSeed;
        
        do 
        {
            if ((value % 2) == 0)   // value is even
            {
                value = value / 2;
            } else {
                value = 3*value + 1;
            }
            
            seqLength++;
        } while (value > 1);
        
        if (seqLength > maxLength)
        {
            maxSeed   = currSeed;
            maxLength = seqLength;
        }
        
        // cout << " has sequence length of " << seqLength << endl;
        
        currSeed--; 
    } while (currSeed > 1);
    
    cout << endl;
    cout << maxSeed << " generated a sequence of " << maxLength << endl;
    
    return 0;
}
