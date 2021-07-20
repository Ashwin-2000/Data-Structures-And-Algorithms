#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<utility> // Pair is in utility lib

using namespace std;

//Nodes in the tree
struct Node {
    int data;
    Node *left;
    Node *right;

    Node (int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


/*

        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
    In this tree the TOP VIEW : 2 1 3 6 .
    So we need to traverse vertically.
    Using BFS : 
        Traverse level by level and find the horizontal distance from the root.
            if the horizontal distance is met for the first time it is the top view of the tree
    Using DFS : 
        Here we keep track of the level and hosizontal distance for each node from the root node.
            if the horizontal distance is met for first time OR the level we are at is less than the node mapped at that horizontal distance
            Add it to the map

*/
void topViewUtility(Node *root , int level , int horizontalDistance , map<int , pair<int , int> >&hash){
    if(root == NULL)
        return ;
    //If we are exploring the horizontal distance for the firat time or the level at which the horizontal distance was met
    //is larger than the current level at same horizontal distance,then insert it to map
    if( hash.find(horizontalDistance) == hash.end() || level <  hash[horizontalDistance].first){
        hash[horizontalDistance] = make_pair(level , root->data);
    }

    //level increases as we go in depth

    //Horizontal distance decreases on moving to the left subtree
    topViewUtility(root->left , level+1 , horizontalDistance-1 , hash);
    //Horizontal Distance increases on moving to the right of the subtree
    topViewUtility(root->right , level+1 , horizontalDistance+1 , hash);

}



void topViewOftree(Node *root ){
    if(root == NULL )
        return;
    map< int , pair<int,int>  > hash;
    topViewUtility( root , 0 , 0 , hash);
    map< int , pair<int , int >> :: iterator itr;
    for(itr = hash.begin() ; itr != hash.end() ; itr++ ){
        cout<<itr->second.second<<" ";
    }
        cout<<endl;

}

/*

It is similar to the top view of the tree,But instead of checking the current level is lesser
than the already visited horizontal level, we can check the level is greater than the already
visited horizontal level.

*/
void bottomViewUtility(Node *root , int horizontalDist , int level , map< int , pair<int, int> > &hash){
    if(root == NULL)
        return;
    
    if(hash.find(horizontalDist) == hash.end() || level > hash[horizontalDist].first){
        hash[horizontalDist] = { level , root->data };
    }

    bottomViewUtility( root->left , horizontalDist-1 , level+1 , hash);
    bottomViewUtility( root->right , horizontalDist+1 , level+1 , hash);

}

void bottomViewOftree( Node *root){
    if(root == NULL)
        return;
    
    map< int , pair<int,int> > hash;
    bottomViewUtility( root , 0 , 0 , hash);
    for(auto itr = hash.begin() ; itr!=hash.end() ; itr++){
        cout<< itr->second.second <<" ";
    }
    cout<<endl;

}





/*
    LEFT VIEW is nothing but first node in each level
*/
void leftViewOfTree(Node *root){
    if(root==NULL)
        return;
    
    queue<Node *> q;

    q.push(root);

    while(!q.empty()){
        //We calculate the number of nodes at each level
        int n = q.size();

        for(int i=0;i<n;i++){
            Node *curr = q.front();
            q.pop();
            //If the curr node is first node in current level , then we print it
            if(i==0)
                cout<<curr->data<<" ";
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
    cout<<endl;
}

// RIGHT VIEW : Last nodes at each level form the right end of the tree
void rightViewOfTree(Node *root){
    if(root==NULL)
        return;
    
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++){
            Node *curr = q.front();
            q.pop();
            //If the curr node is the last node in the level then it is print it.
            if(i==n-1)
                cout<<curr->data<<" ";
            
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout<<endl;
    }
}

/*
The Binary tree is : 
        10
     /      \
    20       30
  /   \     /  \
 40   50   60   70
                 \
                 80

*/
int main(){
    Node *head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);
    head->right->right->right = new Node(80);
  

    cout<<"Top view of the tree : "<<endl;
    topViewOftree(head);    
    cout<<"Bottom view of the tree : "<<endl;
    bottomViewOftree(head);
    cout<<"Left view of the tree : ";
    leftViewOfTree(head);
    cout<<"Right view of the tree : ";
    rightViewOfTree(head);

}