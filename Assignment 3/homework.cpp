#include<iostream> 
using namespace std;
class Loan  { 
public: 
  Loan(); 
  Loan(int ID, float amount, float rate, int term);
  void input(); 
  int getID();
  float getAmount();
  float getRate(); 
  int getTerm();
  void display( ); 
private: 
      int ID;  // assume an unique integer between 1111-9999 
      float amount; // $ amount of the loan 
      float rate; // annual interest rate 
      int term;  // number of months, length of the loan 
    }; 
    int main( ) 
    { 
    Loan loan1(1234, 2300, 5.5, 48);  // initialize to values given 
    Loan loan2;  // use the default values 
    Loan loan3; 
    Loan loan4 = loan1; 
    cout << "Display loan1 \n"; 
    loan1.display(); 
    cout << "\nDisplay loan2 \n"; 
    loan2.display(); 
    cout << "\nDisplay loan4 \n"; 
    loan4.display(); 
    
    cout << endl << "Input of Loan 3\n";
    loan3.input( ); 
    cout << "\nDisplay loan3\n"; 
    loan3.display();    
    return 0; 
  } 
  Loan::Loan( ) 
  { 
// Body intentionally kept empty so the default values are used. 
  } 
  Loan::Loan(int I, float am, float rt, int trm) 
  { 
      ID = I;
      amount = am;
      rate = rt;
      term = trm;
  } 
  void Loan::input( ) 
  { 
    cout << "Enter the ID of this loan \n"; 
    cin >> ID; 
    cout << "Enter the amount of this loan \n"; 
    cin >> amount; 
    cout << "Enter the annual interest rate of this loan (in %) \n"; 
    cin >> rate; 
    cout << "Enter the term (number of months, length of the loan) \n"; 
    cin >> term; 
  } 
  void Loan::display() 
  { 
    cout << "Your ID is: " << ID << "\n" <<
       "Your Loan Amount is: " << amount << "\n" <<
       "Your APR is: " << rate << "\n" << 
       "Your Loan Length is: " << term;
  }
