// Garden Designer
// OOP244.143 - Assignment 2
// a2main.cpp
// Version 1.0
// Justin Denney
// Oct 18 2014


#include <iostream>
#include <iomanip>
#include "Plant.h"
#include "Crop.h"
#include "Garden.h"


const int MAX_PLANT=20;
const int MAX_CROPS=20;

char menu(std::istream& is);

//Map Functions
void displayPlants(const Plant*,int);
void displayCrops(const Crop*,int);
Garden* setupGarden();

int main(){
	Crop crops[MAX_CROPS];
	Plant plants[MAX_PLANT];
	int noPlants=0;
	int noCrops=0;

	Garden *garden=nullptr;

	char choice;

	//Some starting data to reduce re-insertion of data
	//calls respective constructors

	plants[noPlants++]=Plant("Carrots", 'c');
	plants[noPlants++]=Plant("Lettuce", 'l');
	plants[noPlants++]=Plant("Rosemary", 'r');

	crops[noCrops++]=Crop(plants[0],4,2,0,0);

    std::cout << "Garden Designer\n"
              << "===============\n";
    // process user input
    do {
        choice = menu(std::cin);
        std::cout << std::endl;
        switch(choice) {
            case 'N':
				if(noPlants<MAX_PLANT){
					Plant temp;
					bool add=true;
					temp.read();
					for(int i=0;i<noPlants && add; i++)
						if(temp.symbol()==plants[i].symbol())
							add=false;
					if(!add)
						std::cout<<"Plant already exists"<<std::endl;
					else
						plants[noPlants++]=temp;
				}else
					std::cout<<"No room for any additional plant types"<<std::endl;
                break;
            case 'P':
					displayPlants(plants,noPlants);
                break;
            case 'A':
            	{
					if(noCrops<MAX_CROPS){
            			char symb;
            			int index=-1;
            			displayPlants(plants,noPlants);
            			std::cout<<"Plant Choice:";
            			std::cin>>symb;
            			for(int i=0;index==-1 && i<noPlants;i++)
            				if(plants[i].symbol()==symb)
            					index=i;
            			if(index!=-1){
            				//crops[noCrops++].read(plants[index]);
            			}
            			else
            				std::cout<<"No Match"<<std::endl;
					}else
						std::cout<<"No room for any additional crop shapes"<<std::endl;
				}
                break;
            case 'C':
				displayCrops(crops,noCrops);
                break;
            case 'G':
            	{
					if(garden==nullptr)
						garden=setupGarden();
					displayCrops(crops,noCrops);
					int choice=0;
					std::cout<<"Add which crop to garden?(0 to quit)";
					do{
						std::cin>>choice;
					}while(choice > noCrops);
					if(choice >0){
						*garden+=crops[choice-1];
					}
				}
            	break;
            case 'V':
            	if(garden!=nullptr)
            		std::cout<<*garden;
            	break;
        }
    } while (choice != 'Q');
	delete garden;
	return 0;
}

// menu prompts for and accepts an option selection from standard input and
// returns the character identifying the selected option
//
char menu(std::istream& is) {
    char c;
    int  ok = false;

    std::cout << '\n';
    std::cout << "Please select from the following options :\n";
    std::cout << " N - Create New Plant Type\n";
    std::cout << " P - View Plants Type\n";
    std::cout << " A - Create a new Crop Shape\n";
    std::cout << " C - View Crop(s)\n";
    std::cout << " G - Add Crop to Garden\n";
    std::cout << " V - View Garden\n";

    std::cout << " Q - Quit\n";
    do {
        std::cout << " Your selection : ";
        c = ' ';
        is.get(c);
        if (c >= 'a' && c <= 'z')
            c -= 'a' - 'A';
        if (is.fail()) {
            is.clear();
            is.ignore(2000, '\n');
            std::cerr << " Invalid input.  Try again." << std::endl;
        } else if (c == '\n') {
            ; // no input - try again
        } else if (c != 'N' && c != 'P' && c != 'A' && c != 'C' && c != 'G' && c != 'V' && c != 'Q') {
            is.ignore(2000, '\n');
            std::cerr << " Invalid Character.  Try again." << std::endl;
        } else if (is.get() != '\n') {
            is.ignore(2000, '\n');
            std::cerr << " Trailing Characters.  Try Again. " << std::endl;
        } else if (c == 'N' || c == 'P'|| c == 'A' || c == 'C'|| c == 'G' || c == 'V' || c == 'Q')
            ok = true;
    } while (ok == 0);

    return c;
}

//Displays all plants currently stored
//recieves plant array + size of array
void displayPlants(const Plant* plants, int n){
	for(int i=0; i<n;i++)
		std::cout<<plants[i];
	std::cout<<std::endl;
}

//Displays all crop shapes currently stored
//receives crop array + size of array
void displayCrops(const Crop * crops, int n){
	for(int i=0; i<n;i++)
		std::cout<<std::endl<<"--------------Crop "<<i+1<<"------------------"<<std::endl
		         <<crops[i];
}

//Sets up the Garden, reads a length and width from the std input, Allocates a new object
//recieves a pointer to a garden
Garden* setupGarden(){
	int l;
	int w;
	Garden *g=nullptr;

	do{
		std::cout<<"Garden Length (no rows):";
		std::cin >> l;
		std::cout<<"Garden Width  (no cols):";
		std::cin>> w;
		g= new Garden(l,w);
		if(l<= 0 || w <= 0 ||g->isEmpty()){
			delete g;
			g=nullptr;
			std::cout<<"Error: invalid dimensions"<<std::endl;
		}
	}while(g==nullptr);
	return g;
}

