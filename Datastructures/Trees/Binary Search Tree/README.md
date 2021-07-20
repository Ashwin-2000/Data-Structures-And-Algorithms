# BINARY SEARCH TREE - BST
-   Left subtree  => nodes lesser than key node.
-   Right subtree => nodes greater than key node.
-   Left and Right subtree eac must be BST

BASIC OPERATION : 
| OPERATIONS| ANALYSIS |
|-----------|----------|
| Searching |  O(log(n))|  
| Inserting | O(n) |
| Deletion  | O(n) |

## Searching
- We check that the key is lesser than the node , if so we search the value in the left subtree
- We check that the key is greater than the node , if so we search the value in the right of the subtree

## Insertion
- NOTE : We insert the value at the leaf node only.
- We check the new value with node and if it is lesser than the node we iterate through the left subtree
- We check the new value with node and if it is greater we iterate through right subtree
- If we reach the leaf node we insert the node

## Deletion 
<pre>
 if root is null
    return

if the node is greater than the node to be deleted
    node->left = delete(root->left , key) //iterate through left subtree
if the node is lesser than the node to be deleted
    node->right = delete(root->right , key) //iterate through right subtree

if node to be deleted is found 
    if it has no child  
        delete the node
        return NULL
    if the node has only one child
        delete the node
        return the child
    if there are more than one childeren
        find the min element in right sub tree or find max element in left sub tree
        now swap the value of least element and the node to be deleted
        call the delete()
//It is important because if the node to be deleted is not found then we should return the current node to make sure tree remains same
return root
</pre>
