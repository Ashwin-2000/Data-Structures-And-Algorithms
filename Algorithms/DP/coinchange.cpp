#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int coinChangerecurr(vector<int> coins , int n , int total){

    //If total mat is zero , 
    if(total == 0){
        return 0;
    }
    int mincoin=INT_MAX;
    for(int i=0;i<n;i++){
        //Of all the denomination,what is smallest number of coin to make total
        if(coins[i] <= total){
            int coin = coinChangerecurr(coins , n  , total-coins[i]);
            cout<<"Total : "<<total-coins[i]<<" from : "<<coins[i]<<" is "<<coin<<endl;
            //Min is stored here
            if(coin!=INT_MAX && coin+1 < mincoin ){
                mincoin = 1+coin;
            } 
        }
    }

    return mincoin;
    
}

int coinChange( vector<int> coins , int n , int total){

    // vector< vector<int> >  DP( n+1 , vector<int> (total+1) );
int DP[n+1][total+1];
    //Basecase , If there is no amt , then no coin
    // for(int i=0;i<=n;i++){
    //     DP[i][0] = 0;
    // }

    //If there is no coin exist , then infinite ant of coins required
    //Basically , we need to select a min value , so if we cant put 0 , because
    //it is also part of solution , if we put -1 then it is min than 0 , then we will take it.
    //SO we put INT_MAX so that we select min value.
    // for(int i=1;i<=total;i++){
    //     DP[0][i]=INT_MAX;
    // }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++){
            if(j==0)
                DP[i][j] = 0;
            else if (i==0)
                DP[i][j] = INT_MAX;
            else if(coins[i-1] > j){
                DP[i][j] = DP[i-1][j];
            } else {
                cout<<coins[i-1] <<" to make " <<j<<" i-1 j "<<DP[i-1][j]<<"i j-coins[i] : "<<DP[i][j-coins[i-1]]<<endl;
            
                DP[i][j] = min(1+DP[i][j-coins[i-1]] , DP[i-1][j]);

            }
        }
    }
    cout<<endl;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++){
            cout<<DP[i][j]<<" ";
        }
        cout<<endl;
    }
    return DP[n][total];
}




int main() {
    int n , total;
    n=3;
    total = 11;
    // cin>>n;

    //Coins of denomination
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    // for(int &x : coins){
    //     cin>>x;
    // }

    //KNAPSACK
    //1. Capacity is total.It must be full else it is not possible.
    //2. I can use items(coins) any number of times.
    //3. Profit/cost is not given.
    cout<<"Min coins : "<<coinChange(coins , n , total)<<endl;


    return 0;
}