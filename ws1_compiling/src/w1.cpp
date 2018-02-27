//============================================================================
// Name        : ws1_compiling.cpp
// Author      : Josh Cunningham
// Date        : Sept 3, 2014.
// Description : Hello World in C++, Ansi-style
//============================================================================
// Modular Programs - Workshop 1

#include <iostream>
#include "w1.h"
#include "getPosInt.h"
using namespace std;

int getPosInt(int max);

int main(){
    int i;
    i = getPosInt(MAX);
    cout << "You entered " << i << endl;
}
