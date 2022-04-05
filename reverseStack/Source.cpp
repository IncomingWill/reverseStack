/*
Title: Chapter Seventeen Stack reverseStack Function Program -- Source Code
Created by William Schaeffer
CPS 362
P. 1275, Challenge 3, Add reverseStack Function Program, Week 10
03.31.2022
*/

#include <iostream>

#include "linkedStack.hpp"
#include "stackType.hpp"

using namespace std;


int main()
{
	int STACK_SIZE = 3;

	stackType<int> testStack(STACK_SIZE);					//set size of array
	stackType<int> otherTestStack;							//default size of array

	testStack.push(48);
	testStack.push(99);
	testStack.push(444);

	cout << "Array based stack: " << endl << endl;

	while (!testStack.isEmptyStack())
	{
		cout << testStack.top() << endl;
		testStack.pop();
	}
	
	cout << "Placing 48, 99, and 44 back in the stack in the same order..." << endl << endl;

	testStack.push(48);
	testStack.push(99);
	testStack.push(444);

	otherTestStack.push(34);								//putting items in stack that will be destroyed
	otherTestStack.push(223);
	otherTestStack.push(2342);
	
	testStack.reverseStack(otherTestStack);

	cout << "Printing otherTestStack, which is a reverse copy of the first array stack: " << endl << endl;

	while (!otherTestStack.isEmptyStack())
	{
		cout << otherTestStack.top() << endl;
		otherTestStack.pop();
	}

	/*
	linkedStackType<int> testLinkStack;

	testLinkStack.push(28);
	testLinkStack.push(42);
	testLinkStack.push(345);

	cout << endl << "Link based stack: " << endl << endl;

	while (!testLinkStack.isEmptyStack())
	{
		cout << testLinkStack.top() << endl;
		testLinkStack.pop();
	}
	*/


	return 0;
}

//Function