#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int main(){

/**
* Part 1 of homework.
**/
	string s1,s2;
	cout << "Enter two lines of input:\n";
	getline(cin,s1);
	getline(cin,s2);
	regex rx ("Gcc");
	string replace = "gcc";

	regex_replace(s1,rx,replace);
	regex_replace(s2,rx,replace);	

	cout << "After replacement:\n" << 
	s1 << "\n" << s2 << "\n\n";

/**
* Part 2 of Homework
**/
	vector<int> vectorObject;
	int i;

	for(i = 0; i <10; i++) 
		vectorObject.push_back(i);

	cout << "Initial: ";
	for(vector<int>::iterator it=vectorObject.begin(); it != vectorObject.end(); ++it)
		cout << *it << " ";
	cout << endl;


	cout << "Reversed: ";
	for(vector<int>::reverse_iterator jt=vectorObject.rbegin(); jt != vectorObject.rend(); ++jt){
		cout << *jt << " ";
	}



	return 0;
}