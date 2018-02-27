/*
 ============================================================================
 Name        : ws2_compoundtypes
 Author      : Josh Cunningham
 ============================================================================
 */

 #include <iostream>
 #include "fraction.h"
 using namespace std;


 int main (){

     Fraction fraction;
     int n = 0;
     int d = 0;

     fraction.set(n, d);
     fraction.simplify();
     fraction.display();
     cout << endl;
}
