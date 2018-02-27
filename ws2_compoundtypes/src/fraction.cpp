/*
 * fraction.cpp
 *
 *  Created on: Sep 3, 2014
 *      Author: Josh
 */

 // Workshop 2 - Fraction Simplifier


#include <iostream>
#include "fraction.h"
using namespace std;

void Fraction::set(int n, int d){

	// printing the title of the program
	cout << "\nFraction Simplifier\n===================\n";

	// prompting the user for the numerator
	cout << "Numerator  : ";
	// user inputs numerator
	cin >> n;
	// sets num to equal n which is the number the user entered
	num = n;

	// prompting the user to input the denominator
	cout << "Denominator: ";
	// user inputs denominator
	cin >> d;

	// sets den to equal d which is the number the user entered
	den = d;
	cout << endl;
}

void Fraction::simplify(){
	// declaring numerator and denominator variables
	int remainder = 0;
	int numerator = num, denominator = den;



		do{
			remainder = numerator % denominator;
			numerator = denominator;
			denominator = remainder;

		}while(remainder != 0);

		num = num / numerator;
		den = den / numerator;

}

void Fraction::display(){
	cout << num << "/" << den << endl;
}
