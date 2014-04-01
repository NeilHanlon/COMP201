#include <iostream> 
#include <cstddef> 
#include <string> 
using namespace std;
struct Node 
{ 
	string name; 
	int employees;
	Node *link; 
};
typedef Node* NodePtr;

NodePtr search(NodePtr head, string target); 
NodePtr searchPtr(NodePtr head, NodePtr target);
void head_insert(NodePtr& head, string name, int employees); 
void show_list(NodePtr& head);
void insert_after(NodePtr& head, string target, NodePtr newPtr);
void remove(NodePtr& head, string target);

int main() 
{ 
	NodePtr head = NULL;
	head_insert(head, "Google", 18500);
	head_insert(head, "BCG", 1958);
	head_insert(head, "SAS", 6046);
	head_insert(head, "WFM", 41717);
	head_insert(head, "EJ", 36937);
	head_insert(head, "NetApp", 6887);
	head_insert(head, "CPT", 1678);
	head_insert(head, "REI", 10466);
	head_insert(head, "CHGHS", 1312);
	head_insert(head, "QL", 3808);
	NodePtr ptr2 = new Node;
	ptr2->name = "Neil";
	ptr2->employees = 100;

	show_list(head); 
	insert_after(head, "CPT", ptr2);
	show_list(head); 
	remove(head, "Neil");
	show_list(head);
	return 0; 
}
void remove(NodePtr& head, string target){
	NodePtr to_remove = search(head,target);
	NodePtr before = searchPtr(head,to_remove);
	before->link = to_remove->link;
	//delete to_remove;
}
NodePtr searchPtr(NodePtr head, NodePtr target){
	NodePtr here = head;
	if(here == NULL){
		return NULL;
	} else {
		while(here->link != target && here->link != NULL)
			here = here->link;
		if(here->link == target)
			return here;
		else
			return NULL;
	}

}
void insert_after(NodePtr& head, string target, NodePtr newPtr){
	NodePtr after_me = search(head,target);
	NodePtr tempPtr = after_me->link;
	after_me->link = newPtr;
	newPtr->link = tempPtr;
}
NodePtr search(NodePtr head, string target) 
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
		while (here-> name != target && here->link != NULL) 
			here = here->link; 
		if (here-> name == target) 
			return here; 
		else 
			return NULL;
	} 
} 
void head_insert(NodePtr& head, string name, int employees) 
{ 
	NodePtr temp_ptr; 
	temp_ptr = new Node; 
	temp_ptr->name = name; 
	temp_ptr-> employees = employees; 
	temp_ptr->link = head; 
	head = temp_ptr; 
} 
void show_list(NodePtr& head) 
{ 
	NodePtr here = head;
	cout << "Name\tEmployees\n----\t-----\n";
	while (here != NULL) 
	{ 
		cout << here-> name << "\t"; 
		cout << here-> employees << "\n";
		here = here->link; 
	} 
}