# TREES

## Introduction About the Trees

The Trees are _NON LINEAR_ Datastructures.Any data that is in heirarchial form can be represented as trees.
The most familiar example is our family tree

                    GrandFather  && Grandmother
                                /     \
                               /       \
                              /         \
                    Father && Mother   Uncle && Aunt
                        /   \               \
                       /     \               \
                      /       \               \
                    YOU      Sister         cousin

Why Trees ?
-Non-linear organization of elements. The components do not form a simple sequence of first element, second element, and so on.

## BASIC TREMINOLOGIES :

- Technical Terms :

  - Node - Nodes are the basic unit in trees.It contains the data
  - Branch - The number of edges a node can produce
  - Branching factor - number of children at each node.
  - Root - The node with no Parent.It doesnt have siblings.
  - Leaf - The node with no child.Last nodes in the tree.
  - path - The edges connecting one node to another
  - height - height of Node : No. of edges on the _longest path from node to leaf._ - height of Tree : No. of edges on the _longest path from root to leaf._
  - depth - The number of edges from node to root node.[It is node property].Depth at root node is 0
  - level - Nodes at same depth are level.level = depth + 1

_NOTE : Please view the below tree in fullscreen mode_

  <pre>
          | Height : 3_____Depth : 0_____Level : 1__________________   [ A ]           Node  : [A],[B],[C],[D],[E]
   Height |                                                           /      \         Root  : [A]
  of tree |                                                          /        \        Leaf  : [D],[E],[C]
     3    | Height : 2_____Depth : 1_____Level : 2___________    [ B ]       [ C ]     Paths : [ A -> B -> D],
  [A>B>D] |                                                     /     \                        [ A -> B -> E],
     or   |                                                    /       \                       [ A -> C ].
  [A>B>E] | Height : 1_____Depth : 2_____Level : 3________  [ D ]     [ E ]

  </pre>

- Anologies :

  - parent - A node which is predecessor of any node.Otherwords,A node with child is parent node,obiviously.
  - child -The node below a given node connected by its edge downward is child node
  - sibiling - Nodes with same parent
  - cousin - Nodes in the same level
  - neighbor - Parent or child node of current node
  - ancestor - Nodes at above level of current node is ancestor of current node.
  - descendant - Nodes which are below the level of the current node is descendant of current node.
  - subtree - a subset of larger tree

      <pre>
      Ancestor : None_____________Descendant : [B],[C],[D],[E]___   [ A ]            
                                                                   /      \         
                                                                  /        \        
      Ancestor : [A]  ____________Descendant : [D],[E]  _____  [ B ]       [ C ]    
                                                              /     \               
                                                             /       \                
      Ancestor : [A],[B],[C]_____Descendant : None _____  [ D ]     [ E ]
      </pre>

    |          | A       | B           | C    | D       | E       |
    | -------- | ------- | ----------- | ---- | ------- | ------- |
    | Parent   | None    | [A]         | [A]  | [B]     | [B]     |
    | Child    | [B],[C] | [D],[E]     | None | [D],[E] | [D],[E] |
    | Sibiling | None    | None        | None | None    | None    |
    | Cousin   | None    | [C]         | [C]  | [C]     | [C]     |
    | Neighbor | [B],[C] | [A],[D],[E] | [A]  | [B]     | [E]     |

    Applications and representation of trees:

- In other fields

  - School Management
  - Classification of animal kingdom
  - [Barnes-Hut trees](https://en.wikipedia.org/wiki/Barnes%E2%80%93Hut_simulation) - To simulate Galaxy
  - Workflow for composting digital images for visual effects
  - Trie tree is used in Phonebook
  - Desicion Tree - that models probable outcomes and possible consequences. It is used in civil planning, law , business etc.

- In Computer Science Field
  - Syntax Tree in Complier
  - Folder Structure in Operating Systems
  - Databases uses trees for indexing
  - Decision-based algorithms in Machine Learning
  - Domain Name Server also uses tree

To continue with Classification of trees - [NEXT PAGE](./Classification%20of%20Trees.md)
