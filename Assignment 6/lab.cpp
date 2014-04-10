#include <iostream>
#include <string>

using namespace std;

class Area
{
public:
	Area();
 	void setu(string a);
 	void seta(float b);
 	string getu();
 	float geta();
private:
 	string unit;
 	float area_value;
};

int main(){

	Area *a1;
	string unit;
	float area;

	a1 = new Area();

	cout << "Enter a unit with no space: ";
	cin >> unit;
	a1->setu(unit);

	cout << "\nEnter a value of area: ";
	cin >> area;
	a1->seta(area);

	printf("\nA half of your input = %G %s",a1->geta() / 2,a1->getu().c_str());
	printf("\nA quarter of your input = %G %s\n", a1->geta() / 4, a1->getu().c_str());


	return 0;
}

Area::Area(){
	unit = "squaremeter";
	area_value = 0;
}
void Area::setu(string a){
	unit = a;
}
void Area::seta(float b){
	area_value = b;
}
string Area::getu(){
	return unit;
}
float Area::geta(){
	return area_value;
}
