#include<iostream>

using namespace std;

void selectionSort(int *arr , int N){
   cout<<sizeof(int)<<" "<<sizeof(arr)<<endl;
    for(int i=0;i<N;i++){
        int idx = i;
        int min = arr[i];
        for(int j=i;j<N;j++){
            if(arr[j] < min)
               { 
                   idx = j;
                   min=arr[j];
               }
        }
        arr[idx] = arr[i];
        arr[i] = min;
    }
}
int main(){
    int arr[] = {8, 6, 4, 5, 3, 7, 2, 4, 1, 9};
    int x = 10;
    // cout << "arr : " << sizeof(arr) << " arr[0]" << sizeof(arr[0]) << endl;
    int N = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr , N);
    for(int x : arr){
        cout<<x<<" ";
    }
    return 0;
}