#include<iostream> 
#include "palindrome.h"
#include<string> 
using namespace std; 

int main() 
{ 
     string s1("Black"), s2("Black"); 
     unsigned int length1, length2; 

      // Find their lengths 
      length1 = s1.length(); 
      length2 = s2.length(); 
      // Compare their length 
      if(length1 == length2) 
      { 
           cout << "The two strings are the same length, are they the same? \n"; 
      } 

	  if(s1 == s2) 
      { 
           cout << "The two strings: "; 
           cout << s1 << " and " << s2 << " are the same \n";
      } 
      else 
      { 
          cout << "The two strings: "; 
          cout << s1 << " and " << s2 << " are NOT the same \n"; 
      } 

      cout << "Now I let you enter two strings\n"; 
      cout << "Enter the first string, then the second \n"; 

      cin >> s1 >> s2; 

      string comb = s1 + s2;

      cout << "The combination of the two strings is: " << comb;

      cout << "\n";

      if(Palindrome::is_pal(comb)){
        cout << "String is a palindrome";
      } else {
        cout << "String is not a palindrome.";
      }

      return 0; 
} 
