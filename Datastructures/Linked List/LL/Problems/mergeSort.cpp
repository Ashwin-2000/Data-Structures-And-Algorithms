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
Node *head = NULL;
void createList(int arr[] , int N){
    Node *tail;
    for (int i = 0; i < N;i++){
        Node *newnode = new Node(arr[i]);
        if(i==0){
            head = newnode;
            tail = newnode;
            continue;
        }
        tail->next = newnode;
        tail = tail->next;
        }
}

//Find Middle
Node* findMiddle(Node* head){

}

//Merger
void merger(Node* h1 , Node* h2){

}

//Merge Sort
void mergerSort(Node* start , Node* end){

}

//Print list
void printList(Node* head){
    for (Node *temp = head; temp != NULL; temp = temp->next){
        cout << temp->data << " -> ";
    }
    cout << "NULL"<<endl;
}

int main(){
    int arr[] = {8, 1, 4, 3, 6, 9, 7, 2, 10, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    createList(arr, N);
    printList(head);
    return 0;
}