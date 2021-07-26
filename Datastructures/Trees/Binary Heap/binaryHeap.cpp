#include<iostream>

using namespace std;

class Minheap {
    int *arr;

    public : 
    int capacity = 0;
    int heap_size = 0;

  

    //TO get the index of the parent
    int parent(int idx){
        return (idx-1)/2;
    }

    //TO get the left child
    int leftChild(int idx){
        return (2*idx)+1;
    }

    //TO get the right hild
    int rightChild(int idx){
        return (2*idx)+2;
    }

    void swap(int *a , int *b){
        int temp = *a;
        *a = *b;
        *b = temp;        
    }
    
    int extractMin(){
        if(heap_size==0)
         {   cout<<"Heap is empty"<<endl;
            return INT16_MAX;
         }
        
        //Extrating the root element which the smallest of all
        int min = arr[0];
        //Change the last element as root
        arr[0] = arr[heap_size-1];
        arr[heap_size-1] = -1;
        heap_size--;
        //Call heapify to estabilsh heap property with last node as root node
        Heapify(arr, heap_size , 0);
        return min;
    }

    void decereaseKey(int i, int val){
        arr[i] = val;
        int root = parent(i);
        cout<<root<<endl;
        //Traverse in reverse to check the insertion violates the heap property
        //If so , swap the parent with i , and check if it violates the heap.
        while(i>=0 && arr[root] > arr[i]){
            swap(&arr[root] , &arr[i]);
            i=root;
            root=parent(i);
            cout<<root<<" "<<i<<endl;

        }
    }

    void deleteKey(int i){
        //To delete a key we make the element at the index so minimum so that it would become root node
        //Then we can delete it
        decereaseKey(i,INT16_MIN);
        extractMin();
    }

    void insert( int num ){
        if(heap_size == capacity){
            cout<<"Heap is full "<<endl;
            return;
        }
        //Insert the heap at last node , to maintain it as compelete binary tree
        arr[heap_size]=num;
        int idx = heap_size;
        heap_size++;

        //Find the parent and check if it violates heap property or not
        int root = parent(idx);

        if(root >= 0){
            if(arr[root] > arr[idx]){
                Heapify(arr , heap_size , root );
            }
        }
        //We insert the element at the end of the heap
    }

    //TO MAINTAIN THE HEAP PROPERTY IN ARRAY
    void Heapify(int arr[] , int n , int root){
        
        //Root must be smallest or if the subtree is in heap property we need to avoid swapping
        int smallest  = root;
        cout<<"root"<<arr[root]<<endl;
        //Left & Right child index
        int left = leftChild(root);
        int right = rightChild(root);

        cout<<"LEft child : "<<arr[left]<<endl;
        cout<<"right child : "<<arr[right]<<endl;

        if(left < n && arr[smallest] > arr[left] )
            smallest = left;
        if(right < n && arr[smallest] > arr[right] )
            smallest = right;
        
        //The heap property is violated or not
        if(smallest != root){
            swap(&arr[smallest] , &arr[root]);

            //Now check the sub tree of swapped number follows heap property
            Heapify(arr , n , smallest);
        }

        return;
    }
    void createHeap(int n){
        arr = new int[n];
        heap_size = 0;
        capacity = n;
    }
    //Build a Heap from the array 
    void buildHeap( int val[] , int n){
        if(capacity != 0)
        {
            cout<<"Heap is already present!"<<endl;
            return;
        }
        arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = val[i];
        }
        capacity = n;
        heap_size = n;

        //Heapify the new array
        // The leaf nodes are already satisfy the minheap property
        //  i.e They are lesser than the child because they have no child.

        //So we can start from the last non leaf node.The last non leaf node is nothing but the parent of the last leaf node
        // parent (n-1) = (n-1) -1 /2
        //              = (n-2) / 2
        int start = (n-2)/2;
        cout<<"Start index : "<<start<<endl;
        //So i will check the heap property from start index to all the way to the top
        for(int i = start ; i>=0 ; i--){
            Heapify(arr , n , i);
        }

    }

    void printHeap(){
        for(int i=0;i<heap_size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    //Delete the arr pointer memeory on deleting the obj of min heap
    ~Minheap(){
        delete[] arr;
    }
};

int main() {
    int val[] = {1,5,6,8,9,7,3};
    int n = sizeof(val)/sizeof(val[0]);

    Minheap heap;
    // heap.buildHeap(val , n);
    heap.createHeap(5);
    heap.printHeap();
    heap.insert(5);
    heap.insert(3);
    heap.insert(6);
    heap.insert(7);
    heap.printHeap();
    heap.deleteKey(1);
    // cout<<x<<endl;
    heap.printHeap();

    return 0;
}