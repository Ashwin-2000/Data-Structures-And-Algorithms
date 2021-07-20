#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>

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


/* 
     A  B   C   D  E   F
     |  |   |   |  |   | 
     |  |   1   |  |   |
     |  | / |  \|  |   |
     |  2   |   3  |   |
     | /|\  |  /|\ |   |
     4  |  5|6  |  7   |
     |  |   |   | /| \ |
     |  |   |   8  |   9 
     |  |   |   |  |   |
    -2 -1   0   1   2   3  -> horizontal distance
              
The vertical order traversal will be like:
A : 4
B : 2
C : 1 5 6
D : 3 8
E : 7
F : 9

We can implement vertical order by keeping track of horizontal distance
*/
void verticalOrderUtility(Node *root , int level , map< int , vector<int> > &hash);


void verticalOrderTraversal( Node *head){
    if(head == NULL)
        return;
    
    //We Hash the horizontal distance from root with node
    map <int , vector<int> > hash;
    verticalOrderUtility( head , 0 , hash);

    map< int , vector<int> > :: iterator itr;
    for( itr = hash.begin() ; itr != hash.end() ; itr++){
        cout<< itr->first << " : ";
        for(int data : itr->second)
            cout<< data <<" ";
        cout<<endl;
    }

}

void verticalOrderUtility(Node *root , int horizontalDistance , map< int , vector<int> > &hash){
    if(root==NULL)
        return;
    
    if(hash.find( horizontalDistance ) == hash.end() ){
        vector<int> vec{ root->data };
        hash.insert ( make_pair ( horizontalDistance , vec ));
    }
    else {
        map< int , vector<int> > :: iterator itr;
        itr = hash.find(horizontalDistance);
        itr->second.push_back(root->data);
    }

    //We decrease the horizontal distance by one as we go to left of root
    verticalOrderUtility(root->left , horizontalDistance-1 , hash);

    //We increase the forizontal distance by one as we go to right of root
    verticalOrderUtility(root->right , horizontalDistance+1 , hash);

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
    cout<<"Vertical Order Traversal of the tree : "<<endl;
    verticalOrderTraversal(head);
    cout<<"Height of the tree : ";
    cout<<heightOftree(head)<<endl;
    cout<<"Diameter of the tree : ";
    cout<<diameterofTree(head)<<endl;


}