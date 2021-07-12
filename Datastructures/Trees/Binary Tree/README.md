# BINARY TREES

Binary Trees have atmost two children (i.e) a parent node can have one or two or three children.
The childs in Binary tree are named as left child and right child.

## Properties of binary trees

Assumptions : heights starts with 0,level starts with 0.

- The maximum number of nodes at depth 'l' of Binary tree is 2^l.
- The maximum number of nodes in a binary tree of heignt 'h' is 2^(h+1) - 1
- In a Binary tree with N nodes , minimum possible height or minimum number of levels = |Log(N+1)| - 1

## Representation of the trees

Binary Trees can be represented by two ways :

- Array representaion
- Linked List Representation

---

## 1. Array Representation

Node values are stored in Arrays

- if root is stored at arr[0]

  - Let index of parent node = p
  - Then index of left child = (2\*p)+1
  - Then index of right child = (2\*p)+2

- if root is stored at arr[1]
  - Let index of parent node = p
  - Then index of left child = (2\*p)
  - Then index of right child = (2\*p)+1

> NOTE : On accessing the left and right child , check whether the index within the range.

### CODE

<pre>
Lets consider the following Binary tree of 6 nodes.
Lets mark NULL nodes as -99
                  [1]                      [1]
                  / \                      / \
                 /   \                    /   \
                [2]  [3]               [2]     [3]
                / \          ==>       / \      / \
               /   \                  /   \    /   \
              [4]  [5]              [4]   [5] -99  -99
              /                     / \    /\
             /                     /   \  /  \
            [6]                 [6]  -99 -99  -99

</pre>

```cpp
  int num_of_node = 12;
  //The Array Representation of given tree [ indexed as 0 - N-1 ]
  char tree[ num_of _node ] = [ 1 , 2 , 3 , 4 , 5 , -99 , -99 , 6 ,-99 , -99 , -99 , -99]

  //Left child of any index
  int leftchild( int index ){

    //Check the index is within the range
    if( index >= 0 && index < num_of_node ){
        return arr [ (2*index + 1) ];
    }
    std :: cout<<"Invalid Index"<<endl;
    return -1;

  }

    //Right child of any index
  int rightchild( int index ){

    //Check the index is within the range
    if( index >= 0 && index < num_of_node ){
        return arr [ (2*index + 2) ];
    }
    std :: cout<<"Invalid Index"<<endl;
    return -1;

  }

```

## 2. Linked List Representation

In Linked list representation , the Node can be class/struct and they have two self-referencing pointers _left_ and _right_ for left and right child.

```cpp
struct Node {

    //left child
    struct Node* left;
    int data;
    //right child
    struct Node* right;

};
```

---

## Types of Binary trees

There are four types of Binary Trees

- FULL Binary tree
- COMPLETE Binary tree
- PERFECT Binary tree

FUll Binary tree :
Every node in the tree will have either 0 or 2 child.No single child

<pre>
        [A]
        / \
      [B]  [C]
           / \
        [D]  [E]

0 child - [B] , [D] , [E]
1 child - None
2 child - [A] [C]

For representing 'n' nodes we need maximum 2n-1 size array
Array Representation = { [A] , [B] , [C] , Null , Null , [D] , [E] , Null , Null , Null }
</pre>

Complete Binary Tree :

- Every level must be completely filled except last level.
- The last level can either be completely filled or filled from left to right without leaving null inbetween.
- The array representation of Complete binary is continous,Only last spaces are left empty if the last level is partially filled.
- Therefore it is space efficient in array representation.
  > The Complete binary tree is BINARY HEAP

<pre>
Below there are two examples of Complete Binary tree

         [A]               [ A ]
        /   \             /     \
      [B]    [C]        [B]      [C]
     /  \     /        /   \    /   \
   [D]  [E] [F]      [D]   [E][F]    [G]


We can represent 'n' nodes in an array of size 'n';
Eg : First tree Array Representation = { [A] , [B] , [C] , [D] , [E] , [F] }
</pre>

Perfect Binary Tree :

- All internal nodes have two children and all leaf nodes are at same level
- Here the number of leaf nodes = number of internal nodes + 1
- In Perfect binary tree of height h , No.of nodes = 2^h - 1.

<pre>
Below there are two examples of Complete Binary tree

         [A]               [ A ]
        /   \             /     \
      [B]    [C]        [B]      [C]
                       /   \    /   \
                     [D]   [E][F]    [G]

For First tree,
    Internal Node = [A]     = 1
    Leaf Node     = [B],[C] = 2 = Internal Node + 1
Array Representation = { [A] , [B] , [C] , [D] , [E] , [F] , Null }
</pre>

## Variations of Binary Tree

- [Binary Search Tree](../Binary%20Search%20Tree/README.md)
- Binary Heap
- Balanced Binary Trees

[Catalan Number](https://www.geeksforgeeks.org/enumeration-of-binary-trees/) 

Before going into Binary tree basic operations we need to know two more important topics.

- [Tree Traversal](../Tree%20traversal/README.md)
- [Tree Searching](../Tree%20Searching/README.md)

After completing those two topics we can join Binary tree.

Lets Dive into Tree Traversal - [NEXT PAGE](../Tree%20traversal/README.md)

