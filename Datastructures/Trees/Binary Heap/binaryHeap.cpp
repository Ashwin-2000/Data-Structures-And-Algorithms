#include<iostream>

using namespace std;

class MinHeap {
    int *arr;
    int size , heap_size;

    public :
    MinHeap(int capacity){
        arr = new int[capacity];
        for(int i=0;i<capacity;i++){
            arr[i] = -99;
        }
        size = capacity;
        heap_size = 0;
    }

    int parent(int idx){
        if(idx<=0 || idx>heap_size){
            cout<<"Invalid Index"<<endl;
            return-99;
        }
        else 
            //Return the index parent element
            return (idx-1)/2;
    }

    int leftChild(int idx){
        if(idx<=0 || idx>heap_size){
            cout<<"Invalid Index";
            return -99;
        }
        //Return the index left child
        return (idx*2)+1;
    }
    
    int rightChild(int idx){
        if(idx<=0 || idx>heap_size){
            cout<<"Invalid Index";
            return -99;
        }
        //Return the index of right child
        return (idx*2)+2;
    }

    void insert(int val){
        if(heap_size==size){
            cout<<"Heap is full"<<endl;
            return;
        }

        int i = heap_size;
        heap_size++;

        //Insert the element
        arr[i] = val;

        //Check whethter inserting the element changes the heap property or not
        while( i!=0 && arr[parent(i)] > arr[i]){
            //Swap the element with the parent
            int pidx = parent(i);
            int temp = arr[pidx];
            arr[pidx] = arr[i];
            arr[i] = temp;
            //Change the current index to parent index
            i = pidx;
        }
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    
};

int main(){
    MinHeap *head = new MinHeap(5);
    head->insert(4);
    head->insert(3);
    head->print();

    head->insert(5);
    head->insert(1);
    head->print();

    head->insert(0);
    head->insert(0);
    head->print();
    return 0;
}