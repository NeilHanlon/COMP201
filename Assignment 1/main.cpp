#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <cmath>

#include "../Helpers.h"

using namespace std;

int main(){

	fstream input, outputf;
	string line;
	int sum = 0;

	string output = "";

	array<int,8> numbers;

	input.open("maininput.txt");

	if(input.is_open()){
		int i = 0;
		while(getline(input,line)){
			int l;
			if(Helpers::StringToInt(line,l)){
				numbers[i] = l;
			}
			++i;
		}
	}

	input.close();

	output += "x\tx^2\tCurrent Sum \n---\t---\t----------\n";

	for(int i=0;i<numbers.size();++i){
		sum += numbers[i];
		string powstring = to_string(pow(numbers[i],2));
		output +=  to_string(numbers[i]) + "\t" + powstring.substr(0,2) + "\t" + to_string(sum) + "\n";
	}

	cout << output;

	outputf.open("mainoutput.txt");

	outputf << output;

	outputf.close();




	return 0;
}