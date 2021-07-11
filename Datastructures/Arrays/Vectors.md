# VECTORS IN STL LIBRARY

- Vectors have contagious memory allocation,But unlike array they grow dynamically.
- They dont grow everytime when we add the element they grow logrithmicaly
  - i.e
    intial size would be 2 times of the data type size
    when the size if full it doubles the capacity to 4times , then 8times then 16times like that

OPERATIONS :
Constructors :

```c++
vector<int> nums;               //Empty Vector
vector<int> nums (4,100);       //[100,100,100,100]
vector<int> nums (d.begin() , d.end());//[ data btw the iterator ]
vector<int> nums (another_vector);  //[ copy of another vector ]
```

## Basic methods

### Iterators

- begin()
- end()
- rbegin()
- rend()

## Capacity

- size()
- empty()

## Elemental access

- Operator[]
- at()
- front()
- back()

## Modifiers

- push_back()
- pop_back()
- insert()

  ```cpp
  vector<int> vec(3,100) //[100,100,100]
  vector<int>::iterator it = vec.begin();

  vec.insert( it , 200) //[200,100,100,100]
  //"it" will be no longer valid
  it = vec.begin();
  vec.insert( it+2 , anothervector.begin(),anothervector.end()); //[200,100,...anothervector...,100,100]
  int arr[] = {1,2,3};
  vec.insert(vec.begin() , arr , arr+1); //[1,2,200,100,......100]
  ```

- erase()
- swap()
