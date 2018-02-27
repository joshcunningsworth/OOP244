//============================================================================
// Name        : burger_walkthrough.cpp
// Author      : Josh Cunningham
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define B_BITE 100
#define C_BITE  20

class Burger {
    double grams;
    int toppings;
  public:
    Burger() {
        grams = 0;
        toppings = 0;
        cout << "B";
    }
    Burger(double g, int t) {
        grams = g;
        toppings = t;
        display();
    }
    Burger(const Burger& b) {
        cout << '&';
        *this = b;
        display();
    }
    Burger& operator=(const Burger& b) {
        cout << '=';
        grams = b.grams;
        toppings = b.toppings;
        return *this;
    }
    ~Burger() {
        cout << '~';
        display();
    }
    void display() const {
        cout << "B(" << grams << ',' << toppings << ')' << endl;
    }
    void operator++() { toppings++; }
    void operator++(int) { toppings += 2; }
    void bite() {
        grams -= B_BITE;
        if(grams < 0) grams = 0;
    }
};

class CheeseBurger : public Burger {
    double grams;
    int layers;
  public:
    CheeseBurger() {
        grams = 0;
        layers = 1;
        cout << "C";
    }
    CheeseBurger(double g, double b, int t) : Burger(b, t) {
        grams = g;
        layers = 1;
        display();
    }
    void display() const {
        cout << "C(" << grams << ',' << layers << ')' << endl;
    }
    void operator++(int) {
    	layers++;
    }
    ~CheeseBurger() {
        cout << '~';
        Burger::display();
        cout << '~';
        display();
    }
    void bite() {
        Burger::bite();
        grams -= C_BITE;
        if(grams < 0) grams = 0;
    }
};

Burger bite(Burger& b) {
    b.bite();
    return b;
}

int main() {
    CheeseBurger cheeseBurger(60, 200, 3);
    Burger hamBurger, myShare;

    cout << endl;
    cheeseBurger++;
    cout << "----------" << endl;
    hamBurger = Burger(150, 2);
    cout << "----------" << endl;
    ++hamBurger;
    myShare = bite(hamBurger);
    cout << "----------" << endl;
    cheeseBurger.bite();
    myShare.bite();

    return 0;
}
