# Tree Searching Algorithms :

    Tree searching algorithm are used to find the element in the tree.Whereas traversal is used to visit all nodes in the tree,like for loop in array.

- DFS - Depth First Search

  - Preorder
  - Inorder
  - Postorder

- BFS - Breadth First Search
  - Level Order traversal

## DEPTH FIRST SEARCH

- DFS is really an interesting algorithm.It is like you are walking into the maze with the ball of string>So if we meet at the intersection which we already visited.then we take a differernt path.
- Generally , DFS algo goes to the depth,until it reaches downward end and then backtrack and continues.
- DFS uses the traversal algorithms.All the tree traversal algorithms are different types of DFS.
- DFS plays important role in Graphs rather than trees.We will explore more there.
- Types of DFS and its implementation:
- [Preorder](./Preorder/preorder.cpp)
- [Inorder](./Inorder/inorder.cpp)
- [Preorder](./Postorder/postorder.cpp)

## Breadth First Search

- BFS is level order searching algorithm,Unlike DFS. In DFS we explore the tree height wise.In BFS we will explore the tree width wise.
- BFS searches level by level using queue.Each level consisit of sibling nodes.
- Since we use queue instead of stack,we traverse to adjacent nodes at the same level rather than the child nodes.This small change in data structure differs in sunch a manner.
- CODE for BFS - [Click here](BFS.cpp)
