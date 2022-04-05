/*
Title: Chapter Seventeen Stack reverseStack Function Program -- linkedStackType Header File
Created by William Schaeffer
CPS 362
P. 1275, Challenge 3, Add reverseStack Function Program, Week 10
03.31.2022
*/

#ifndef H_linkedStackType
#define H_linkedStackType

#include <iostream>
#include <cassert> 

#include "stackADT.h"

using namespace std;

//Definition of the node 

template <class Type>
struct nodeType
{
    Type info;
    nodeType<Type>* link;
};

//          ================  linkedStackType Class  ================

template <class Type>
class linkedStackType : public stackADT<Type>
{
public:

//Overload Operators

    //Overload the assignment operator.
    const linkedStackType<Type>& operator=(const linkedStackType<Type>&);

//Member Functions
    
    //Function to determine whether the stack is empty.
        //Postcondition: Returns true if the stack is empty; otherwise returns false.
    bool isEmptyStack() const;
    
    //Function to determine whether the stack is full.
        //Postcondition: Returns false.
    bool isFullStack() const;

    //Function to initialize the stack to an empty state. 
        //Postcondition: The stack elements are removed; stackTop = nullptr;
    void initializeStack();

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
    void reverseStack(linkedStackType<Type>& otherStack);

 //Constructors
    //Default constructor
        //Postcondition: stackTop = nullptr;
    linkedStackType();
    
    
    //Copy constructor
    linkedStackType(const linkedStackType<Type>& otherStack);

//Destructor
    //Postcondition: All the elements of the stack are removed from the stack.
    ~linkedStackType();
    

private:
    nodeType<Type>* stackTop; //pointer to the stack

    //Function to make a copy of otherStack.
        //Postcondition: A copy of otherStack is created and assigned to this stack.
    void copyStack(const linkedStackType<Type>& otherStack);
    
};

//Function to overload the assignment operator
template <class Type>
const linkedStackType<Type>& linkedStackType<Type>::operator=(const linkedStackType<Type>& otherStack)
{
    if (this != &otherStack)                    //avoid self-copy
        copyStack(otherStack);

    return *this;
}

//Other Functions

    //Function to test if stack is empty
template <class Type>
bool linkedStackType<Type>::isEmptyStack() const
{
    return(stackTop == nullptr);
}

    //Function to test if stack is full
template <class Type>
bool linkedStackType<Type>::isFullStack() const
{
    return false;
}

    //Function to initialize stack
template <class Type>
void linkedStackType<Type>::initializeStack()
{
    nodeType<Type>* temp;                       //pointer to delete the node

    while (stackTop != nullptr)                 //while there are elements in the stack
    {
        temp = stackTop;                        //set temp to point to the current node
        stackTop = stackTop->link;              //advance stackTop to the next node
        delete temp;                            //deallocate memory occupied by temp
    }
}

    //Function to set top element of stack
template <class Type>
void linkedStackType<Type>::push(const Type& newElement)
{
    nodeType<Type>* newNode;                    //pointer to create the new node

    newNode = new nodeType<Type>;               //create the node

    newNode->info = newElement;                 //store newElement in the node
    newNode->link = stackTop;                   //insert newNode before stackTop
    stackTop = newNode;                         //set stackTop to point to the top node
}

    //Function return the top element
template <class Type>
Type linkedStackType<Type>::top() const
{
    assert(stackTop != nullptr);                //if stack is empty, terminate the program
    return stackTop->info;                      //return the top element 
}

    //Function to remove top node of stack
template <class Type>
void linkedStackType<Type>::pop()
{
    nodeType<Type>* temp;                       //pointer to deallocate memory

    if (stackTop != nullptr)
    {
        temp = stackTop;                        //set temp to point to the top node

        stackTop = stackTop->link;              //advance stackTop to the next node
        delete temp;                            //delete the top node
    }
    else
        cout << "Cannot remove from an empty stack." << endl;
}

    //Function to copy one stack
template <class Type>
void linkedStackType<Type>::copyStack(const linkedStackType<Type>& otherStack)
{
    nodeType<Type>* newNode, * current, * last;

    if (stackTop != nullptr)                    //if stack is nonempty, make it empty
        initializeStack();

    if (otherStack.stackTop == nullptr)
        stackTop = nullptr;
    else
    {
        current = otherStack.stackTop;          //set current to point to the stack to be copied

    //copy the stackTop element of the stack 
        stackTop = new nodeType<Type>;          //create the node

        stackTop->info = current->info;         //copy the info
        stackTop->link = nullptr;               //set the link field of the node to nullptr
        last = stackTop;                        //set last to point to the node
        current = current->link;                //set current to point to the next node

    //copy the remaining stack
        while (current != nullptr)
        {
            newNode = new nodeType<Type>;

            newNode->info = current->info;
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

    //Function to reverse order of one stack onto another stack
template <class Type>
void linkedStackType<Type>::reverseStack(linkedStackType<Type>& otherStack)
{

}

//Constructors
    //Default constructor
template <class Type>
linkedStackType<Type>::linkedStackType()
{
    stackTop = nullptr;
}

    //copy constructor
template <class Type>
linkedStackType<Type>::linkedStackType(const linkedStackType<Type>& otherStack)
{
    stackTop = nullptr;
    copyStack(otherStack);
}

//Destructor
    //Removes all elements from the stack
template <class Type>
linkedStackType<Type>::~linkedStackType()
{
    initializeStack();
}

#endif