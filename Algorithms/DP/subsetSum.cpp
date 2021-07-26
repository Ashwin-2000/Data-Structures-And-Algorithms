#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int cansubArraysum(vector<int> arr , int n , int target){
    //Base cases 
     
    if(n==0 && target > 0){
        return 0;
    }
   if(target == 0){
        return 1;
    }
    cout<<"arr[i] : "<<arr[n-1]<<" target : "<<target<<endl;
    //Target sum must be greater than or equal to element
    if(target >= arr[n-1]){
        //Include in subet
        int include = cansubArraysum(arr , n-1 , target-arr[n-1] );
        cout<<arr[n-1]<<" Include : "<<include<<"for "<<target<<endl;
        //Not include in the subset
        int exclude  = cansubArraysum(arr , n-1 , target);
        
        if(include||exclude){
            cout<<arr[n-1]<<" can produce "<<target<<endl;
        }
        return (include || exclude);
    } 
    //Target sum is lesser than element
    else {
        //Exclude the element
        return cansubArraysum(arr , n-1 , target);
    }

}

int cansubsetSum(vector<int> arr , int n , int target){

    vector<vector<int> > DP(n+1 , vector<int>(target+1 , 0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++){
            //Base case : Target 0 empty subset exists
            if(j==0){
                DP[i][j] = 1;
            }
            //Base case : No array elements
            else if (i==0){
                DP[i][j] = 0;
            }
            //Element is less than or equal to target
            else if( j >= arr[i-1]){
                //Include
                bool include = DP[i-1][j-arr[i-1]]; 
                //Exclude
                bool exclude = DP[i-1][j];

                DP[i][j] = (include || exclude); 
            }
            //Element is greater than target
            else{
                DP[i][j]= DP[i-1][j];
            }
        }
    }

    for(auto ar : DP){
        for(auto i : ar){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return DP[n][target];
}

int countsubsetSum(vector<int> arr, int n , int target){
    vector<int> count(target+1 , 0);

    count[0] = 1;

    for(int i=1;i<=target;i++){
        for(int j=0;j<n;j++){
            if(arr[j] <= i){
                count[i] += count[ i-arr[j] ];
            }
        }
    }

    for(int x : count){
        cout<<x<<endl;
    }
    cout<<endl;
    
    return count[target];
}

int main(){
    vector<int> arr={ 3,4,5,2 };
    int n = arr.size();
    int target = 6;

    cout<<cansubsetSum(arr ,n , target);
    
    return 0;
}
//Positive set of numbers
//Can or not 