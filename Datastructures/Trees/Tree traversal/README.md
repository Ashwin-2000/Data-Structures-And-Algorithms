# TREE TRAVERSAL

Tree traversal is travelling through all nodes in the tree.Searching a node is different from traversal.On searching we would stop at key node,In traversal we visit every nodes.These traversal can be applied to all trees.
NOTE : These traversal are used to implement DFS.
There are three ways we can traverse through the tree :

| Travesal            | Path                    |
| ------------------- | ----------------------- |
| Preorder traversal  | _root_ -> left -> right |
| Inorder traversal   | left -> _root_ -> right |
| Postorder traversal | left -> right -> _root_ |

> The traverse methods differ due to the _**order of the root**_

## Preorder Traversal

- In preorder traversal we visit the root first , then the leftsub tree and the right subtree
- Root is visited before the subtree,so Pre-order.
- It is used to create the copy of the tree.
- It is also used to get prefix expression on of an expression tree.

<pre>

    [A]
   /   \
 [B]   [C]

 Preorder Traversal : A->B->C
</pre>

## Inorder Traversal

- In inorder traversal we visit the left subtree first , then the root and the right subtree
- In Binary Search Tree, inorder traversal gives nodes in ascending order.
- To get descending order in BST , follow : right -> root -> left.

<pre>

    [A]
   /   \
 [B]   [C]

 Inorder Traversal : B->A->C
</pre>

## PostOrder Traversal

- In postorder traversal we visit the left subtree first , then the the right subtree and root
- It is usefull in deleting the tree.[ We check the sub tree first , and then move to the root ].
- It is useful in getting the postfix expression of the expression tree

<pre>

    [A]
   /   \
 [B]   [C]

 Postorder Traversal : B->C->A
</pre>

### CODE

- [Preorder](./Preorder/preorder.cpp)
- [Inorder](./Inorder/inorder.cpp)
- [Preorder](./Postorder/postorder.cpp)
