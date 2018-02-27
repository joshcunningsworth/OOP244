/*
 ============================================================================
 Name        : Molecule.cpp
 Author      : Josh Cunningham
 ============================================================================
 */

#include <iostream>
#include <iomanip>
#include <new>
#include "Molecule.h"
#include <cstring>
using namespace std;	

// function that copies symbol to temp_symbol
void Molecule::Setsymbol(char temp_symbol[21]){
	strcpy (symbol,temp_symbol);
}

// function that copies the description to temp_desc
void Molecule::Setdesc(char temp_desc[201]){
	strcpy (description,temp_desc);
}

// function that copies weight to temp_weight
void Molecule::Setweight(double temp_weight){
	weight = temp_weight;
}

void Molecule::display() const{

	// formatting the output of the molecules
	cout.width(10);
	cout << std::left << symbol;
	cout.width(7);

	// sets the decimal place to be fixed at 3
	std::cout << std::fixed;
	cout << std::setprecision(3);
	cout << std::right << weight;
	cout << " " << description << endl;

	
}
