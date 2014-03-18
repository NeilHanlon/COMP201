#include<iostream> 
#include<cstdlib> 
using namespace std;

class AltMoney 
{ 
public: 
 	AltMoney(); 
 	AltMoney(int d, int c); 
 	friend AltMoney operator +(AltMoney m1, AltMoney m2); 
	friend AltMoney operator +=(AltMoney income, AltMoney expenditure);
	friend bool operator >=(AltMoney income, AltMoney expenditure);
 	void display_money( ); 
 	AltMoney add(AltMoney first, AltMoney second);
 	void read_money(AltMoney alt);
 private: 
 	int dollars; 
 	int cents; 
 	double sum;
}; 
void read_money(int& d, int& c); 
int main( ) 
{ 
 	int d, c; 
 	AltMoney sum, income, expenditure, pe; 
 	read_money(d, c); 
 	AltMoney m1(d, c);
 	cout << "The first money is:";
 	m1.display_money(); 
 	read_money(d, c); 
 	AltMoney m2(d, c);
 	cout << "The second money is:"; 
 	m2.display_money(); 
 	sum = m1+m2; 
 	cout << "The sum is:"; 
 	sum.display_money();
	
	income = m1;
	expenditure = m2;
	pe = income += expenditure;

	cout << "The result of += is: " << endl;
	pe.display_money();

 	return 0; 
 } 
AltMoney::AltMoney() 
{ 
 	dollars = 0;
 	cents = 0;
} 
AltMoney::AltMoney(int d, int c)
{ 
 	dollars = d; 
 	cents = c;
} 
void AltMoney::display_money() 
{ 
 	cout << "$" << dollars << "."; 
 	if(cents <= 9) 
 		cout << "0";  //to display a 0 in the left for numbers less than 10 
 	cout << cents << endl; 
} 
AltMoney operator +(AltMoney m1, AltMoney m2) 
{ 
     AltMoney temp; 
     int extra = 0; 
     temp.cents = m1.cents + m2.cents; 
     if(temp.cents >=100){ 
         temp.cents = temp.cents - 100; 
         extra = 1; 
      } 
      temp.dollars = m1.dollars + m2.dollars + extra; 
      return temp; 
} 

AltMoney operator +=(AltMoney income, AltMoney expenditure)
{
	if (income >= expenditure)
		return (income);
	else
		return (expenditure);
}

//not perfect
bool operator >=(AltMoney income, AltMoney expenditure)
{
	int a1, a2;
	a1 = income.dollars*100 + income.cents;
	a2 = expenditure.dollars*100 + expenditure.cents;
	if (a1 >= a2)
		return true;
	else 
		return false;
}

void read_money(int& d, int& c) 
{ 
 	cout << "Enter dollar \n"; 
 	cin >> d; 
 	cout << "Enter cents \n"; 
 	cin >> c; 
 	if( d < 0 || c < 0) 
 	{ 
 		cout << "Invalid dollars and cents, negative values\n"; 
 		exit(1); 
 	 }
}
AltMoney AltMoney::add(AltMoney first, AltMoney second, AltMoney& sum){
   	int extra = 0; 
    sum.cents = first.cents + second.cents; 
    if(sum.cents >=100){ 
         sum.cents = sum.cents - 100; 
         extra = 1; 
      } 
      sum.dollars = m1.dollars + m2.dollars + extra; 

}
void AltMoney::read_money(AltMoney alt){
	cout << "Enter dollar \n"; 
 	cin >> alt.dollars; 
 	cout << "Enter cents \n"; 
 	cin >> alt.cents;
 	if( d < 0 || c < 0) 
 	{ 
 		cout << "Invalid dollars and cents, negative values\n"; 
 		exit(1); 
 	 }
}