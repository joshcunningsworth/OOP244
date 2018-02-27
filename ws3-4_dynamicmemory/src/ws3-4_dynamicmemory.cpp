/*
 ============================================================================
 Name        : ws3-4_dynamicmemory.cpp
 Author      : Josh Cunningham
 ============================================================================
 */

#include <iostream>
#include <iomanip>
#include <new>
#include "Molecule.h"
using namespace std;

int main() {
 
	int n;	
	Molecule* molecule = nullptr;

	cout << "Molecular Information\n";
	cout << "=====================" << endl;

	cout << "Number of Molecules : ";
	cin >> n;
	cout << endl;
	
	molecule = new(nothrow) Molecule[n];
	if (molecule == nullptr){
         cout << "No data Available" << endl;
		};
	
	// allocates dynamic memory for an array of n Molecules
	for (int i = 0; i < n; i++) {
		char temp_symbol[21], temp_desc[201];
		double temp_weight = 0;
		
		cin.clear();
		cin.ignore(2000,'\n');
		
		cout << "Enter Structure: ";
		cin.getline(temp_symbol, 21);
		cout << endl;
		
		cout << "Enter Full Name: ";
		cin.getline(temp_desc, 201);
		cout << endl;
		
		cout << "Enter weight: ";
		cin >> temp_weight;
		
		molecule[i].Setsymbol(temp_symbol);
		molecule[i].Setdesc(temp_desc);
		molecule[i].Setweight(temp_weight);
		cout << endl;

	}

	cout << "Structure    Mass Name\n";
     cout << "========================================" << endl; 
	
	for (int i = 0; i < n; i++) {
         molecule[i].display();
         cout << endl;
     }

	cout << endl;
	// deallocate dynamic memory for the array of n Molecules
	delete [] molecule;
	molecule = nullptr;
}
