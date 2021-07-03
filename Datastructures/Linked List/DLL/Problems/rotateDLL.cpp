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


    void rotateDLL(int n){

        int count = 0;
        for (Node *temp = head; temp != NULL;temp=temp->next,count++);

        //Finding modulus to reduce the no. of rotaion and to find the element at the head from last
        int rotate = n % count;

        if(rotate == 0 || count==0)
            return;

        Node *newhead = NULL, *newTail = NULL;

        //To find the Node of tail and head
        Node *temp=tail;
        for (int i=0; i < rotate-1; temp=temp->prev,i++);

        //Make the DLL to Circular DLL
        head->prev = tail;
        tail->next = head;

        //Change the head and tail to the new position
        head = temp;
        tail = temp->prev;

        //Break the chain
        head->prev = NULL;
        tail->next = NULL;
    }

};
int main(){
    int arr[] = {1,2,3,4,5,6,7,8};
    int N = sizeof(arr) / sizeof(arr[0]);
    doublyLL dll;
    dll.createDLL(arr, N);
    dll.printDLL();
    return 0;
}