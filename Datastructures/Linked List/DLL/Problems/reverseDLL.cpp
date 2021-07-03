#include<iostream>

using namespace std;

//Node of Doubly Linked List
struct Node{
    int data;
    Node *prev;
    Node *next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

//Doubly Linked List
class doublyLL {
    private :
        int size;
        Node *head=NULL;
        Node *tail=NULL;

    public:

    //Creating DLL using array
    void createDLL(int arr[] , int N){

        Node *prev = NULL;
        for (int i = 0; i < N;i++){
            Node *newnode = new Node(arr[i]);
            newnode->prev = tail;
            if(tail==NULL){
                tail = newnode;
                head = newnode;
            } else {
                tail->next = newnode;
                tail = newnode;
            }
            
        }
    }

     void reverseDLL(){
        if(head==NULL || head->next==NULL)
            return;

        //If we revers the DLL the head and tail will be interchanges
        Node *newhead = tail;
        Node *newtail = head;
        
        Node *curr = head;
        Node *temp = NULL;

        while(curr){

            //Swap the next and prev pointer
            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;

            //Move to the next node
            curr = temp;
        }

        //Change the head and tail to the new postion
        head = newhead;
        tail = newtail;
    }

    private : 
    Node* reverseUtil(Node *top){
        if(top == NULL || top->next == NULL)
            return top;

        Node *swap = NULL,*prev=NULL;

        while(top){
            cout << top->data << endl;
        
            prev = top;
            swap = top->next;
            top->next = top->prev;
            top->prev = swap;
            top = swap;
        }
        Node *x;
        for (x = prev; x->next != NULL;x=x->next)
            cout << x->data<<" ";
        cout << x->data<<endl;
        for (; x->prev != NULL;x=x->prev)
            cout << x->data << " ";
        cout << x->data<<endl;
        
        return prev;
    }
    public :
    void reverseByparts(int k){
        if(head==NULL)
            return;
        
        //Count and validate k
        int count = 0;
        for (Node *temp = head;temp!=NULL;count++,temp=temp->next);
        if(k>=count)
            return;

        //Search for Key node where to be sepperated
        Node *temp = head;
        for (int i = 1; i < k;i++){
            temp = temp->next;
        }

        cout << "Kth element : " << temp->data << endl;
       
        Node *newhead , *newtail , *twofirst , *onefirst;

        //Note the tobe head and tail
        newhead = temp;
        newtail = temp->next;

        //Divide into two list
        onefirst = head;
        twofirst = temp->next;
        temp->next->prev = NULL;
        temp->next = NULL;
      

        //Reverse the first part
        cout << "Ist part" << endl;
        onefirst = reverseUtil(onefirst);
        cout << "Head : " << head->data<<endl;
        
        //Reverse the second part
        cout << "IInd part" << endl;
        twofirst = reverseUtil(twofirst);
        cout << "two = " << twofirst->data << endl;

        //Join the list
        head->next = twofirst;
        twofirst->prev = head;

        //Assign the new head and tail
        head = newhead;
        tail = newtail;
    }


    void printDLL(){
        
        cout << "HEAD -> ";
        for (Node *temp = head; temp != NULL;temp=temp->next)
            cout << temp->data << "->";
        cout << "NULL" << endl;
        cout << "TAIL -> ";
        for (Node *temp = tail; temp != NULL;temp=temp->prev)
            cout << temp->data << "->";
        cout << "NULL" << endl;
    }


};
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int N = sizeof(arr) / sizeof(arr[0]);
    doublyLL dll;
    dll.createDLL(arr, N);
    dll.reverseDLL();
    dll.printDLL();
    return 0;
}