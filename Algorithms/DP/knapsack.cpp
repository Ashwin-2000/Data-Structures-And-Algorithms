#include<iostream>
#include<vector>
using namespace std;


int knapSackrecurr(vector<int> wt, vector<int> pr , int n , int W){
    
    //Bag is filled or No item to fill
    if(W == 0 || n==0)
        return 0;
    cout<<"wt : "<<wt[n-1]<<" pr : "<<pr[n-1]<<" n : "<<n-1<<" W : "<<W<<endl;
    if(W >= wt[n-1]){
        //Include in Knapsack
        int include = pr[n-1] + knapSackrecurr(wt , pr , n-1 , W-wt[n-1]) ;
        //Not include it in Knapsack
        int exclude = knapSackrecurr(wt , pr , n-1 , W);
        //Return Maximum profit
        return (include > exclude ) ? include : exclude;
    } else {
        //I cant include it in my bag
        return knapSackrecurr(wt , pr , n-1 , W);
    }

}

int knapSack(vector<int> wt , vector<int> pr , int n , int W){

    // int DP[n+1][W+1];
    vector< vector<int> > DP ( n+1 , vector<int>(W+1 , 0));

    //BASE CASE
    //If W is Zero nothing to fill
    for(int i=0;i<=n;i++){
        DP[i][0] = 0;
    }
    //If no items there , the profit is zero
    for(int i=0;i<=W;i++){
        DP[0][i] = 0;
    }

    for(int i=1 ; i<=n ; i++){
        for(int j=1; j<=W ; j++){

            //Capacity must be greater than wt if item
            if(j >= wt[i]){
                //Include
                int include = pr[i] + DP[i][j-wt[i]]; 
                //Exclude
                int exclude = DP[i-1][j];

                DP[i][j] = max(include, exclude);
            }
            //Capacity is less than weight
            else {
                DP[i][j] = DP[i-1][j];
            }
            
        }
    }

    return DP[n][W];
    

}

int main() {
    int n = 3;
    int capacity = 50;

    //Weights of items
    vector<int> wt;
    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);

    //Profit of items
    vector<int> p;
    p.push_back(60);
    p.push_back(100);
    p.push_back(120);

    //KnapSack
    cout<< knapSackrecurr( wt , p , n , capacity);
    cout<< knapSack( wt , p , n , capacity);

    return 0;
}