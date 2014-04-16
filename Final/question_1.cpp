#include <iostream> 
using namespace std; 

struct Node 
{ 
    double count; 
    Node *link; 
}; 

typedef Node* NodePtr; 
void head_insert(NodePtr& head, double a_number); 
void show_list(NodePtr& head); 
NodePtr search(NodePtr& head, double target);
NodePtr searchPtr(NodePtr head, NodePtr target);
void insert(NodePtr& after_me, double a_number);
void remove(NodePtr& before, NodePtr& discard);
void insert_after(NodePtr& head, double target, double a_number);
void remove(NodePtr& head, double target);
double findMin(NodePtr& head);

int main() 
{ 
    NodePtr head = NULL; 

    head_insert(head,4.8);
    head_insert(head,5.5);
    head_insert(head,6.6);
    head_insert(head,4.5);

    cout << "Original List:\n";
    show_list(head);

    cout << "After inserting node 2.2:\n";
    insert_after(head,6.6,2.2);
    show_list(head);

    cout << "After removing node 5.5:\n";
    remove(head,5.5);
    show_list(head);

    printf("The lowest count is %g\n",findMin(head));

    return 0; 
} 
void remove(NodePtr& head, double target){
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
void insert_after(NodePtr& head, double target, double a_number){
    NodePtr after_me = search(head,target);
    NodePtr newPtr = new Node;
    newPtr->count = a_number;
    NodePtr tempPtr = after_me->link;
    after_me->link = newPtr;
    newPtr->link = tempPtr;
}
void head_insert(NodePtr& head, double a_number) 
{ 

    NodePtr tmp_ptr;
    tmp_ptr = new Node;
    tmp_ptr->count = a_number;
    tmp_ptr->link = head;
    head = tmp_ptr;

} 
void show_list(NodePtr& head) 
{ 
    NodePtr here = head; 
    while (here != NULL) 
    { 
        cout << here-> count << endl; 
        here = here->link; 
    } 
}

NodePtr search(NodePtr& head, double target) 
{ 

    NodePtr here = head;
    if(here == NULL){
        return NULL;
    }
    else {
        while(here->count != target && here->link != NULL)
            here = here->link;
        if(here->count == target)
            return here;
        else
            return NULL;
    }

}

void insert(NodePtr& after_me, double a_number) 
{ 
    NodePtr temp_ptr; 
    temp_ptr = new Node; 
    temp_ptr -> count = a_number; 
    temp_ptr ->link = after_me -> link; 
    after_me ->link = temp_ptr; 
} 

void remove(NodePtr& before, NodePtr& discard)
{
    before -> link = discard -> link;
    delete discard;
    discard = NULL;
}


double findMin(NodePtr& head)
{
    double min;

    NodePtr here = head;
    if(here == NULL){
        return 0;
    }
    else {
        min = here->count;
        while(here->link != NULL){
            if(here->count < min){
                min = here->count;
            }
            here = here->link;
        }
    }

    return min;
}