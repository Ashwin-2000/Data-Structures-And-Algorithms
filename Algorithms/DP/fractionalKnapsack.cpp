#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

//Comparator function to sort the vec of pairs using second value
bool SortbySecond( pair<int,float> &a , pair<int,float> &b){
    return a.second > b.second;
} 

//Profit per unit of item
vector< pair<int,float> >  perUnitProfit(vector<int> wt , vector<int> price){
    int n = wt.size();
    vector< pair<int,float> > wp(n);
    cout<<n<<endl;
    float perUnit ;
    for(int i=0;i<n;i++){
        // cout<<i<<endl;
        perUnit = (double)price[i] / (double)wt[i];
        wp[i] = { wt[i] , perUnit} ; 
    } 
    //Sort by profit values
    sort( wp.begin() , wp.end() , SortbySecond);
    return wp;
}

//Kanpsack Greedy implementation
int knapsack( vector< pair<int ,float> > profit, int capacity ){
    int n = profit.size() , max=0;
    cout<<n<<endl;
    for(int i=0;i<n;i++){
        int wt = profit[i].first;
        float perProfit = profit[i].second;
        cout<<"wt : "<<wt<<" pr : "<<perProfit<<" cap : "<<capacity<<" max : "<<max<<endl;
        //If bag is full end the loop
        if(capacity==0)
            break;
        //If the capacity to hold is less than the total weight of item
        if( capacity < wt ){
            //Fill all the remaining capacity of bag to full.
            int fill = capacity;
            max += fill*perProfit;
            capacity = 0;
        //If capacity is grt than or equal to weight
        } else {
            //Fill all the weight n=in bag
            int fill = wt;
            max += fill*perProfit;
            capacity -= wt;
        }

    }

    return max;
    
    

}

int main(){
    int n,capacity;
    n = 3;
    capacity = 50;
    // cin>>n>>capacity;
    
    //Weights of items
    vector<int> wt;
    cout<<n<<endl;
    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);
    for(int &i : wt){
        cout<<i;
    }
    

    //Profit of items
    vector<int> price;
    price.push_back(60);
    price.push_back(100);
    price.push_back(120);
    // for(int &i : price){
    //     cin>>i;
    // }
    
    
   cout<<wt.size()<<endl;
    //Find the weight per unit cost
    vector< pair<int ,float> > profitPerUnit = perUnitProfit(wt , price);
   
    //Fill the knapsack GREEDY METHOD
    cout<<"Max Profit is : "<<knapsack(profitPerUnit , capacity);


    

    return 0;
}