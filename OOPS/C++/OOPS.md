# Pillars of OOPS

- Encapsulation
- Abstraction
- Inheritance
- Polymorphism

# OOPS in cpp

- Encapsulation
  - Classes and Struct encaplsulates/binding the data members and member functions
- Abstraction =>Hiding the implementation and showing the essential features
  - Using Access Specifiers - Private , Public , Protected
- Inheritance => Inherit the property of base class.
  - Reduce the code size , and helps in testing
- Polymorphism  => same name different functionality
  - Overloading and Overriding the functions

## Abstraction
- It is a concept and it is achieved through access specifiers
- Access specifiers
  - Private    - Can be used only within class not outside not inherited[ default ] { for struct public is default }
  - Protected  - Can be used within the class in derived class but not outside the base and derived class
  - Public   - Can be used anywhere in the program
  
- On Inheriting the class 
  - Privately inherited class
     - Base class protected  => Derived class private
     - Base class public     => Derived Class Private
  - Protectedly inherited class
     - Base class protected => Derived Class Protected   
     - Base class public => Derived Class Protected   
  - Publicly inherited class
     - Base class protected => Derived Class Protected  *** 
     - Base class public => Derived Class Public   ***
  
## Inheritance

- Types of Inheritance
  - Single Inheritance
  - Multilevel Inheritance
  - Multiple Inheritance - [Not supported in Java but can be implemented through Interface]
  - Heirarchial Inheritance
  - Hybrid Inheritance (Virtual Inheritance)
  
- Execution Order of constructor Call
  - Base class is called first
  - It is like when the object of derived class is created , the memory for derived should be created , in order to to that we create the obj of base class first so its constructor is called initially
  NOTE  : Destructor execute opposite to constructor,it calls the derived class first and then base class
-  In Multiple Inheritance , the class names are seperated from comma,THe constructor starts from leftmost to right.If there is virtual inheritance it is give preference

## Polymorphism

- #### Compile time/ Static /Early Binding Polymorphism
- Types
  - Function Overloading
  - Operator Overloading
  - Constructor Overloading
  - Template Overloading
  
  - <b>Function Overloading</b>
    > Same function name , Same return type but differ by
    >
    >- No. of Parameter
    >- If no. of parameter is same, then type of parameter
    >- Or Order of parameter
    >NOTE : Return type is not considered 
    ```cpp
            void sum( int x , float y);
            void sum( int x , int y);
        /* The implementation goes here*/
            sum(10,3.5);    //Throws Ambigious error
            sum(3.5,10);    //seond sum is executed
    ```
  - <b>Operator Overloading</b>
        - Not all operator can be overloaded
  
- #### Runtime / Dynamic / Late Binding Polymorphism
  - Types 
    - Virtual Functions
    - Virtual Class
    - Virtual Destructor 
    - <b>Virtual Functions</b>
