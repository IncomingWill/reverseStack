/*
Title: Chapter Seventeen Stack reverseStack Function Program -- linkedStackType Header File
Created by William Schaeffer
CPS 362
P. 1275, Challenge 3, Add reverseStack Function Program, Week 10
03.31.2022
*/

#ifndef H_StackType
#define H_StackType

#include <iostream> 
#include <cassert>

#include "stackADT.h"

using namespace std;

template <class Type>
class stackType : public stackADT<Type>
{
public:
    
//Overload Operators
    
    //Overload the assignment operator.
    const stackType<Type>& operator=(const stackType<Type>&);

//Member Functions

    //Function to initialize the stack to an empty state.
        //Postcondition: stackTop = 0
    void initializeStack();
    
    //Function to determine whether the stack is empty.
        //Postcondition: Returns true if the stack is empty,  otherwise returns false.
    bool isEmptyStack() const;
    
    //Function to determine whether the stack is full.
        //Postcondition: Returns true if the stack is full, otherwise returns false.
    bool isFullStack() const;
    
    //Function to add newItem to the stack.
        //Precondition: The stack exists and is not full.
        //Postcondition: The stack is changed and newItem is added to the top of the stack.
    void push(const Type& newItem);
    
    //Function to return the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: If the stack is empty, the program terminates; 
        //otherwise, the top element of the stack is returned.
    Type top() const;
    
    //Function to remove the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: The stack is changed and the top element is removed from the stack.
    void pop();
    
    //Function to reverse order of one stack onto another stack
        //Precondition: Both stacks exist and are not empty.
        //Postcondition: Stack passed to function (otherStack) is deleted and then becomes a reverse copy of calling stack
    void reverseStack(stackType<Type>& otherStack);

//Constructors

    //Create an array of the size stackSize to hold the stack elements. 
        //The default stack size is 100.
        //Postcondition: The variable list contains the base address of the array, 
        //stackTop = 0, and maxStackSize = stackSize.
    stackType(int stackSize = 100);
    
    //copy constructor
    stackType(const stackType<Type>& otherStack);

//Destructor
    //Remove all the elements from the stack.
        //Postcondition: The array (list) holding the stack elements is deleted.
    ~stackType();
    

private:
    int maxStackSize;                       //variable to store the maximum stack size
    int stackTop;                           //variable to point to the top of the stack
    Type* list;                             //pointer to the array that holds the stack elements
                      
    //Function to make a copy of otherStack.
        //Postcondition: A copy of otherStack is created and assigned to this stack.
    void copyStack(const stackType<Type>& otherStack);
    
};

//Function to overload the assignment operator
template <class Type>
const stackType<Type>& stackType<Type>::operator=(const stackType<Type>& otherStack)
{
    if (this != &otherStack)                //avoid self-copy
        copyStack(otherStack);

    return *this;
}

    //Function to initialize stack
template <class Type>
void stackType<Type>::initializeStack()
{
    stackTop = 0;
}

    //Function to test if stack is empty
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
    return (stackTop == 0);
}

    //Function to test if stack is full
template <class Type>
bool stackType<Type>::isFullStack() const
{
    return (stackTop == maxStackSize);
}

    //Function to set top element of stack
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
    if (!isFullStack())
    {
        list[stackTop] = newItem;           //add newItem to the top of the stack
        stackTop++;                         //increment stackTop
    }
    else
        cout << "Cannot add to a full stack." << endl;
}

    //Function to return the top element of stack
template <class Type>
Type stackType<Type>::top() const
{
    assert(stackTop != 0);                  //if stack is empty, terminate the program
    return list[stackTop - 1];              //return the element of the stack indicated by stackTop - 1
}

    //Function to remove top element of stack
template <class Type>
void stackType<Type>::pop()
{
    if (!isEmptyStack())
        stackTop--;                         //decrement stackTop 
    else
        cout << "Cannot remove from an empty stack." << endl;
}

    //Function to reverse order of one stack onto another stack
template <class Type>
void stackType<Type>::reverseStack(stackType<Type>& otherStack)
{
    if (!this->isEmptyStack() || !otherStack.isEmptyStack())
    {
        delete[] otherStack.list;
        otherStack.maxStackSize = maxStackSize;
        otherStack.stackTop = stackTop;
        
        otherStack.list = new Type[maxStackSize];

        int i = 0;

        for (int j = stackTop - 1; j >= 0; j--)
        {
            otherStack.list[i] = list[j];
            i++;
        }
    }
    else
        cout << "Cannot copy an empty stack." << endl;
}

//Constructor
    //Function to create stack
template <class Type>
stackType<Type>::stackType(int stackSize)
{
    if (stackSize <= 0)
    {
        cout << "Size of the array to hold the stack must be positive." << endl;
        cout << "Creating an array of size 100." << endl;

        maxStackSize = 100;
    }
    else
        maxStackSize = stackSize;           //set the stack size to the value specified by the parameter stackSize

    stackTop = 0;                           //set stackTop to 0
    list = new Type[maxStackSize];          //create the array to hold the stack elements
}

//Destructor
    //Deletes list to remove all elements from stack

template <class Type>
stackType<Type>::~stackType()
{
    delete[] list;                          //deallocate the memory occupied by the array
}

    //Function to copy stack
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
    delete[] list;
    maxStackSize = otherStack.maxStackSize;
    stackTop = otherStack.stackTop;

    list = new Type[maxStackSize];

//copy otherStack into this stack
    for (int j = 0; j < stackTop; j++)
        list[j] = otherStack.list[j];
}

    //Constructor
template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
    list = nullptr;

    copyStack(otherStack);
}     

#endif