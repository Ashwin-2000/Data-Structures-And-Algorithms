#include<iostream>
#include<queue>

using namespace std;

//Nodes in the tree
struct Node {
    int data;
    Node *left;
    Node *right;

    Node ( int val ){
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
    Node *root=NULL;

    public : 
    Node* searchBST(Node *root , int key){
        //BASE CASE : Node is NULL
        if(root==NULL)
            return NULL;
        
        //If the key is found return the node
        if (root->data == key){
            return root;
        }

        //If node is not found and the node is greater than the key
        //Search for left sub tree 
        if(root->data > key)
            return searchBST(root->left , key);
        //If the node is lesser than the key , search for right sub tree
        else    
            return searchBST(root->right , key);

    }

    //Inserting at BST is always at the leaf node.
    void insertBST(int val){

        if(root == NULL) {   
        Node *newnode = new Node(val);
            cout<<"ROot insert : "<<val<<endl;
            root = newnode;
            return;
        }

        Node *temp = root;

        while(temp){
            //If the node val is greater than the new value
            if(temp->data >= val ){
                //If there is no left child insert it
                cout<<"left iter"<<endl;
                if(temp->left == NULL){
                    Node *newnode = new Node(val);
                    cout<<"LEft insert : "<<val<<endl;
                    temp->left=newnode;
                    break;
                }
                //If there is left child , iterate to it
                temp = temp->left;
            }
            else if(temp->data < val)
            {
                cout<<"right iter"<<endl;

                if(temp->right==NULL){
        Node *newnode = new Node(val);

                    cout<<"Right insert : "<<val<<endl;
                    temp->right = newnode;
                    break;
                }
                temp = temp->right;
            }
        }   
    }

    void deleteBST(int key ){
        if(root == NULL)
            return;
        deleteUtil(root , key);
    }

    Node * deleteUtil(Node *root , int key) {
        if(root == NULL)
            return NULL;
        
        //If node is greater than the key 
        if(root->data > key)
            root->left = deleteUtil(root->left,key);
        //If node is lesser than the key
        if(root->data < key)
            root->right = deleteUtil(root->right,key);
        //If the node is the key
        if(root->data == key){
            //root with no child
            if( !root->left && !root->right){
                root = NULL;
            }
            
            //root with only one child - either left or right
            if( !root->left || !root->right){
                Node *temp = (root->left==NULL) ? root->right : root->left;
                delete(root);
                return temp;
            }

            //root with two child
            //we can swap the node either with smallest element in the right sub tree
            //or greatest element in left subtree
            else{
                //Smallest in right subtree
                Node *temp = root;
                while(temp && temp->left)
                    temp=temp->left;
                
                //Swap the key with the min at right subtree
                root->data = temp->data;
                temp->data = key;

                //Now delete the key
                root->right = deleteUtil(root->right , key);
            }
        }

        return root;
        
    }

    void BFS(){
        if(root == NULL)
            return;
        BFSutil(root);
    }
    //Printing the BST
    void BFSutil(Node* root){
        if(root == NULL)
            return;

        queue<Node *> q;
        q.push(root);
        while( !q.empty() ){
            Node *curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            if(curr->left)
                q.push(curr->left);
            if(curr->right)
                q.push(curr->right);
        }       
    
    }

    
};



int main() {
    BST tree;
    tree.insertBST(13);
    tree.insertBST(3);
    tree.insertBST(4);
    tree.insertBST(12);
    tree.insertBST(14);
    tree.insertBST(10);
    tree.insertBST(5);

    tree.BFS();
    return 0;
}