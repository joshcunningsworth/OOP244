//============================================================================
// Name        : ws7-8.cpp
// Author      : Josh Cunningham
//============================================================================
#include <iostream>
#include "bill.h"

int main(){
	Receipt *Receipts;
	int noRec;

	std::cout<<"Number of Receipts:";
	std::cin>>noRec;

	Receipts= new Receipt[noRec];

	for(int i=0;i<noRec;i++)
		std::cin>>Receipts[i];

	std::cout<<std::endl<<"----Results----"<<std::endl;

	for(int i=0;i<noRec;i++){;
		std::cout<<Receipts[i]<<std::endl;
	}
	delete [] Receipts;
}
