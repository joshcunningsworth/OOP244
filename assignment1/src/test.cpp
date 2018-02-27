/* OOP244 143 Assignment 1 Test Main
 * Garden Planning Application (GPA)
 * Foundation Classes
 *
 * Author: Justin Denney
 * Based on test main created by Chris Szalwinski
 * Sept 27 2014
 *
 * Version 1.00 : Initial Version
*/
/*
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>

#include "crop.h"

#define DEBUG 1                    // Output verbosity flag
const int NOTESTS=76;
const int BLANK=0;

bool PlantTests(int& testNumber,int* totalPassed, int* totalTested);
bool CropTests(int& testNumber, int* totalPassed, int* totalTested);
bool MapTests(int& testNumber, int* totalPassed, int* totalTested);
void passed(const char* message, int i, int* totalPassed, int* total);
void failed(const char* message, int i, bool* ok, int* total);

bool compare(const char map[MAPL][MAPW], const char master[MAPL][MAPW+1]);
void displaySBS(const char[MAPL][MAPW], const char[MAPL][MAPW+1]);



int main() {
    bool ok = true;
    struct Plant plant;
    int totalPassed = 0, totalTested = 0, testNumber = 0;

    // Plant Tests
    if (DEBUG)
        std::cout << "Plant Tests\n===============\n";
    if(PlantTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "\nPlant Tests passed!\n\n";
        else
            std::cout << "Plant Tests passed!\n";
    else {
        std::cout << "\n";
        if (DEBUG)
            std::cout << "Plant Tests had errors!\n\n";
        else
            std::cout << "Plant Tests had errors!\n";
    }

    // Crop Tests
    if (DEBUG)
        std::cout << "Crop Tests\n=========\n";
    if(CropTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "\nCrop Tests passed!\n\n";
        else
            std::cout << "Crop Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nCrop Tests had errors!\n";
    }

   // Crop Map Tests
    if (DEBUG)
        std::cout << "Map Tests\n====================\n";
    if(MapTests(testNumber, &totalPassed, &totalTested) != 0)
        if (DEBUG)
            std::cout << "\nMap Tests passed!\n\n";
        else
            std::cout << "Map Tests passed!\n";
    else {
        std::cout << "\n";
        std::cout << "\nMap Tests had errors!\n";
    }

    // Conclusion
    std::cout << "\nYour GPA modules have passed " << totalPassed << " of " << NOTESTS << " tests\n";
    if (totalPassed == totalTested)
        std::cout << "\nCongratulations!!!   "
        "Your GPA modules are ready for submission\n"
        "Assuming no segmentation faults ....\n";
    else
        std::cout << "Keep working on your code - good luck!\n";
    return 0;
}
*/


/* PlantTests performs tests on the Plantclass and return false
*  for invalid results
*  *totalPassed - total number of tests passed
*  *totalTested - total number of tests attempted
*/

/*
bool PlantTests(int& testNumber, int* totalPassed, int* totalTested) {
    bool ok = true;
	Plant blank;
	Plant plant1("Turnips", 'T');

	if(!blank.isEmpty())
        failed("SES Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("SES Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.isEmpty())
        failed("Good Test: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Good Test: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!='T')
        failed("Good Test: symbol did not return the correct character",++testNumber,
               &ok, totalTested);
    else
    	passed("Good Test: symbol returned the correct character", ++testNumber,
  	  	       totalPassed, totalTested);

  	std::cout<<"Null Name Test: Sending null pointer to Plant constructor..."<<std::endl;
    plant1=Plant(nullptr, 'W');
	if(!blank.isEmpty())
        failed("Null Name Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Null Name Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!=blank.symbol())
        failed("Null Name Test: symbol did not return the correct character, object is not in a SES"
               ,++testNumber, &ok, totalTested);
    else
    	passed("Null Name Test: symbol returned the correct character", ++testNumber, totalPassed,
         totalTested);

    plant1=Plant("", 'F');
	if(!plant1.isEmpty())
        failed("Blank Name Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Blank Name Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!=blank.symbol())
        failed("Blank Name Test: symbol did not return the correct character, object is not in a SES"
               ,++testNumber, &ok, totalTested);
    else
    	passed("Blank Name Test: symbol returned the correct character", ++testNumber, totalPassed,
         totalTested);

  	std::cout<<"Long Name Test: Sending an excessively long name to Plant constructor..."<<std::endl;
    plant1=Plant("An Excessively long name for a plant", 'L');
	if(!blank.isEmpty())
        failed("Long Name Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Long Name Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);

	if(plant1.symbol()!=blank.symbol())
        failed("Long Name Test: symbol did not return the correct character, object is not in a SES"
               ,++testNumber, &ok, totalTested);
    else
    	passed("Long Name Test: symbol returned the correct character", ++testNumber, totalPassed,
         totalTested);
    return ok;
}
*/

/* CropTests performs tests on all Crop function except place()
*  returns false for invalid results
*  *totalPassed - total number of tests passed
*  *totalTested - total number of tests attempted
*/

/*
bool CropTests(int& testNumber, int* totalPassed, int* totalTested) {
    bool ok = true;
	Plant blankPlant;
	Plant plant1("Cabbage", 'c');
	Crop blank;
	Crop crop1(plant1,4,4);

	if(!blank.isEmpty())
        failed("SES Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("SES Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
   //Good Plant
   	std::cout<<"---Valid Plant Crop Test"<<std::endl;
	if(crop1.isEmpty())
        failed("Good Test: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Good Test: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
    crop1=Crop(plant1, 1, 1);
	if(crop1.isEmpty())
        failed("Good Test Smallest: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Good Test Smallest: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
    crop1=Crop(plant1, MAPL, MAPW);
	if(crop1.isEmpty())
        failed("Good Test Largest: isEmpty did not return false",++testNumber, &ok, totalTested);
    else
    	passed("Good Test Largest: isEmpty returned false", ++testNumber, totalPassed,
         totalTested);
	std::cout<<"---Valid Plant Crop Test"<<std::endl;
	crop1=Crop(plant1, -10, 4);
	if(!blank.isEmpty())
        failed("Neg Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, -15);
	if(!blank.isEmpty())
        failed("Neg Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, -135, -122);
	if(!blank.isEmpty())
        failed("Neg Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 0, 4);
	if(!blank.isEmpty())
        failed("0 Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, 0);
	if(!blank.isEmpty())
        failed("0 Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 0, 0);
	if(!blank.isEmpty())
        failed("0 Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, MAPL+1, 4);
	if(!blank.isEmpty())
        failed("Len too big: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Len too big: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, 4, MAPW+1);
	if(!blank.isEmpty())
        failed("Wid too big: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Wid too big: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop1=Crop(plant1, MAPL+1, MAPW+1);
	if(!blank.isEmpty())
        failed("Both too big: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Both too big: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
    //Bad Plant
    std::cout<<"---Invalid Plant Crop Test"<<std::endl;
	Crop crop2(blankPlant, 5,5);
	if(!crop2.isEmpty())
        failed("Valid Len/Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Valid Len/Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
    crop2=Crop(blankPlant, 1, 1);
	if(!crop2.isEmpty())
        failed("Valid Len/Wid Test Smallest: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Valid Len/Wid Test Smallest: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
    crop2=Crop(blankPlant, MAPL, MAPW);
	if(!crop2.isEmpty())
        failed("Valid Len/Wid Largest Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Valid Len/Wid Largest Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, -10, 4);
	if(!blank.isEmpty())
        failed("Neg Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 4, -15);
	if(!blank.isEmpty())
        failed("Neg Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, -135, -122);
	if(!blank.isEmpty())
        failed("Neg Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Neg Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 0, 4);
	if(!blank.isEmpty())
        failed("0 Len Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Len Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 4, 0);
	if(!blank.isEmpty())
        failed("0 Wid Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Wid Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 0, 0);
	if(!blank.isEmpty())
        failed("0 Both Test: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("0 Both Test: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, MAPL+1, 4);
	if(!blank.isEmpty())
        failed("Len too big: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Len too big: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, 4, MAPW+1);
	if(!blank.isEmpty())
        failed("Wid too big: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Wid too big: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
	crop2=Crop(blankPlant, MAPL+1, MAPW+1);
	if(!blank.isEmpty())
        failed("Both too big: isEmpty did not return true",++testNumber, &ok, totalTested);
    else
    	passed("Both too big: isEmpty returned true", ++testNumber, totalPassed,
         totalTested);
    return ok;
}
*/

/* RegisteredTests performs tests on the registered() function and returns
*  false for invalid results
*  *totalPassed - total number of tests passed
*  *totalTested - total number of tests attempted
*/

/*
bool MapTests(int& testNumber, int* totalPassed, int* totalTested) {
    bool ok = true;

	char map[MAPL][MAPW]=
	   {"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             "};
	char master[13][MAPL][MAPW+1]={
		{"                              ","                              ","                              ","                              ",
		"                              ","                              ","                              ","                              ",
		"                              ","                              ","                              ","                              ",
		"                              ","                              ","                              ","                              ",
		"                              ","                              ","                              ","                              "},
		{"ll                            ","ll                            ","ll                            ","ll                            ",
		"ll                            ","ll                            ","ll                            ","ll                            ",
		"ll                            ","ll                            ","ll                            ","ll                            ",
		"ll                            ","ll                            ","ll                            ","ll                            ",
		"ll                            ","ll                            ","ll                            ","ll                            "},
		{"ll cc                         ","ll cc                         ","ll cc                         ","ll cc                         ",
		"ll cc                         ","ll cc                         ","ll cc                         ","ll cc                         ",
		"ll cc                         ","ll cc                         ","ll cc                         ","ll cc                         ",
		"ll cc                         ","ll cc                         ","ll cc                         ","ll cc                         ",
		"ll cc                         ","ll cc                         ","ll cc                         ","ll cc                         "},
		{"ll cc p                       ","ll cc p                       ","ll cc p                       ","ll cc p                       ",
		"ll cc p                       ","ll cc p                       ","ll cc p                       ","ll cc p                       ",
		"ll cc p                       ","ll cc p                       ","ll cc p                       ","ll cc p                       ",
		"ll cc p                       ","ll cc p                       ","ll cc p                       ","ll cc p                       ",
		"ll cc p                       ","ll cc p                       ","ll cc p                       ","ll cc p                       "},
		{"ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ",
		"ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ",
		"ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ",
		"ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ",
		"ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   "},
		{"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt                   ","ll cc p ttt                   ",
		"ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ",
		"ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   ","ll cc p ttt                   "},
		{"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt                   ","ll cc p ttt CCCCC             ",
		"ll cc p ttt CCCCC             ","ll cc p ttt CCCCC             ","ll cc p ttt CCCCC             ","ll cc p ttt CCCCC             ",
		"ll cc p ttt CCCCC             ","ll cc p ttt CCCCC             ","ll cc p ttt CCCCC             ","ll cc p ttt CCCCC             "},
		{"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt                   ","ll cc p ttt CCCCC  bbb        ",
		"ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ",
		"ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        "},
		{"ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr",
		"ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR        ","ll cc p ttt                   ","ll cc p ttt CCCCC  bbb        ",
		"ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ",
		"ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        "},
		{"ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr",
		"ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR TTTTTTT","ll cc p ttt            TTTTTTT","ll cc p ttt CCCCC  bbb TTTTTTT",
		"ll cc p ttt CCCCC  bbb TTTTTTT","ll cc p ttt CCCCC  bbb TTTTTTT","ll cc p ttt CCCCC  bbb TTTTTTT","ll cc p ttt CCCCC  bbb        ",
		"ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        ","ll cc p ttt CCCCC  bbb        "},
		{"ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr",
		"ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr","ll cc p ttt RRRRRRRRRR rrrrrrr",
		"ll cc p ttt RRRRRRRRRR        ","ll cc p ttt RRRRRRRRRR TTTTTTT","ll cc p ttt            TTTTTTT","ll cc p ttt CCCCC  bbb TTTTTTT",
		"ll cc p ttt CCCCC  bbb TTTTTTT","ll cc p ttt CCCCC  bbb TTTTTTT","ll cc p ttt CCCCC  bbb TTTTTTT","ll cc p ttt CCCCC  bbb        ",
		"ll cc p ttt CCCCC  bbb sssssss","ll cc p ttt CCCCC  bbb sssssss","ll cc p ttt CCCCC  bbb sssssss","ll cc p ttt CCCCC  bbb sssssss"},
		{"BBBB                          ","BBBB                          ","BBBB                          ","BBBB                          ",
		"                              ","                              ","                              ","                              ",
		"                              ","                              ","                              ","                              ",
		"                              ","                              ","                              ","                              ",
		"                              ","                              ","                              ","                              "},
		{"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
		"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
		"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
		"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS",
		"SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS","SSSSSSSSSSSSSSSSSSSSSSSSSSSSSS"}
};

	Plant plant1("Basil", 'B');
	Crop blankCrop;
	Crop crop1(plant1,4,4);

	for(int i=0;i<MAPL;i++)
		map[i][MAPW-1]=' ';
	//invalid cases
	std::cout<<"---Invalid Input Map Tests"<<std::endl;
	std::cout<<"Null Name Test: Sending null pointer to Plant constructor..."<<std::endl;
	if(crop1.place( nullptr, 1,1))
		failed("Null Pointer: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("Null Pointer: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("Null Pointer: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("Null Pointer: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(crop1.place(map, -1,1))
		failed("x<0: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("x<0: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("x<0: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("x<0: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(crop1.place(map, 1,-1))
		failed("y<0: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("y<0: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("y<0: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("y<0: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(crop1.place(map, -1,-1))
		failed("x<0 && y<0: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("x<0 && y<0: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("x<0 && y<0: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("x<0 && y<0: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(crop1.place(map, MAPW,1))
		failed("x>max width: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("x>max width: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("x>max width: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("x>max width: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(crop1.place(map, 1,MAPL))
		failed("y>max length: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("y>max width: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("y>max length: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("y>max length: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(crop1.place(map, 1,MAPL-2))
		failed("Partial off: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("Partial off: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("Partial off: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("Partial off: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);


	if(blankCrop.place(map, 1,MAPL))
		failed("Blank Crop: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("Blank Crop: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("Blank Crop: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("Blank Crop: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);
	Crop big(Plant ("Sun flower", 'S'),MAPL,MAPW);
	if(big.place(map, 1,1))
		failed("Too Big Crop: place did not return false",++testNumber, &ok, totalTested);
	else
	   	passed("Too Big Crop: place returned false", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[BLANK])){
		failed("Too big Crop: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[BLANK]);
		return false;
	}else
		passed("Too Big Crop: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	//Valid tests
	std::cout<<"---Valid Map Tests"<<std::endl;
	if(!crop1.place(map, 0,0))
		failed("Simple Crop: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("Simple Crop: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[11])){
		failed("Simple Crop: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[11]);
		return false;
	}else
		passed("Simple Crop: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!big.place(map, 0,0))
		failed("Full Crop: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("Full Crop: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map,master[12])){
		failed("Full Crop: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map,master[12]);
		return false;
	}else
		passed("Full Crop: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

    //various changes
   // copy(map,blank);
	char map2[MAPL][MAPW]=
	   {"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             ",
		"                             ","                             ","                             ","                             "};
	for(int i=0;i<MAPL;i++)
		map2[i][MAPW-1]=' ';
    Crop crops[10];
    crops[0]=Crop(Plant("Lettuce",'l'), MAPL,2);
    crops[1]=Crop(Plant("Carrots",'c'), MAPL,2);
    crops[2]=Crop(Plant("Peppers",'p'), MAPL,1);
    crops[3]=Crop(Plant("Tomatoes",'t'), MAPL,3);
    crops[4]=Crop(Plant("Rhubarb",'R'), 10,10);
    crops[5]=Crop(Plant("Cabbage",'C'), 9,5);
    crops[6]=Crop(Plant("Basil",'b'),9,3);
    crops[7]=Crop(Plant("Rosemary", 'r'),8,7);
    crops[8]=Crop(Plant("Thyme", 'T'),6,7);
    crops[9]=Crop(Plant("Squash", 's'),4,7);

	if(!crops[0].place(map2, 0,0))
		failed("crop[0]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[0]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[1])){
		failed("crop[0]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[1]);
		return false;
	}else
		passed("crop[0]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[1].place(map2, 3,0))
		failed("crop[1]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[1]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[2])){
		failed("crop[1]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[2]);
		return false;
	}else
		passed("crop[1]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[2].place(map2, 6,0))
		failed("crop[2]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[2]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[3])){
		failed("crop[2]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[3]);
		return false;
	}else
		passed("crop[2]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[3].place(map2, 8,0))
		failed("crop[3]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[3]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[4])){
		failed("crop[3]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[4]);
		return false;
	}else
		passed("crop[3]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[4].place(map2, 12,0))
		failed("crop[4]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[4]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[5])){
		failed("crop[4]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[5]);
		return false;
	}else
		passed("crop[4]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[5].place(map2, 12,11))
		failed("crop[5]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[5]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[6])){
		failed("crop[5]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[6]);
		return false;
	}else
		passed("crop[5]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[6].place(map2, 19,11))
		failed("crop[6]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[6]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[7])){
		failed("crop[6]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[7]);
		return false;
	}else
		passed("crop[6]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[7].place(map2, 23,0))
		failed("crop[7]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[7]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[8])){
		failed("crop[7]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[8]);
		return false;
	}else
		passed("crop[7]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[8].place(map2, 23,9))
		failed("crop[8]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[8]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[9])){
		failed("crop[8]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[9]);
		return false;
	}else
		passed("crop[8]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

	if(!crops[9].place(map2, 23,16))
		failed("crop[9]: place did not return true",++testNumber, &ok, totalTested);
	else
	   	passed("crop[9]: place returned true", ++testNumber, totalPassed,
         totalTested);
    if(!compare(map2,master[10])){
		failed("crop[9]: your map does not match expected result",++testNumber, &ok, totalTested);
		std::cout<<std::endl;
		displaySBS(map2,master[10]);
		return false;
	}else
		passed("crop[9]: map matches with the expected result", ++testNumber, totalPassed,
         totalTested);

    return ok;
}

// passed displays passing message, increments *totalPassed and *total
//  i holds test number
void passed(const char* message, int i, int* totalPassed, int* total) {
    if (DEBUG && message[0] != '\0')
        std::cout << "Passed test " << std::setw(4) << i << " (" << message << ")\n";
    ++*totalPassed;
    ++*total;
}

// failed displays failure message, resets *ok to false, increments *total
// i holds test number

void failed(const char* message, int i, bool* ok, int* total) {
    std::cout << "Failed test " << std::setw(4) << i << " (" << message << ")\n";
    *ok = false;
    ++*total;
}

bool compare(const char map[MAPL][MAPW], const char master[MAPL][MAPW+1]){
	bool same=true;
	int i;
	for( i=0; i<MAPL && same;i++)
		same= strncmp(map[i],master[i],MAPW)==0;
	return same;
}

void displayHeader(int wid){
	std::cout<<std::endl<<"   " ;
	for (int i=1; i<=wid;i++){
		if(i/10==0)
			std::cout<<' ';
		else
			std::cout<<i/10;
	}
	std::cout<<"      ";
	for (int i=1; i<=wid;i++){
		if(i/10==0)
			std::cout<<' ';
		else
			std::cout<<i/10;
	}
	std::cout<<std::endl<<"   ";
	for (int i=1; i<=wid;i++)
		std::cout<<i%10;
	std::cout<<"      ";
	for (int i=1; i<=wid;i++)
		std::cout<<i%10;

	std::cout<<std::endl;
	std::cout<<"  +";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<'+';
	std::cout<<"    ";
	std::cout<<"+";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<'+'<<std::endl;
}

//Displays map footer based on the width (wid) provided
void displayFooter(int wid){
	std::cout<<"  +";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<"+    ";
	std::cout<<"+";
	for(int i=0; i<wid; i++)
		std::cout<<'-';
	std::cout<<"+    "<<std::endl;
}

void displaySBS(const char map[MAPL][MAPW], const char master[MAPL][MAPW+1]){
	displayHeader(MAPW);
	for(int i=0; i<MAPL; i++){
		std::cout.width(2);
		std::cout<<i+1<<'|';
		for(int j=0; j<MAPW;j++)
			std::cout<<map[i][j];
		std::cout<<"|  ";
		std::cout.width(2);
		std::cout<<i+1<<'|';
		for(int j=0; j<MAPW;j++)
			std::cout<<master[i][j];
		std::cout<<'|'<<std::endl;
	}
	displayFooter(MAPW);
	std::cout<<"   "<<"Your Map"<<std::setw(MAPW+6)<<
		      "Should be"<<std::endl<<std::endl;
}
*/
