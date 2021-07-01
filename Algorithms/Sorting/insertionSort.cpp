#include<iostream>

using namespace std;

void insertionSort(int arr[] ,int N){

    int j;//To avoid swapping

    //We consider first element @ 0th index is sorted
    for (int i = 1; i < N;i++){
        //We need to insert this element
        int key = arr[i];

        //Initailzation : To insert in left part so we start from i to 0 
        //Condition     : The element in the left is already sorted so, we can traverse until key is greater than element in left
        //                because it is sorted.So we dont need to traverse till the end unnesserily
       
        //          *we are checking arr[j-1] (i.e) Prev ele to the key intialy because we need not to chnage the key if it is already
        //           at right place 
        for (j = i; j > 0 && key < arr[j - 1];j--){
            //Moving each element to the right to avoid swapping at every stage
            arr[j] = arr[j - 1];
        }
        //Now the elements greater than key are moved towards right and  j is at the right spot
        arr[j] = key;
        cout << "@ i = " << i << endl;
        for (int k = 0; k < N;k++)
            cout << arr[k] << " ";
        cout << endl;
    }
}



int main(){

    int arr[] = {9, 5, 7, 3, 6, 2, 8, 2};
    int N = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, N);
    for (int i = 0; i < N;i++){
        cout << arr[i] << " ";
    }

        return 0;
}