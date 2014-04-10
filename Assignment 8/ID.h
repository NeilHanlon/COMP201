#ifndef ID_H
#define ID_H
#include <iostream>

using namespace std;

class ID 
{ 
    public: 
        ID(); 
        ID(int, int, int); 
        void display(); 
    private: 
        int left; 
        int middle; 
        int right; 
}; 

#endif