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
 */

//Node in the tree
struct Node {
    
    //Left child reference
    Node *left;
    char data;
    //Right child reference
    Node *right;

    Node(char val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void recurrPostorder(Node *root){
    if(root == NULL)
        return;
    recurrPostorder(root->left);
    recurrPostorder(root->right);
    cout << root->data << " ";
}

void iterPostOrder(Node *root){
    //Stack for mimicing recurrsion in preorder
    stack<Node *> s;
    s.push(root);

    //Stack to print the preorder
    stack<char> out;

    while(!s.empty()){
        Node *curr = s.top();
        s.pop();

        //Add the node to the output stack
        out.push(curr->data);

        /* 
        In here , Left sub tree to be added first and then right subtree unlike preorder.
        Because, While reversing the stack we need left at first rather than right [LIFO strategy]
        */
        if(curr->left)
            s.push(curr->left);
        if(curr->right)
            s.push(curr->right);
    }

    //Now we reversed the stack
     while(!out.empty()){
            cout << out.top() <<" ";
            out.pop();
        }
}

void iterPostOrder_with_one_stack(Node *root){

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
    cout << "Recursive Post order traversal" << endl;
    recurrPostorder(root);
    cout << endl;

    //Inorder Traversal
    cout << "Iterative Post order Traversal" << endl;
    iterPostOrder(root);
    cout << endl;
}