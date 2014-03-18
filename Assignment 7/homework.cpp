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
NodePtr search(NodePtr head, string an_item, int choice); 
void head_insert(NodePtr& head, string an_item, int a_number, string expire); 
void show_list(NodePtr& head); 
int main() 
{ 
    NodePtr head = NULL; 
    head_insert(head, "Tea", 2, "08/10/2003"); 
    head_insert(head, "Jam", 3, "09/12/2003"); 
    head_insert(head, "Rolls", 10, "01/01/2010"); 
    cout << "List contains:" << endl; 
    show_list(head);


    string target;
    int choice;
    cout << "What would you like to search for?\nEnter 1 to search by name, 2 to search by expiration\n";
    cout << "Choice: "; cin >> choice;
    do{
        if(choice > 2){
            cout << "Invalid Choice. Exiting.";
            return 0;
        }
        cout << "Enter an " << ((choice == 1) ? "item" : "expiration date") << " to search for: " << endl; 
        cin >> target; 
        if (search(head, target, choice)) 
            cout << target << " is on the list." << endl; 
        else 
            cout << target << " is not on the list." << endl;
        cout << "What would you like to search for?\nEnter 1 to search by name, 2 to search by expiration, 0 to exit\n";
        cout << "Choice: "; cin >> choice;
    }while(choice > 0); 
 return 0; 
} 
NodePtr search(NodePtr head, string target, int choice) 
{ 
   // Point to the head node 
    NodePtr here = head; 
    // If the list is empty nothing to search 
    if (here == NULL) 
    { 
        return NULL; 
    } 
    // Search for the item 
    else 
    { 
        switch(choice){
            case 1:
                while (here-> item != target && here->link != NULL) 
                    here = here->link; 
                if (here-> item == target) 
                    return here; 
                else 
                    return NULL; 
                break;
            case 2:
                while (here->expiration != target && here->link != NULL)
                    here = here->link;
                if (here->expiration == target)
                    return here;
                else
                    return NULL;
                break;
        }
    } 
} 
void head_insert(NodePtr& head, string an_item, int a_number, string expire) 
{ 
    NodePtr temp_ptr; 
    temp_ptr = new Node; 
    temp_ptr -> item = an_item; 
    temp_ptr -> count = a_number; 
    temp_ptr -> expiration = expire;
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
