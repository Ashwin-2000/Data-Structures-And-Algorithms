# STRINGS

Strings are sequence of characters.

| Array of Char | Strings |
|---------------|---------|
| Allocated statically | Allocated dynamically |
| threat of array decay | no array decay |
| Faster | Slower |
| Dont offer inbuilt function | offers number of functionalities |

> Array decay - The size of the array decays to the size of the pointer,when it is passed to a function.

## Operations on String
-   getline()
    ```cpp
     #include<string>
     string str;
     getline(cin,str);
     //Al
    ```
-   push_back()
-   push_front()