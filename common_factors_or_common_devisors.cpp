#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a, int b) {
   if (a == 0)
      return b;
   return gcd(b%a, a);
}
int countCommonDivisors(int a,int b) {
   int gcd_val = gcd(a, b); //get gcd of a and b
   int count = 0;
   for (int i=1; i<=sqrt(gcd_val); i++) {
      if (gcd_val%i==0) { // when'i' is factor of n
         if (gcd_val/i == i) //if two numbers are same
            count += 1;
         else
            count += 2;
      }
   }
   return count;
}
main() {
   int a = 12, b = 24;
   cout << "Total common divisors: " << countCommonDivisors(a, b);
}