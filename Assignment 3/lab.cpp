#include<iostream> 
#include <cmath>
using namespace std; 
class Loan  
{ 
public: 
 void input( ); 
         float payment( ); //exercise 1
         void payment(); //exercise 2
         void display( );
       private: 
       int ID;  // assume an unique integer between 1111-9999 
       float amount; // $ amount of the loan, e.g., 1000 
      float rate; // annual interest rate, e.g., 2 
      int term;  // number of months, length of the loan 
      float monthly_patment;
    }; 
    int main( ) 
    { 
      Loan loan1; 
      loan1.input( );
      //<!-- exercise 1: --
      loan1.display();
      float p = loan1.payment();
      cout << "\nMonthly Payment: " << p;
      // -->
      //<!--exercise 2 
      loan1.payment();
      loan1.display();
      // -->



      return 0; 
    } 
    void Loan::input( ) 
    { 
       // Initialize the loan1 object 
      cout << "Enter the ID of this loan \n"; 
      cin >> ID; 
      cout << "Enter the amount of this loan \n"; 
      cin >> amount; 
      cout << "Enter the annual interest rate of this loan (in %) \n"; 
      cin >> rate; 
      cout << "Enter the term (number of months, length of the loan) \n"; 
      cin >> term; 
    }

    void Loan::display(){
      cout << "ID: " << ID << "\n" <<
      "Amount: " << amount << "\n" <<
      "Rate: " << rate << "\n" <<
      "Term: " << term << "\n";
      //exercise 2:
      cout << "Monthly Payment: " << monthly_patment;
    }
//Exercise 1 Loan::payment
    float Loan::payment(){
      double tempRate = rate/1200;
      return (amount*tempRate*pow(tempRate+1,term))/(pow(tempRate+1,term)-1);
    }

//Exercise 2 Loan::payment
    void Loan::payment(){
      double tempRate = rate/1200;
      monthly_patment = (amount*tempRate*pow(tempRate+1,term))/(pow(tempRate+1,term)-1);
    }