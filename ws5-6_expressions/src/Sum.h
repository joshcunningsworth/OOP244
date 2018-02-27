/*
Sum.h
Author: Josh
*/

class Sum{

	int *n;
	int sum;
	int amount;
	int total;

	public:
		Sum();
		Sum(int);
		Sum(Sum&); // copy ctor
		Sum& operator=(Sum&); // assignment operator
		~Sum(){if(n != nullptr){delete [] n;}} // dtor deallocate dynamic memory
		Sum(const int *, int);
		void display() const;
		Sum& operator+=(int); // operator overload
};
