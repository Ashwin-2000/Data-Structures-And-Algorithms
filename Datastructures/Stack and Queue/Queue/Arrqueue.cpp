#include<iostream>

using namespace std;

class Queue {
    int front, rear, size;
    int *arr ;

    public : 
    void createQ(int N){
        arr = new int[N];
        for (int i = 0; i < N; i++){
            arr[i] = -99;
        }
        size = N;
        front = -1;
        rear = -1;
    }

    void enqueue(int val){
        //Check for overflow
        if(rear+1 == size)
        {
            cout << "Queue is FUll" << endl;
            return;
        }

        //Initail Condition
        if(front == -1 ){
            front = 0;
        }

        //Add to the queue
        arr[++rear] = val;
    }

    void dequeue(){
        //Check for the under flow
        if(front == -1){
            cout<<"Queue is empty "<<endl;
            return;
        }

        //If front and rear points to only one node i.e Last node then initialize front and rear
        //Last node condition
        if( front == rear){
            arr[front] = -99;
            front = rear = -1;
            return;
        }

        //Shif all the element to the left by one
        //This step is to use the array at its fullest potential
        for (int i = 0; i <= rear;i++){
            arr[i] = arr[i + 1];
        }
        rear--;
        cout << "Rear idx : " << rear << endl;
        }

        //Front of the Queue
        int Front(){
            if(front == -1){
                cout<<"Queue is empty";
                return -1;
            }
            return arr[front];
        }

        //Rear of the Queue
        int Rear(){
            if(rear == -1){
                cout << "Queue is empty";
                return -1;
            }
            return arr[rear];
        }

            //Display
            void display()
            {
                if (front == -1)
                {
                    cout << "Queue is empty" << endl;
                    return;
                }
                cout << front << " " << rear << endl;
                cout << "Front : " << arr[front] << endl;
                cout << "Rear : " << arr[rear] << endl;
                for (int i = 0; i < size; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
};


int main(){

    Queue q;
    q.createQ(5);
    q.enqueue(0);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();
    cout << q.Front() << " " << q.Rear() << endl;

    q.dequeue();
    cout << q.Front() << " " << q.Rear() << endl;
    q.dequeue();
    cout << q.Front() << " " << q.Rear() << endl;
    q.dequeue();
    cout << q.Front() << " " << q.Rear() << endl;

    q.dequeue();
    cout << q.Front() << " " << q.Rear() << endl;

    q.dequeue();
    cout << q.Front() << " " << q.Rear() << endl;

    q.display();
    return 0;
}