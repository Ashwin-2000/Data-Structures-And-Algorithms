# Heap Data Structure

- It is a complete tree - All leaf nodes are at last level filled from left to right
- Types :
  - Min heap [The root is lesser than the child]
  - Max heap [The root is greater than the child]
- Binary heap is heap with root having atmost two children

- It is used in Heap sort
- It contains the largest/smallest element in the root.

# Representation

- We can represent it in array
- The root of tree is ARR[0]
  - It is the max element in the tree if it is max heap
  - It is the min element in the heap if it is min heap
- Parent of ith node = (i-1)/2
- Left child of Parent = (2*i)+1
- Right child of Parent = (2*i)+2

# Time Complexitites

- Heapify - O(h) in Binary Heap - O(Log n)
- Insertion - O(Log n)
- Deletion - O(log n)
- Extraction of min/max - O(1)

# Basic Operation

- Heapify
- Extractmin/max
- Insert
- Delete

# Problem statements uses

- Heap sort
- Finding the nth largest/smallest element.

## Application

- Heap Sort
- Priority Queue implements the below operation in O(logn)
  - insert()
  - delete()
  - extractmax()
  - decreaseKey()
- Graph Algorithms
  - Dijkstra's Shortest Path
  - Prims Minimum Spanning Tree

## STD Priority Queue
- The Heap data structure is implemented as priority queue in the STL Library

- For implementing Max Heap:
``` cpp
priority_queue< type_of_data > name_of_heap; 
```
- For implementing Min Heap:
```cpp
 priority_queue< type, vector<type>, greater<type> > name_of_heap;
```

  
- priority_queue::empty(): The empty() function returns whether the queue is empty.
priority_queue::size(): The size() function returns the size of the queue.
priority_queue::top(): This function returns a reference to the top most element of the queue.
priority_queue::push(): The push(g) function adds the element ‘g’ at the end of the queue.
priority_queue::pop(): The pop() function deletes the first element of the queue.
priority_queue::swap(): This function is used to swap the contents of one priority queue with another priority queue of same type and size.
## Problems

- Kth largest element in array
- Sort an almost sorted array
- Merge K sorted Array
