#include <iostream>
#include <map>

using namespace std;

void part1();
void part2();

int main(){

	cout << "Question 1:\n\n\n";
	part1();
	cout << "\n\n\nQuestion 2:\n\n\n";
	part2();
	

	return 0;
}

void part1(){
	int age;

	typedef map<string,int> riderMap;
	typedef pair<string,int> riderPair;

	riderMap today;

	today.insert(riderPair("Student",0));
	today.insert(riderPair("Adult",0));
	today.insert(riderPair("Senior",0));

	cout << "....ENTER -1 TO EXIT....\n";
	cout << "Enter Age: ";
	cin >> age;

	while(age != -1){
		if(age <= 17){
			today["Student"]++;
		} else if(age <= 65){
			today["Adult"]++;
		} else {
			today["Senior"]++;
		}
		cout << "Enter Age: ";
		cin >> age;
	}
	
	cout << "Students: " << today["Student"];
	cout << endl << "Adults: " << today["Adult"];
	cout << endl << "Seniors: " << today["Senior"];
}

void part2(){
	int num1, num2;

	cout << "Enter the first number: "; cin >> num1;
	cout << "Enter the second number: "; cin >> num2;

	for(int i = 1; i <= num1; ++i){
		for(int j = 1; j <= num2; ++j){
			cout << j*i << "\t";
		}
		cout << "\n";
	}
}