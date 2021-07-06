# ARRAYS

- Stores homogeneous elements
- Size of array must be known
- Allocates memory in contagious location
- It is used to implement other data structures like hash table,tree,graph etc.

# Types of Arrays

- Static Arrays

  - Size cant be changed.Size must be known

  ```cpp
  int arr[5] = {0}; //[0,0,0,0,0]
  ```

- Dynamic Arrays

  - Variable length array

    - Allocating size on runtime.Size must been known at runtime.After that _we can't resize after creation(allocation)_. It is special case of Dynamic Array

    ```cpp
    int size;
    cin<<size;
    int arr[size];
    ```

  - Dynamic Array

    - The size of the variable can be changed anytime during runtime i.e _we can resize the array anytime_.It invloves API calls.The resize takes place in logrithmic manner that is the array size doubles itself if array is full.

    ```cpp
    int *arr = new int[ nums ];
    ```

### Advantages

- Cache performance is faster due to its contagious factor
- Random access of elements at O(1)

### Disadvantages

- Can't resize
- Insertion and deletion operations are costly

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
