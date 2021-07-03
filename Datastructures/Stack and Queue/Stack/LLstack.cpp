#include<iostream>

using namespace std;

//Node in stack
struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

//Stack
class stack {
    Node *head = NULL;
    
    public : 
    //Insert at begining
    void push(int val){
        Node *newnode = new Node(val);
        newnode->next = head;
        head = newnode;
    }

    //Delete at the head
    void pop(){
        if(!isEmpty()){
            Node *delptr = head;
            head = head->next;
            delete (delptr);
        }
        else
            cout << "Stack is empty" << endl;
    }

    //Value at the top
    int top(){
        if(head)
            return head->data;
        cout << "Stack is empty"<<endl;
        return -99;
    }

    int isEmpty(){
        return head ? 0 : 1;
    }

    void display(){
        if(!head){
            cout << "Stack is empty" << endl;
            return;
        }
        for (Node *temp = head; temp != NULL;temp=temp->next){
            cout << temp->data << " ";
        }
        cout << endl;
    }
};

int main(){
    stack s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(3);
   
    s.display();
    return 0;
}