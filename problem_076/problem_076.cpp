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
 */

#include <iostream>
#include <vector>
using namespace std;

void display(const vector<long> & vec, long count = 0);
const vector<long> & fillVecTail(vector<long> & vec, long maxVal, long fillVal);
long sumVec(const vector<long> & vec);

const long SOLVENUM = 100;

int main(int argc, char **argv) {
   vector <long> v;
   long          count = 0;
   
   // Allocate space for the vector v
   v.reserve(SOLVENUM);
   v.push_back(SOLVENUM);
   
   while (v.at(0)>1) {
      count++;
      
      // Strip out trailing ones from the vector
      while (v.back() == 1) {
         v.pop_back();
      }
      
      // Decrement the last element of the vector
      v.back() = v.back() - 1;
      
      /* 
       * Fill the end of the vector with the last element repeatedly until the sum
       * of the vector elements equals SOLVENUM
       */
      v = fillVecTail(v, SOLVENUM, v.back());
   }  // end while loop
   
   cout << endl << "Done" << endl << endl;
   display(v, count);
}

void display(const vector<long> & vec, long count) {
   long N = vec.size();
   cout << count << ":   ";
   for (long n=0; n != N; n++) {
      cout << vec[n] << " ";
   }
   cout << endl;
}

/* 
 * Sum the elements of the vector
 */
long sumVec(const vector<long> & vec) {
   vector<long>::const_iterator p;
   long sum = 0;
   for (p=vec.begin(); p != vec.end(); p++) {
      sum += *p;
   }
   return sum;
}

/* 
 * Repeatedly append fillVal to the end of a vector until the sum of the 
 * vector elements equals maxVal
 */
const vector<long> & fillVecTail(vector<long> & vec, 
                                 const long maxVal,
                                 const long fillVal) {
   
   // Append fillVal as many times as necessary without sumVec(vec) > maxVal
   long remaining = maxVal - sumVec(vec);
   int appendCnt  = remaining/fillVal;
   for (int k=0; k<appendCnt; k++) {
      vec.push_back(fillVal);
      remaining -= fillVal;
   }
   // If remaining is still positive, append to the vector
   if (remaining>0) {
      vec.push_back(remaining);
   }
   
   return vec;
}
