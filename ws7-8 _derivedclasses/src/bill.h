/*
bill.h
Created on: Nov 11, 2014
Author: Josh
*/

#ifndef BILL_H_
#define BILL_H_

// bill class
class Bill{
	int numpurchased;
	double *prices;
public:
	Bill();
	Bill(int, double[]);
	~Bill();
	double total()const;
	bool isEmpty()const;
	void display(std::ostream& os)const;
	Bill& operator=(const Bill&);
};

// receipt class
class Receipt : public Bill{
	char store[41];
	int numreceipts;
	int pricepurchased;
	double *receiptprice;
public:
	Receipt();
	void set(char[], int, double[]);
	~Receipt();
	bool isEmpty() const;
	void display(std::ostream& os) const;
	void setall(char, int, double);
};
//main: Receipt m;   m.display

std::ostream& operator<<(std::ostream& os, const Receipt& r);
std::istream& operator>>(std::istream& is, Receipt& r);

#endif /* BILL_H_ */
