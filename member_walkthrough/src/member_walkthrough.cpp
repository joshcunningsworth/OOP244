//============================================================================
// Name        : member_walkthrough.cpp
// Author      : Josh Cunningham
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
 #include <iomanip>
 #include <string>
 #define N 2
 using namespace std;

 class Member {
     int m;
     int p;
     char* text;
 public:
     Member() {
         text = nullptr;
         m = 0;
         p = 7;
     }
     Member(const Member& in) {
         p = 1;
         m = in.m;
         text = new char[m+1];
         strcpy(text, in.text);
     }
     void operator=(const char* in) {
         m = 0;
         while (in[m] != '\0' && in[m] != ' ')
             m++;
         text = new char[m+1];
         for (int i = 0; i < m; i++)
             text[i] = in[i] + i;
         text[m] = '\0';
     }
     int size() const {return m;}
     friend ostream& operator<<(ostream& os, const Member in) {
         os << "^\n" << setw(4) << in.text << ' ';
         return os;
     }
     ~Member() {
         cout << setw(p) << m << endl;
         if (text) delete [] text;
     }
 };

 int main() {
     Member mem[N];
     int n = 0, j = 0;
     char str[] = "Wgm ir is";

     do {
         mem[n] = &str[j]; // calls = operator - passes which address?
         j += mem[n].size() + 1;
         n++;
     } while (n < N && str[j-1] != '\0');

     cout.fill('.');
     cout << left;
     for (int i = 0; i < n; i++)
         cout << mem[i];
     cout << right << "_\n-------" << endl;

     return 0;
 }
