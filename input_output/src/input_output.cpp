//============================================================================
// Name        : input_output.cpp
// Author      : Josh Cunningham
// Date		   : Jan 8th 2014
// Description : Basic input/output in C++
//============================================================================

#include <iostream>
using namespace std;

int main() {
	//ofstream myfile("output.txt");
	int x;

	cout << "input a number to count up to 10" << endl;
	cin >> x;
	cout << x << endl;

	if (x < 10){
		for(int i = x; i < 10; i++){
		cout << i+1 << endl;
		}
	}

	else{
		cout << "you fail.. enter a number under 10" << endl;
	}

	return 0;
}
