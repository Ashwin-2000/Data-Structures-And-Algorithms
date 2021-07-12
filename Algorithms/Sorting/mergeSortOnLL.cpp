#include<iostream>

using namespace std;

//Node for the list
struct Node {
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void printList(Node *head);
//Dividing the list
void splitAtmid(Node *head , Node **left , Node **right){
    
    Node *fast = head->next;
    Node *slow = head;

    while(fast && fast->next){
        fast = fast->next;
        if(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    //Left List
    *left = head;
    //Right List
    *right = slow->next;
    //Break the list
    slow->next = NULL;
}

//Mergeing the list
Node*  SortedMerge(Node *left , Node *right){

    //BASE CASE : If only one list is NULL return other
    if(left == NULL) return right;
    if(right == NULL) return left;
    
    //The head and tail of new list on merging left and right
    Node *result , *temp;

    //Initialize the new head - result
    if(left->data <= right->data){
        result = left;
        left = left->next;
    }
    else{
        result = right;
        right = right->next;
    }
    temp=result;

    
    while( left && right){
        //Find the min of left and right and add at the end of tail
        if(left->data <= right->data){
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        else{
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
    }

    //If there is any remaining elements in left or right add to list
    while(left){
        temp->next = left;
        left = left->next;
        temp=temp->next;
    }

    while(right){
        temp->next = right;
        right = right->next;
        temp=temp->next;
    }
    
    return result;
    //     Node* result = NULL;
    // /* Base cases */
    // if (a == NULL)
    //     return (b);
    // else if (b == NULL)
    //     return (a);
 
    // /* Pick either a or b, and recur */
    // if (a->data <= b->data) {
    //     result = a;
    //     result->next = SortedMerge(a->next, b);
    // }
    // else {
    //     result = b;
    //     result->next = SortedMerge(a, b->next);
    // }
    // return (result);
}

Node *recurrSortedMerge(Node *left , Node *right){
    if( left == NULL ) return right;
    if( right == NULL ) return left;

    Node *result = NULL;
    if(left->data >= right->data){
        result = left;
        result -> next= recurrSortedMerge(left->next , right);
    }
    else {
        result = right;
        result->next = recurrSortedMerge(left , right->next);
    }
    return result;
}

//MergeSort 
void mergeSort( Node **head){
    //BASE CASE : List is empty of only one element 
    if(!(*head) || !(*head)->next)
        return;
    
    Node *left =NULL, *right =NULL;

    //Divide the list here
    splitAtmid(*head , &left , &right);

    mergeSort(&left);
    mergeSort(&right);

    //Conquer the list here
    *head = recurrSortedMerge(left , right);
    printList(*head);
    
}

//Print the Linked List
void printList(Node *head){
    for(Node*temp = head;temp!=NULL;temp=temp->next){
        cout<<temp->data<<" ";
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(9);
    head->next = new Node(5);
    head->next->next=new Node(3);
    head->next->next->next=new Node(2);
    head->next->next->next->next=new Node(7);
    head->next->next->next->next->next=new Node(3);
    printList(head);
    mergeSort(&head);
    printList(head);

    return 0;
}