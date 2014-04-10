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
NodePtr createNode(string name, int employees);
void updateEmployees(NodePtr& head, string target, int employees);
void replaceNode(NodePtr& head, string target, NodePtr newPtr);


int main() 
{
	NodePtr head = NULL;
	head_insert(head, "Google", 18500);
	insert_after(head, "Google", createNode("BCG", 1958));
	insert_after(head, "BCG", createNode("SAS", 6046));
	insert_after(head, "SAS", createNode("WFM", 41717));
	insert_after(head, "WFM", createNode("EJ", 36937));
	insert_after(head, "EJ", createNode("NetApp", 6887));
	insert_after(head, "NetApp", createNode("CPT", 1678));
	insert_after(head, "CPT", createNode("REI", 10466));
	insert_after(head, "REI", createNode("CHGHS", 1312));
	insert_after(head, "CHGHS", createNode("QL", 3808));
	printf("Original list:\n");
	show_list(head);

//update list:
	/*//remove all changing nodes (not the best way.. but it works)
	remove(head,"BCG");
	remove(head,"CHGHS");
	remove(head,"WFM");
	remove(head,"SAS");
	remove(head,"EJ");
	remove(head,"CPT");
	remove(head,"REI");
	remove(head,"CHGHS");
	remove(head,"QL");*/


	updateEmployees(head,"Google",34311);
	replaceNode(head,"CHGHS",createNode("Ultimate",1440));
	replaceNode(head,"SAS",createNode("CHGHS",1378));
	replaceNode(head, "BCG", createNode("SAS",6373));
	replaceNode(head,"WFM",createNode("BCG",2314));
	replaceNode(head,"EJ",createNode("WFM",43927));
	updateEmployees(head,"NetApp",7426);
	replaceNode(head,"CPT",createNode("Hilcorp", 1012));
	replaceNode(head,"REI",createNode("EJ",35114));
	replaceNode(head,"QL",createNode("CPT",1896));

	show_list(head);

	return 0; 
}/**
FROM:
Google	18500	=>	Google	34311
BCG		1958	=>	SAS		6373
SAS		6046	=>	CHGHS	1378
WFM		41717	=> 	BCG		2314
EJ		36937	=>	WFM		43927
NetApp	6887	=> 	NetApp	7426
CPT		1678	=>	Hilcorp	1012
REI		10466	=>	EJ		35114
CHGHS	1312	=>	Ultimate(1440)
QL		3808	=>	CPT		1896
**/
void replaceNode(NodePtr& head, string target, NodePtr newPtr){
	NodePtr tmpPtr = search(head,target);
	tmpPtr->name = newPtr->name;
	tmpPtr->employees = newPtr->employees;
}
void updateEmployees(NodePtr& head, string target, int employees){
	NodePtr targetNode = search(head,target);
	targetNode->employees = employees;
}
NodePtr createNode(string name, int employees){
	NodePtr tmp = new Node;
	tmp->name = name;
	tmp->employees = employees;
	return tmp;
}
void remove(NodePtr& head, string target){
	NodePtr to_remove = search(head,target);
	NodePtr before = searchPtr(head,to_remove);
	before->link = to_remove->link;
	delete to_remove;
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