//============================================================================
// Name        : Assignment1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <ctype.h>

using namespace std;

bool isValid(char* ean) {
        cout << "EAN = " << ean << endl;
        int len = strlen(ean);
        cout << "len =" << len << endl;
        if(len != 13){
                return false;
        }
        return true;
}

int main (int argc, char *argv[]) {
        for (int i = 0; i < argc; i++){
                cout << "argv[" << i << "]= " << argv [i] << endl;
                cout << "isValid = " << isValid (argv[i]) << endl;
        }
}
