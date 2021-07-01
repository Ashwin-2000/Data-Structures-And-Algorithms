#include<iostream>

using namespace std;

//Node
struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

//Linked List
class LinkedList{
    Node *head = NULL;

    public:

    void createList(int arr[] , int N){
        Node *tail = head;
        for (int i = 0; i < N;i++){
            Node *newnode = new Node(arr[i]);
            if(!head){
                head = newnode;
                tail = head;
            }
            else{
                tail->next = newnode;
                tail = tail->next;
            }
        }
    }

    void reverseItr(){
        if(head == NULL)
            return;

        //We use two pointer to track current Node and Previous Node 
        Node *prev, *curr;
        
        //Intially conditions :
            //Set prev Node to 1st element in the list
            //Set head and current node to the second element in the list
        prev = head;
        curr = head->next;
        head = head->next;
        prev->next = NULL;

        while(curr){
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }

        //At the end of the while loop curr and head will be at NULL
        //Prev will be at the Last Node
        head = prev;
    }

    //Reverse Using Recurrsion
    void reverseRecurr(){

        //During reversing we assign curr->next to prev

        //For first node prev= NULL :: Curr = head --- Prev = NULL
        reverseRecurrUtil(head, NULL);
    }

    void reverseRecurrUtil(Node*curr , Node* prev){
        if(curr==NULL){
            head = prev;
            return;
        }
        //Iterate to the end using recursion then change from the alst
        reverseRecurrUtil(curr->next, curr);
        curr->next =  prev;
    }


    
    void reverseKthidx(int k){
        if(head == NULL || k<1)
            return;

        //There would be two list if we break the list at k
            //LIST 1 : 0 - k    ==> head1 tail1
            //LIST 2 : k+1 - N  ==> head2 tail2
        //We need to connect "tail2 with head2" after reversing each list
       
       //last ==> lastnode @ LIST 1
       //first ==> firstnode @ LIST 1 which would be head
      
        Node *last ,*first;


        Node *curr, *prev;
        prev = head;
        curr = head->next;
        head = curr;
        prev->next = NULL;
        last = prev;

        int i = 1;

        while(curr){
            if( i==k ){
                cout << "Enterted First : "<<prev->data<<endl;
                //Marking the Head of the List
                first = prev;

                //Initalizing reversing of List 2
                prev = head;
                head = head->next;
                curr = head;
                prev->next = NULL;
                i++;
                //Important
                continue;
            }
            cout << " head : " << head->data << " prev : " << prev->data << " i : "<<i<<endl;
            head = head->next;
            curr->next = prev;
            prev = curr;
            curr = head;
            i++;

        }
        cout << "First : " << first->data << " prev : " << prev->data <<" "<<prev->next<< " last : " << last->data << endl;
         //prev at end of reversing will contain last element which is head of LIST2
        last->next = prev;
        head = first;
    }

    void printList(){
        for (Node *temp = head; temp != NULL; temp=temp->next){
            cout << temp->data << "->";
        }
        cout << "NULL" << endl;
    }
};

int main(){
    int arr[] = {1,2,3,4,5,6};
    int N = sizeof(arr) / sizeof(arr[0]);

    LinkedList list;
    list.createList(arr, N);
    list.printList();
    list.reverseKthidx(1);
    list.printList();
    return 0;
}