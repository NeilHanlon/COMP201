#include <iostream>
#include "Rational.h"

using namespace std;

Rational::Rational(){
	numerator = 0;
	denominator = 1;
}
Rational::Rational(double numer, int denom){
	numerator = numer;
	denominator = denom;
}
double Rational::getNumerator(){
	return numerator;
}
int Rational::getDenominator(){
	return denominator;
}
void Rational::display(){
	printf("The rational number you defined is:\n%g\n",(numerator/denominator));
}