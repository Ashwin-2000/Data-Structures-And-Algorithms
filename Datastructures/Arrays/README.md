# ARRAYS

- Stores homogeneous elements
- Size of array must be known
- Allocates memory in contagious location
- It is used to implement other data structures like hash table,tree,graph etc.

# Types of Arrays

- Static Arrays

  - Size cant be changed.Size must be known
  - Memory is allocated in stack
  - They are contagiously allocated so the scaling is limited

  ```cpp

  int arr[5] = {0}; //[0,0,0,0,0]
  //Static Memory allocation - memory for array is allocated in STACK
  ```

- Dynamic Arrays

  - Variable length array

    - Allocating size on runtime.Size must been known at runtime.After that _we can't resize after creation(allocation)_. It is special case of Dynamic Array

    ```cpp
    int size;
    cin<<size;
    int arr[size];
    //Size of array is get during runtime
    //But the allocation is in the stack
    ```

  - Dynamic Array - The memory is allocated in the heap rather than the stack.The size should be known at the runtime.But we can resize it with a workaround i.e creating new array of greater size.But since the allocation of memory is in heap,it is more scalable than the static array.

    ```cpp
    int *arr = new int[ nums ];
    //Dynamic allocation - memory of array is allocated in HEAP delete[] arr;
    //We need to freed the memory allocated at the end of the program `
    delete[] arr;
    ```

_NOTE : Heap and Stack memory Allocation Video - [Click Here](https://www.youtube.com/watch?v=wJ1L2nSIV1s)_

# Analysis of Array

> ### Accessing the Element

<pre>
    Both sequential and random access can be performed using []operator
        Time Complexity : O(1)
        Space Complexity : O(1)
</pre>

> ### Searching the Element

<pre>
Linear Search :
    Time Complexity  : O(n)
    Space Complexity : O(1)
Binary Search :
    Time Complexity  : O(n)
    Space Complexity : O(1)

</pre>

> ### Inserting the ELement

<pre>
Best Case : Inserting at end
    Time Complexity : O(1)
    Space Complexity  : amortized for allocation for more space
Worst case :On Inserting at the first index we need to move all elements to the right by one
    Time Complexity  : O(n)
    Space Complexity : O(n)
</pre>

> ### Deletion time

<pre>
Best case : Removing at the end
    Time Complexity : O(1)
    Space Complexity : O(1)
Worst case : Deleting the first element and moving all elements to the left by one.
    Time Complexity  : O(n)
    Space Complexity : O(n)
</pre>

### Advantages

- Cache performance is faster due to its contagious factor
- Random access of elements at O(1)

### Disadvantages

- Can't resize
- Insertion and deletion operations are costly

---

## STL CONTAINER FOR ARRAY

- THe STL library provide us static array using container _array_.[Nothing Special..but take a look]
- The STL library provide us dynamic array using _vector_.[ Very Imp ]
  - The size of the variable can be changed anytime during runtime i.e _we can resize the array anytime_.
  - The resize takes place in logrithmic manner that is the array size doubles itself if array is full.
  ```cpp
  #include<vector>
  vector<int> vec;
  vec.push_back(0);   //[0]
  ```
  Cheat sheet for Vector - [Click here](./Vectors.md)
