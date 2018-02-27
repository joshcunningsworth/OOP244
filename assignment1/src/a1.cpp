//============================================================================
// Name        : a1.cpp
// Author      : Josh Cunningham
// Description :
//============================================================================

// including libraries
#include <iostream>
#include <iomanip>
#include "crop.h"
using namespace std;

int main() {
	// initializing variables and instances
	char map[MAPL][MAPW];
	Plant plant[20];
	Crop crop[10];
	int plantnum = 2, cropnum = 0;
	char plantchoice, choice;
	int cropchoice, check;
	int xpos, ypos;
	int cropflop;

	plant[0] = Plant("carrots", 'c');
	plant[1] = Plant("lettuce", 'l');
	plant[2] = Plant("rosemary", 'r');

	crop[0] = Crop(plant[0], 4, 2);
	cropnum++;

	Plant temp;

	// for loops to display map
	for(int i = 0; i < MAPL; i++){
		for(int j = 0; j < MAPW; j++){
			map[i][j] = ' ';
		}
	}

	cout << "Garden Designer\n===============\n";

	// do while loop for menu
	do{
		cout << "Please select from the following options:\n";
		cout << " N - Create New Plant Type\n";
		cout << " P - View Plant Types\n";
		cout << " S - Create a new Crop Shape\n";
		cout << " C - View Crop(s)\n";
		cout << " G - Add Crop to Garden\n";
		cout << " V - View Garden\n";
		cout << " Q - Quit\n";
		cout << " Your selection: ";
		cin >> choice;

		// user inputs a letter which is converted to upper case
		if(choice=='n'||choice=='p'||choice=='s'||choice=='c'||choice=='g'||choice=='v'||choice=='q'){
			choice = toupper(choice);
		}

		// switch case for menu
		switch(choice) {
			// creating a new plant
			case 'N':
				temp.read();
				plantnum++;
				plant[plantnum] = temp;
				break;


			case 'P':
				for(int n = 0; n <= plantnum; n++){
					plant[n].display();
				}
				cout << endl;
				break;

			case 'S':
				for(int n = 0; n <= plantnum; n++){
					plant[n].display();
				}
				cout << endl << "Plant Choice:";
				cin >> plantchoice;

				for(int n = 0; n <= plantnum; n++){
					if(plantchoice == plant[n].symbol()){
						crop[cropnum].read(plant[n], MAPL, MAPW);
						cropnum++;
						n = 30;
					}
				}
				break;

			case 'C':
				for(int n = 0; n < cropnum; n++){
					cout << "--------------Crop " << n+1 << "------------------\n";
					crop[n].display();
				}
				break;

			case 'G':
				for(int n = 0; n < cropnum; n++){
					cout << "--------------Crop " << n+1 << "------------------\n";
					check = check + 1;
					crop[n].display();
				}
				//prompting user to enter the crop to place in garden
					cout << "Add which crop to garden? (0 to quit)\n";
					cin >> cropchoice;
					if(cropchoice == 0){
						break;
					}

					cropchoice--;

					// doesnt work on matrix only in eclipse
					//if(cropchoice > check-1 || cropchoice < 0){
					//	cout << "Invalid Crop Choice";
					//	break;
					//}

					// header
						cout << setw(24) << right << "11111111112\n";
						cout << setw(24) << right << "12345678901234567890\n";
						cout << "  " << setw(21) << setfill('-') << left << '+' << right << '+' << setfill (' ') << endl;
						cout << flush;

						// for loops to display map
						for(int x = 0; x < MAPL; x++){
							cout << setw(2) << right <<	x+1 << "|";
							for(int y = 0; y < MAPW; y++){
								cout << map[x][y];
							}
							cout << "|" << endl;
						}

						// footer
						cout << "  " << setw(21) << setfill('-') << left << '+' << right << '+' << setfill (' ') << endl;
						cout << setw(24) << right << "11111111112\n";
						cout << setw(24) << right << "12345678901234567890\n";

						// user can enter x and y position
						for(cropflop = 0; cropflop != 1; cropflop = 1){
							cout << "Enter X Coordinate:";
							cin >> xpos;
							if(xpos == 0){
								break;
							}
							cout << "Enter Y Coordinate:";
							cin >> ypos;
							cropflop = crop[cropchoice].place(map, xpos, ypos);
							if(cropflop == 0){
								cout << "The Crop Flopped, It couldn't fit\n";
							}

						}

				break;

			case 'V':
				// header, map and footer for the display of garden
				cout << setw(24) << right << "11111111112\n";
				cout << setw(24) << right << "12345678901234567890\n";
				cout << "  " << setw(21) << setfill('-') << left << '+' << right << '+' << setfill (' ') << endl;
				cout << flush;

				// 2 for loops to display 2d array map
				for(int x = 0; x < MAPL; x++){
					cout << setw(2) << right <<	x+1 << "|";
					for(int y = 0; y < MAPW; y++){
						cout << map[x][y];
					}
					cout << "|" << endl;
				}

				cout << "  " << setw(21) << setfill('-') << left << '+' << right << '+' << setfill (' ') << endl;
				cout << setw(24) << right << "11111111112\n";
				cout << setw(24) << right << "12345678901234567890\n\n";
				break;
		}
		// quit
	}while(choice != 'Q');


	return 0;
}
