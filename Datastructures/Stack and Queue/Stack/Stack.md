# STACK

- LIFO - Last In First Out Strategy
- One Pointer - TOP
- Insert at the Top & Remove at the Top
- Underflow => _Trying to remove the element when the stack is empty_
- Overflow => _Trying to add the element when the stack is full_

## REAL LIFE EXAMPLE

- Submission of books
- Stack of plates

## APPLICATION

- Function call
- Infix to postfix/prefix conversition
- Postfix/prefix evaluation
- Brackect Evaluation
- Undo redo in editors and many more

## INTERNAL USE IN C++

STACK is used in memory allocation.

```cpp
    void fun(){
        int a = 5;
        float b = 6.0;
        cout<<a<<endl;
    }
```

     When the fun() is called the memory for a and b are allocated in the stack created for this function in physical memory(RAM).It is fastest way since allocationg memory in stack is moving the top pointer.After the function is completed the stack is emptied.Stack is faster than heap.

[CLICK HERE]("https://www.youtube.com/watch?v=wJ1L2nSIV1s")
To know about the memory allocation in detail [ youtube video]

> ## IMPLEMENTAION
>
> 1. Array
> 2. Linked List
>    <br>NOTE : Under flow may occur in both the implementaion but overflow occurs only in array

## BASIC OPERATIONS

| OPERATIONS | Time Complexity | Space Complexity |
| ---------- | --------------- | ---------------- |
| Push       | O(1)            | O(1)             |
| Pop        | O(1)            | O(1)             |
| Top/Peek   | O(1)            | O(1)             |
| isEmpty    | O(1)            | O(1)             |
| isFull     | O(1)            | O(1)             |

_NOTE : The both complexities are same in both array and Linked List implementation_

Important to notice in Stack implementation :

- Array implementaion :
  1. Initalize top to -1
  2. TOP should be point to CURRENT element top is indexed form 0 to N-1
  3. - push => preincrement the Top
     - pop => postincrement the Top
- Linked List Implementation

1. Check the Underflow condition in every operation

## Problems

1. Bracket Evaluation
2. Infix to postfix conversition
3. Postfix evaluation
4. Print reverse of linked list
5. Find next gerater element
6. Implement two stack using One Array

## Problem Solving intutions

1. To change the recursion to iteration
2. To find the ans in reverse order
3. If you want to use the lastly used element
