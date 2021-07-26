#include<iostream>

using namespace std;

void printArray(int[],int);
//Swap two variables
// void swap(int &a , int &b ){
//     int temp = a;
//     a = b;
//     b = temp;
// }

//Validates the property of heap and corrects it
void heapify(int arr[] , int n , int index){

    int left = (2*index)+1;
    int right = (2*index)+2;

    int largest = index;

    if( left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if( right < n && arr[right] > arr[largest]){
        largest  = right;
    }

    //If heap property is violated
    if(largest != index){
        //Correct the heap Property
        swap(arr[index] , arr[largest]);
        heapify(arr, n , largest);
    }

}

void heapSort(int arr[] , int n){
    
    //Last non-leaf node
    int start =  n/2-1 ;

    //Build the heap
    for(int i=start; i >=0 ; i-- ){
        heapify(arr , n , i);
    //   printArray(arr , n);

    }
    printArray(arr , n);

    // Traverse the arry from last
    // 1. Swap my root node with last node 
    // 2. I decrease the size by 1
    // 3. Construct the heap

    for(int i=n-1 ; i>0 ; i--){
        swap(arr[0],arr[i]);
      printArray(arr , n);

        heapify(arr, i , 0);
    }
}

//Prints the array
void printArray(int arr[] , int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {5,3,6,4,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr , n);
    heapSort(arr , n);
    printArray(arr , n);
    return 0;
}