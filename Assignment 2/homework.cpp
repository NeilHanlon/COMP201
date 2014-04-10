#include <iostream>
#include <vector>
#include <algorithm> //sort
#include <functional> //greater

using namespace std;

int main(){

	vector<int> ints;
	int tmp;
	double sum;
	int i = 0;

	cout << "Input up to 20 positive integers. Use -1 to terminate input:\n";

	cin >> tmp;

	while(tmp != -1){
		ints.push_back(tmp);
		cin >> tmp;
		i++;
	}

	sort(ints.begin(), ints.end(), greater<int>());

	cout << "Greatest: " << ints[0];

	sort(ints.begin(), ints.end(), less<int>());

	cout << "\nLeast: " << ints[0];

	for(vector<int>::iterator it=ints.begin(); it != ints.end(); ++it){
		sum += *it;
	}

	cout << "\nMean: " << sum / ints.size();

	return 0;
}