#include<iostream>

using namespace std;

//Node
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
class doublyLinkedList{
    private :
        Node *head = NULL;
        Node *tail = NULL;
        int size = 0;
    
    public : 

        //Inserting at the beginning
        void insertBegin(int val){
            Node *newnode = new Node(val);
            newnode->next = head;

            //List is empty
            if(!head)
                tail = newnode;
            //List not empty
            else
                head->prev = newnode;
            head = newnode;
            size++;
        }

        //Inserting at the Index
        void insertAt(int pos , int val){

            if(pos<0 || pos>size){
                cout << "Invalid Position" << endl;
                return;
            }

            //Inserting at first and last position
            if( pos==0 || pos==size){
                pos == 0 ? insertBegin(val) : insertEnd(val);
                return;
            }

            Node *newnode = new Node(val);
            
            //Search for pos
            Node *temp = head;
            for (int i = 0; i < pos;i++,temp=temp->next);

            //Estabilsh the connection
            newnode->prev = temp->prev;
            newnode->next = temp;

            //Remove the old connection
            newnode->prev->next = newnode;
            newnode->next->prev = newnode;

            size++;
        }

        //Inserting after Index
        void insertAfter(int pos , int val){
            if(pos<0 || pos>=size ){
                cout << "Invalid Position" << endl;
                return;
            }

            //Serach for the pos
            Node *temp = head;
            for (int i = 0; i < pos;i++,temp=temp->next);

            Node *newnode = new Node(val);
            //Establish new connections
            newnode->prev = temp;
            newnode->next = temp->next;

            //Change Old Connections
            newnode->prev->next = newnode;

            //Inserting at last node
            if(!newnode->next){
                tail = newnode;
            }
            //Inserting other than end
            else{
                newnode->next->prev = newnode;
            }

            size++;
        }

        //Inserting at the end
        void insertEnd(int val){
            Node *newnode = new Node(val);
            newnode->prev = tail;

            //List is empty
            if(!tail){
                head = newnode;
            }
            //List is not empty
            else{
                tail->next = newnode;
            }

            tail = newnode;

            size++;
        }

        //Delete at begining
        void deleteBegin(){
            if(head ==NULL)
                return;
            
            Node *delptr = head;
            head = head->next;

            //List is not empty at deletion
            if(head){
                head->prev = NULL;
            }
            //List is empty at the deletion
            else {
                tail = NULL;
            }

            delete (delptr);

            size--;
        }

        //Delete at index
        void deleteAt(int pos){
            if(pos<0 || pos>=size){
                cout << "Invalid Position" << endl;
                return;
            }

            if(pos==0 || pos==(size-1)){
                pos == 0 ? deleteBegin() : deleteEnd();
                return;
            } 
            Node *delptr = head;
            for (int i = 0; i < pos;i++,delptr=delptr->next);

            delptr->prev->next = delptr->next;
            delptr->next->prev = delptr->prev;

            delete (delptr);

            size--;
        }

        //Delete the val
        void deleteVal(int val){
            if(head == NULL)
                return;

            Node *temp = head;
            while(temp){
            
                if(temp->data == val){
                
                    Node *delptr = temp;
                    //Deleting the incomming connections
                        //"next" pointer of Previous Node
                            //delptr points to the head
                            //delptr points other than head
                        //"prev" pointer of Next Node
                            //delptr points to the tail
                            //delptr points other than tail


                    if(delptr->prev){
                        delptr->prev->next = delptr->next;
                    }
                    else{
                        head = delptr->next;
                    }


                    if(delptr->next){
                        delptr->next->prev = delptr->prev;
                    }
                    else {
                        tail = tail->prev;
                    }

                    delete (delptr);
                }

                temp = temp->next;
            }
            
        }

        //Delete the end
        void deleteEnd(){
            if (tail ==NULL)
                return;
            
            Node *delptr = tail;
            tail = tail->prev;

            //List is empty at deletion
            if(!tail){
                head = NULL;
            }
            //List is not empty
            else{
                tail->next = NULL;
            }

            delete (delptr);
        }

        //Print the list
        void printList (){

            cout << "HEAD ->";
            for (Node *temp = head; temp != NULL;temp=temp->next)
                cout << temp->data << "->";
            cout << "NULL"<< endl;
            cout << "TAIL ->";
            for (Node *temp = tail; temp != NULL; temp=temp->prev)
                cout << temp->data << "->";
            cout << "NULL" << endl;
        }
};

int main(){
    doublyLinkedList dll;

    dll.insertBegin(0);
    dll.insertEnd(2);
    dll.insertAfter(0, 1);
    dll.printList();

    dll.deleteVal(2);
    dll.printList();

    return 0;
}