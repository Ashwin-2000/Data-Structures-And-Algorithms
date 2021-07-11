#include<iostream>
#include<stack>

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

void recurrInorder( Node *root){
    if( root == NULL)
        return;

    recurrInorder(root->left);
    cout << root->data << " ";
    recurrInorder(root->right);
}

void iterInorder( Node *root){
    if(root == NULL)
        return;
    stack<Node *> s;
   
    Node *curr = root;
    while( !s.empty() || curr != NULL ){
        //Left most of the curr node
        while( curr!=NULL){
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        cout << curr->data << " ";
        s.pop();
        curr = curr->right;
    }
}


int main()
{
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

    cout << "Inorder Recursion : " << endl;
    recurrInorder(root);
    cout << "\nInorder Iteration : " << endl;
    iterInorder(root);

    //Inorder iteration without stack
    
    return 0;
}