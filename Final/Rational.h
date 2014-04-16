#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class Rational
{
	public:
		Rational();
		Rational(double numer, int denom);
		double getNumerator();
		int getDenominator();
		void display();
	private:
		double numerator;
		int denominator;
};

#endif