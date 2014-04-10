#include <iostream> 
#include <cstddef> 
#include <string> 
using namespace std;
struct Node 
{ 
    string item; 
    int count;
    string expiration;
    Node *link; 
};
typedef Node* NodePtr; 
void head_insert(NodePtr& head, string an_item, int a_number, string expire); 
void show_list(NodePtr& head); 
int main() 
{ 
    NodePtr head = NULL;
    head_insert(head, "Tea", 2, "08/10/2003"); 
    head_insert(head, "Jam", 3, "09/12/2003"); 
    head_insert(head, "Rolls", 10, "01/01/2010"); 
    show_list(head); 
    return 0; 
} 
void head_insert(NodePtr& head, string an_item, int a_number, string expire) 
{ 
    NodePtr temp_ptr; 
    temp_ptr = new Node; 
    temp_ptr-> item = an_item; 
    temp_ptr-> count = a_number; 
    temp_ptr->expiration = expire;
    temp_ptr->link = head; 
    head = temp_ptr; 
} 
void show_list(NodePtr& head) 
{ 
    NodePtr here = head;
    cout << "Item\tCount\tExpiration\n----\t-----\t----------\n";
    while (here != NULL) 
    { 
      cout << here-> item << "\t"; 
      cout << here-> count << "\t";
      cout << here-> expiration << "\n"; 
      here = here->link; 
  } 
}