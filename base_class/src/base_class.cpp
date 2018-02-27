//============================================================================
// Name        : base_class.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Base{
public:
	Base() { cout << "Base ctor\n";}
	~Base() { cout << "Base dtor\n";}
	void print(){ cout << "class base\n";}

	Base b;
	b print();
};

class Derived: public Base{
public:
	Derived(){ cout << "Derived ctor\n";}
	~Derived(){ cout << "Derived dtor\n";}
	void print(){ cout << "class Derived\n";
	}
};
	Derived d;
	d print();
};

void printObj(Base & obj){
	obj.print();
}

int main(int argc, char *argv[]) {
	Base b;
	b.print();
	Derived d;
	d.print();
	printObj(b);
	printObj(d);

	return 0;
}
