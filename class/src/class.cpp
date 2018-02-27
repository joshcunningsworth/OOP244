//============================================================================
// Name        : class.cpp
// Author      : Josh Cunningham
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class point{
public:
	void setX(float x) {_x = x;}
	float getX() {return _x;}
	void setY(float y) {_y = y;}
	float getY() {return _y;}

private:
	float _x;
	float _y;
};


int main() {
	point p1;
	point p2;

	p1.setX(24.5);
	cout << "X: " << p1.getX() << endl;

	p2.setY(10.7);
	cout << "Y: " << p2.getY() << endl;
	return 0;
}
