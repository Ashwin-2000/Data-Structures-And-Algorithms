# Generic Trees / N-array Trees

- A parent node can have any number of child
- The number of child is not known.
- Real life example : Tasks which contains substasks.We dont know how many tasks are going to be there ans how many subtasks for each tasks.
  Generic Tree in Java with real time application - [Click Here](https://sujitpal.blogspot.com/2006/05/java-data-structure-generic-tree.html)
  <br>
  <br>

# N-ary / M-Ary trees

- The parent node can have atmost 'm' childs.
  - if m=2 , it is Bi-nary tree
  - if m=3 , it is ternary tree
- Types of m-ary trees :
  - _**Full m-ary tree**_ - Every node will have either 0 or 'm' children
  - _**Complete m-ary tree**_ - It must be completely filled at every level except last level.If last level is not complete , then all nodes must be "as far left as possible".It is space efficient.
  - _**Perfect m-ary tree**_ - All leaf nodes are at same depth.
    NOTE : DOnt worry the above trees are explained in Binar

## Properties

- m-ary tree with height h , then maximum number of nodes is m^h.
- The total number of possible m-ary tree with n-nodes is [Catalan number](https://www.geeksforgeeks.org/program-nth-catalan-number/).
  <br>
  <br>

## Difference between N-array Trees and N-ary trees

| N-array trees                                                                                                               | N-ary Trees                                                                                                                                                                                                                                                                                                  |
| --------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| The maximum number of child a parent node can have is node fixed                                                            | The maximum number of child a parent node can have in 'n'                                                                                                                                                                                                                                                    |
| The no. of child is determined at runtime                                                                                   | The maximum no. of child a node can have is fixed before runtime                                                                                                                                                                                                                                             |
| Since the number of child is not known, dynamic arrays (vectors)are used to store the reference of child node               | We can use array of pointers or individual pointers ( for small n) to store the reference of the child node                                                                                                                                                                                                  |
| <pre> struct node { <br>&nbsp;&nbsp;&nbsp;&nbsp;int data;<br>&nbsp;&nbsp;&nbsp;&nbsp;vector< node\* >children;<br>}; </pre> | <pre> struct node { <br>&nbsp;&nbsp;&nbsp;&nbsp;int data;<br>&nbsp;&nbsp;&nbsp;&nbsp;Node *first_children;<br>&nbsp;&nbsp;&nbsp;&nbsp;Node *second_children;<br>&nbsp;&nbsp;&nbsp;&nbsp;Node *third_children;<br>&nbsp;&nbsp;&nbsp;&nbsp;......<br>&nbsp;&nbsp;&nbsp;&nbsp;Node *nth_children; <br>}; </pre> |

---

<br>

### Why Binary tree is used in most of the text book and website and not Generic trees or N-ary Trees ?

On learning of tree data structure , you can see all tree algorithms and contents are based on _Binary Tree_ - A tree with atmost two child.Maximum every travesal algorithms and other tree data strucutre are developed on thr binary tree.
This is because binary tree are mostly used and have wide range of application due to its two nature property _Yes/No_.

Algorithms on Binary tree is easy to understand and implement.Thats why we come across mostly about binary tree not m-ary or genric trees.Mostly all basic algorithms in binary tree can be applied to all tree.

_**NOTE:For sake of grasping concept we are going to implement all traversal and searching algorithms in Binary tree.**_

Next on We can introduce ourself to Binary tree and know about the traversal and searching on trees [NEXT ONE](./Binary%20Tree/README.md)
