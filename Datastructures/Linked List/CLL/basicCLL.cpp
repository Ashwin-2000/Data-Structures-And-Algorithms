#include<iostream>

using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class circularLL {
    Node *head=NULL, *last=NULL;

    public : 
    //Insert at the Begining
    void insertNode(int val){

        Node *newnode = new Node(val);
        //List is empty
        if(head==NULL){
            head = newnode;
            last = newnode;
            head->next = head;
        }
        //List is not empty
        else{
            last->next = newnode;
            newnode->next = head;
            last = newnode;
        }
    }

    //Insert after
    void insertAfter(int key , int val){
        if(head==NULL)
            return;
        Node *temp = head;
        do{
            if(temp->data == key){
                Node *newnode = new Node(val);
                newnode->next = temp->next;
                temp->next = newnode;
                if(newnode->next == head)
                    last = newnode;
                cout << newnode->next->data << endl;
            }
            temp = temp->next;
        } while (temp != head);
    }

    
    //Delete at begining
    void deleteBegin(){
        if(head == NULL)
            return;

        Node *delptr = head;
        if(head==last){
            head = NULL;
            last = NULL;
        }
        else
        {
            head = head->next;
            last->next = head;
        }
        delete (delptr);
    }

    //Delete the val
    void deleteVal(int key){
        //List is empty
        if(head==NULL)
            return;

        //One one node
        if(head->next==NULL){
            if(head->data = key){
                Node *delptr = head;
                head = NULL;
                last = NULL;
                delete (delptr);
            }
            return;
        }

        //More than One node
        int count = 1;
        for (Node *temp = head->next; temp != head;temp=temp->next,count++);
        Node *temp = head , *prev=last;
        for (int i = 0; i < count; i++, temp = temp->next,prev=prev->next){
            if(temp->data == key){
                Node *delptr = temp;
                prev->next = temp->next;
                //If the key is head or tail we need to move it
                if(temp==head || temp==last){
                    temp==head ? head = head->next : last=prev;
                }
                delete (delptr);
                break;
            }
        }
    }

    //Delete the end
    void deleteEnd(){
        //List is empty
        if(head == NULL)
            return;

        //List contains One element
        if(head==last){
            Node *delptr = head;
            head = NULL;
            last = NULL;
            return;
        }

        //List contains more than one
        Node *delptr = last,*temp;
        for (temp = head; temp->next != last;temp=temp->next);
        temp->next = head;
        delete (delptr);
    }

    //Print the nodes
    void printList(){
        cout << "HEAD -> ";
        if(!head){
            cout << "NULL -> LAST" << endl;
            return;
        }
        Node *temp = head;
        do{
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << " LAST" << endl;
    }

};

int main(){
    circularLL cll;
    cll.insertNode(0);
    cll.insertNode(1);
    cll.insertNode(2);
    cll.printList();
    cll.deleteVal(2);
    cll.printList();
    return 0;
}