#include<iostream>
#include<vector>
using namespace std;

//Create Node 
struct Node {
    int data;
    Node *next;

    Node(int val ){
        data = val;
        next = NULL;
    }
};

//Queue is Cricular Linked List
//In circular linked list the last node always points to the head
class Queue {

    Node *last=NULL;

    public : 
    //Push a node to Queue
    void enqueue(int data){
        Node *newnode = new Node(data);

        //If queue is empty
        if(!last){
            newnode->next = newnode;
            last = newnode;
            return;
        }
        //Make the new node points to the head which is last->next
        //Establish the new connection
        newnode->next = last->next;

        //Change the old connection
        last->next = newnode;

        //Change the last pointer
        last = newnode;
    }

    //Pop First node fron the queue
    void dequeue(){
        //Check for underflow
        if(last == NULL){
            cout << "Queue is empty" << endl;
            return;
        }

        //Remove the First added node (i.e) last->next;
        Node *delptr = last->next;
        int data = delptr->data;
        
        //Connect last pointer to the Second node
        last->next = delptr->next;

        
        //Last in the Queue
        if(last == delptr)
            last = NULL;

        delete (delptr);
    }


    //Front element in the Queue
    int front(){
        if(last == NULL)
        {
            cout << "The Queue is empty" << endl;
            return -1;
        }
        else{
            return last->next->data;
        }
    }

    //Last element in the Queue
    int rear(){
        if(last == NULL){
            cout<<"The Queue is empty"<<endl;
            return -1;
        }
        else{
            return last->data;
        }
    }

    //Print the queue
    void display(){
        Node *temp = last->next;

        do{
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
    }
};

int main(){
    Queue q;
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.front() << " " << q.rear() << endl;

    q.display();
    return 0;
}