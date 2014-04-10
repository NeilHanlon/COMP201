#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "../Helpers.h"

int main(){
	fstream input, output;
	string line;
	double total, count;

	input.open("homeworkinput.txt");

	if(input.is_open()){
		count = 0;
		while(getline(input,line)){
			double l;
			if(Helpers::StringToDouble(line,l)){
				total += l;
				++count;
			}
		}
	}
	input.close();

	double average = total / count;

	cout << setprecision(2) << fixed << average;

	output.open("homeworkoutput.txt");

	output << setprecision(2) << fixed << average;

	output.close();


	return 0;
}