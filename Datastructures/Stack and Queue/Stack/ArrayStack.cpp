#include<iostream>

using namespace std;

class stack {
    //Top is indexed from 0 to N-1 therfore
    //      if stack is empty top = -1
    //      if stack is full  top = N-!
    int top = -1;
    int size = 0;
    int *stack;

public:
    
    //Create the stack
    void create(int n){
       
        stack = new int[n];
        for (int i = 0; i < n;i++){
            stack[i] = -99;
        }
        // stack = arr;
        top = -1;
        size = n;
    }

    //Push into the stack
    void push(int val){
        if(!isFull()){
            //Point the top to to new empty position and add the element
            stack[++top] = val;
        }
        else
            cout << "Stack is Full" << endl;
    }

    //Pop the top
    void pop(){
        if(!isEmpty()){
            //Remove the element at the top and move the top down
            stack[top--] = -99;
        }
        else
            cout << "Stack is empty" << endl;
    }

    //Top of the stack
    int peek(){
        if(!isEmpty)
            return stack[top];
        cout << "Stack is Empty" << endl;
        return -99;
    }

    //Stack is empty or not - UNDERFLOW
    int isEmpty(){
        return top == -1 ? 1 : 0;
    }

    //Stack is full or not - OVERFLOW
    int isFull(){
        return top == (size-1) ? 1 : 0;
    }

    //Printing the stack
    void dispaly(){
      
        for (int i = 0; i < size;i++){
            cout << stack[i] << " ";
        }
        cout <<" <- TOP"<< endl;
    }
};

int main() {
    stack s;
    s.create(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.dispaly();
    return 0;
}