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

PREORDER : A B D H I E C F G J
 */
struct Node {
    char data;
    Node *left;
    Node *right;

    Node (char val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void recurrPreorder(Node *root){
    if(root==NULL)
        return;
    cout << root->data << " ";
    recurrPreorder(root->left);
    recurrPreorder(root->right);
}

void iterPreorder(Node *root){
    stack<Node *> s;
    Node *curr = root;
    s.push(root);

    while(!s.empty()){
        curr = s.top();
        s.pop();
        if(curr){
        cout << curr->data << " ";
        s.push(curr->right);
        s.push(curr->left);
        }
    }
}

int main() {
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
    recurrPreorder(root);
    cout << endl;

    //Inorder Traversal
    cout << "Iter Preorder Traversal" << endl;
    iterPreorder(root);
    cout << endl;
    return 0;
}