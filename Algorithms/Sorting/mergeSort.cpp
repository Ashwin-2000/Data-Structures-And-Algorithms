#include<iostream>

using namespace std;

void merger(int arr[] , int l , int mid , int h){
    int lsize = mid-l+1 , rsize = h-mid;
    int  L[lsize] , R[rsize];
   
   //Create Left array
    for(int i=0 ; i<lsize ; i++){
        L[i] = arr[l+i];
    }

    //Create Right Array
    for(int i=0;i<rsize;i++){
        R[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int idx = l;
    while( i < lsize && j<rsize){
        if( L[i] <= R[j] ){
            arr[idx++] = L[i++];
        }
        else{
            arr[idx++] = R[j++];
        }
    }

    //Fill the remaining elements in L or R array , if any
    while( i<lsize)
        arr[idx++]=L[i++];
    while( j<rsize )
        arr[idx++]=R[j++];

}

void mergeSort( int arr[] , int l , int h ){
    if( l >= h)
        return;
    
    int m = (l+h)/2;
    cout<<"l : "<<l<<" m : "<<m<<" h : "<<h<<endl;
    mergeSort( arr , l , m);
    mergeSort( arr , m+1 , h);
    merger( arr , l , m , h);
    for(int i=l ; i<=h ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;

}



int main() {
    int arr[] = { 6 , 5 , 4 , 9  ,8 , 2 , 1};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr ,0 ,n-1);
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}