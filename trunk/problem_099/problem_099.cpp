/*
 * Problem 99 from ProjectEuler.net
 * Comparing two numbers written in index form like 2^11 and 3^7 is not 
 * difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.
 *
 * However, confirming that 632382^518061 > 519432^525806 would be much more 
 * difficult, as both numbers contain over three million digits.
 * 
 * Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K 
 * text file containing one thousand lines with a base/exponent pair on 
 * each line, determine which line number has the greatest numerical value.
 * 
 * NOTE: The first two lines in the file represent the numbers in the example given above.
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char **argv) {
   string          filename = "base_exp.txt";
   vector <double> base,
                   exponent,
                   result;
      
   ifstream in(filename.c_str()); // input

   if(!in) { 
      cout << "Cannot open " << filename << "file.\n";
      return 1;
   }

   char comma;
   double b   = 0,
          exp = 0;
   do {
      in >> b >> comma >> exp;
      in.get();
      base.push_back(b);
      exponent.push_back(exp);
   } while (!in.eof());
   in.close();
   
   int    length = base.size(),
          row    = 1;
   double maxval = 0;
   
   result.resize(length);
   for (int i=0; i<length; i++) {
      result[i] = exponent[i] * log(base[i]);
      if (result.at(i) > maxval) {
         maxval = result.at(i);
         row    = i+1;
      }
   }

   cout << "Max at line " << row << " with " 
        << base.at(row-1) << "^" << exponent.at(row-1) << endl;
         
   return 0;
}
