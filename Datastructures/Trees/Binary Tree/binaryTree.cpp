#include<iostream>
#include<queue>
#include<stack>
#include<unordered_map>

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

void levelOrderTraversal ( Node *root){
    if(root == NULL)
        return;
    
    queue<Node *> q;

    //Insert the root node to queue
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        //Insert the left and right child if any
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout<<endl;

}

//For maximum problem having keyword "reversal" can be solved easily by stack
void reverseLevelOrderTraversal (Node *root ){
    if(root==NULL)
        return;
    queue<Node *> q;

    stack<int>res;

    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        //We push the val instead of printing it
        res.push(curr->data);
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }

    //Print the stack to show the reverse of level order traversal
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
    cout<<endl;

}

//DFS can be modified to find the height of the tree
int heightOftree(Node *root){
    //If there is 0 node in tree return
    if(root == NULL)
        return 0;
    //It is height of the root node
    int curnode = 1;
    //Height of left subtree
    int left = curnode + heightOftree(root->left);
    //Height of right subtree
    int right = curnode + heightOftree(root->right);

    //Max of height of left and right subtree is the height of tree
    return (left > right) ? left : right;
}

    /*
    IMPORTANT FACT : The diameter i.e longest path between two leaf nodes need not to be pass through ROOT os the whole tree.

        10
     /      \
    20       30
            /  \
          60    70          In this tree the diameter is 6.
           /     \          Diameter path : 80 -> 60 -> 30 -> 70 -> 90 -> 100
          80      90        It doesnt pass through the root of the tree.    
                    \
                    100

    So, we need to calculate height of the leftsubtree and height of the right subtree for every node and add them to
    get the diameter at current node.Max of diameter is the diameter of whole

 */
int diameterofTree(Node *root){
   if(root == NULL)
    return 0;

    //Find the hegiht of left subtree and right subtree
    int leftheight = heightOftree(root->left);
    int rightheight = heightOftree(root->right);

    //Add those two to get the diameter of subtree with current node as root
    int currdia = leftheight + rightheight;

    //Diameter of left subtree
    int leftdia = diameterofTree(root->left);
    //Diameter of right subtree
    int rightdia = diameterofTree(root->right);

    //Now maximum of the three would be the diameter of tree
    return max( currdia , max(leftdia,rightdia));
   
}

/*
    If it is balanced tree the answer is simple, 
        use stack and traverse to the left sub tree until NULL - you would get the Left side of the top view
        use stack and traverse to the right sub tree until NULL - reverse the stack and you will get the left side.

    But the above solution will not work for Unbalanced tree : 

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

*/

void topViewOftree(Node *root){
    if(root == NULL)
        return NULL;
    
    
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
    cout<<"Level Order Traversal : ";
    levelOrderTraversal(head);
    cout<<"Reverse Level Order Traversal : ";
    reverseLevelOrderTraversal(head);
    cout<<"Height of the tree : ";
    cout<<heightOftree(head)<<endl;
    cout<<"Diameter of the tree : ";
    cout<<diameterofTree(head)<<endl;
    cout<<"Top view of the tree : ";
    // topViewOfTree(head);
    cout<<"Left view of the tree : ";
    leftViewOfTree(head);
    cout<<"Right view of the tree : ";
    rightViewOfTree(head);

}