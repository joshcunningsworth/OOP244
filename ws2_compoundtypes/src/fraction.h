/*
 * fraction.h
 *
 *  Created on: Sep 3, 2014
 *      Author: Josh
 */


class Fraction{
	private:
		// integers for the numerator and denominator
		int num, den;

	public:
		// calls function to input the numbers for the fraction
		void set(int num, int dem);
		// calls function to simplify the fraction
		void simplify();
		// calls function to display the fraction
		void display();
};
