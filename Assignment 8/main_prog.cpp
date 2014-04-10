// This and the following 5 lines will go to the main program, main_prog.cpp 
// Additional include statements should be added 
// This program is a driver written to demonstrate how we can use a 
// class inside another one. 
#include <iostream>

using namespace std;

#include "ID.h"
#include "Loan.h"

int main( ) 
{ 
    Loan loan1(ID(111,22,4444), 2300, 5.5, 48);  // initialize to values given 
    Loan loan2; 
    cout << "Display loan1 \n"; 
    loan1.display(); 
    loan2.set( ); // set the values 
    cout << "Display loan2 \n"; 
    loan2.display(); 
    return 0; 
} 
