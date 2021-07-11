#include<iostream>
#include<queue>

using namespace std;


/*
We are going to implement the tree traversal in Binary Tree.
                [A]
                / \
               /   \
            [B]     [C]
            / \     /  \
           /   \   /    \
          [D]  [E][F]   [G]
          / \           /
         /   \         /
        [H]  [I]      [J]  
    
INORDER : H D I B E A F C J G 
 */

struct Node {
    char data;
    Node *left;
    Node *right;

    Node(char val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


void BFS(Node *root){
    if (root==NULL)
        return;
    queue<Node *> q;
    q.push(root);

    while(!q.empty()){
        Node *curr = q.front();
        cout << curr->data << " ";
        q.pop();
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
}

int main(){
    //Construct the binary tree show above
    struct Node *root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');

    root->left->left = new Node('D');
    root->left->right = new Node('E');

    root->right->left = new Node('F');
    root->right->right = new Node('G');

    root->left->left->left = new Node('H');
    root->left->left->right = new Node('I');

    root->right->right->left = new Node('J');

    //Pre Order Traversal
    cout << "Recur Preorder traversal" << endl;
    BFS(root);
    cout << endl;
    return 0;
}