/*
Title: Chapter Seventeen Stack reverseStack Function Program -- stackADT File
Created by William Schaeffer
CPS 362
P. 1275, Challenge 3, Add reverseStack Function Program, Week 10
03.31.2022
*/

#ifndef H_StackADT
#define H_StackADT 

template <class Type>
class stackADT
{
public:
    //Method to initialize the stack to an empty state.
        //Postcondition: Stack is empty
    virtual void initializeStack() = 0;
    
    //Function to determine whether the stack is empty.
        //Postcondition: Returns true if the stack is empty, otherwise returns false.
    virtual bool isEmptyStack() const = 0;
    
    //Function to determine whether the stack is full.
        //Postcondition: Returns true if the stack is full, otherwise returns false.
    virtual bool isFullStack() const = 0;
    
    //Function to add newItem to the stack.
        //Precondition: The stack exists and is not full.
        //Postcondition: The stack is changed and newItem is added to the top of the stack.
    virtual void push(const Type& newItem) = 0;
    
    //Function to return the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: If the stack is empty, the program terminates; 
            //otherwise, the top element nof the stack is returned.
    virtual Type top() const = 0;

    //Function to remove the top element of the stack.
        //Precondition: The stack exists and is not empty.
        //Postcondition: The stack is changed and the top element is removed from the stack.
    virtual void pop() = 0;

};
    

#endif