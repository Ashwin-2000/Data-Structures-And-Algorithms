#include<iostream>

using namespace std;

int partition(int arr[] , int  l , int h){
    cout<<"HErer";
    //We consider first element as pivot element
    int pivot = arr[l];

    int i = l+1 , j= h ;
    while(j > i){
        //Move the i to the element greater than pivot
        while(arr[i]<pivot && i<j)  i++;
        //Move the j to the element lesser than pivot
        while(arr[j]>pivot && j>i) j--;
        if(i>j)
            break;
        //Swap the ith with jth elemnt
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    arr[l] = arr[j];
    arr[j] = pivot;
    cout<<"Pivot : "<<pivot<<" j : "<<j<<endl;
    return j ;

}

void quicksort(int arr[] , int l , int h){
    if( l>= h )
        return ; 

    int mid = partition(arr , l , h);

    /*
        After partition the elements to the right of mid are less then the mid
        The elements to the left of mid are greater then mid
    */
    quicksort(arr , l , mid-1);
    quicksort(arr , mid+1 , h);

}

int main(){
    int arr[] = { 6,4,3,3,5,2,7};
    int N = sizeof(arr) / sizeof( arr[0]);
    quicksort(arr, 0 , N-1);
    for(int x : arr)
        cout<<x<<" ";
    return 0;
}