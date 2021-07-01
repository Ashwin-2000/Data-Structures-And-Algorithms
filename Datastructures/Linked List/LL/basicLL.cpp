#include<iostream>
using namespace std;

//Node in a list
struct Node{
    int data;
    Node *next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

//Linked List
class LinkedList{

    //Compulsory
    Node *head=NULL;

    //Optional
    Node *tail;
    int size=0;


    public:
    //INSERTION
    void insertBegin(int val){
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }

    //Using Double Pointer
    void insertAt(int pos , int val){
        if(pos < 0){
            cout << "Invalid Position" << endl;
            return;
        }
        Node *newnode = new Node(val);
        Node **temp = &head;
        //Using "temp" I can access Head pointer
        //Using "*temp" I can access the value at Head
        int i = 0;
        while(*temp && i!= pos){

            //Making temp to point the "next" pointer
            temp = &(*temp)->next;
            i++;
        }

        //This condition when the pos is greater than size of list
        if( i != pos){
            cout << "Pos is greater then size" << endl;
            return;
        }

        //Now Temp points to "next" in current Node
        //*temp is the next Node i.e valu at "next"
         newnode->next = *temp;
        *temp = newnode;
        // cout << "Invalid Insert Operation" << endl;
    }

    //Using Double Pointer
    void insertEnd(int val){
        Node *newnode = new Node(val);
        Node **temp = &head;
        while(*temp){
            temp = &(*temp)->next;
        }
        //At the end of the loop 
            //temp will be pointing to the "next" pointer of the LAST node and "temp*" will be NULL
        *temp = newnode;
    }

    //DELETION
    void deleteHead(){
        Node *delptr = head;
        head = head->next;
        delete (delptr);
    }

    void deleteAt(int pos){
        Node **temp = &head;
        int i = 0;
        while(*temp){
            if(i==pos){
                Node *delptr = *temp;
                *temp = (*temp)->next;
                delete (delptr);
                return;
            }
            i++;
            temp = &(*temp)->next;
        }
        cout << "Invalid Position" << endl;
    }

    void deleteVal(int val){
        Node **temp = &head;

        while(*temp){
            if((*temp)->data == val){
                Node *delptr = *temp;
                (*temp) = (*temp)->next;
                delete (delptr);
                return;
            }
            temp = &(*temp)->next;
        }
    }

    void deleteEnd(){
       if(!head)
           return;
        Node *temp = head;

        for (; temp->next != NULL; temp=temp->next)
            ;
        Node *delptr = temp->next;
        delete (delptr);
    }

    void printlist(){
        for (Node *temp = head; temp != NULL;temp=temp->next){
            cout << temp->data << "->";
        }
        cout << "NULL" << endl;
    }
};

int main(){
    LinkedList list;

    list.insertEnd(0);
    list.deleteAt(0);

    list.insertAt(0,3);
    list.insertBegin(2);
    list.insertAt(0, 1);
    list.insertAt(3, 4);
    list.deleteEnd();

    list.insertEnd(5);
    list.insertAt(5, 6);
    
    // list.printlist();
    list.printlist();
    return 0;
}