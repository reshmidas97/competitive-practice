#include<bits/stdc++.h>

using namespace std;

/* https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/

Design a Data Structure stack that supports all the stack operations 
like push(), pop(), isEmpty(), isFull() and an additional operation getMin()
 which should return minimum element from it. 
 All these operations of SpecialStack must be O(1). 
 To implement the stack, you should only use standard Stack data structure and 
 no other data structure like arrays, list, .. etc.
 */

class Stack
{
private:
	static const int size = 100;
	int arr[size];
	int top;

public:
	bool isEmpty();
	bool isFull();
	int peek();
	int pop();
	void push(int);
	Stack();

};

bool Stack :: isEmpty()
{
	if(top == -1)
		return true;
	return false;
}

bool Stack :: isFull()
{
	if(top == size - 1)
		return true;
	return false;
}

int Stack :: peek()
{
	if(!isEmpty())
		return arr[top];
	else
		cout << "Stack Empty" << endl;
}

int Stack :: pop()
{
	if(isEmpty())
		cout << "Stack Underflow" <<  endl;

	return arr[top--];
}

void Stack :: push(int x)
{
	if(top == size - 1)
		cout << "Stack Overflow" << endl;

	else
		arr[++top] = x;

}

Stack :: Stack()	
{
	top = -1;
}

class SpecialStack 
{

	Stack s;
	Stack aux;
public:
	int getMin();
	void pop();
	void push(int);

};


void SpecialStack :: pop()
{
	if(s.isEmpty())
		cout << "Stack Underflow" << endl;

	else
	{
		int a = s.pop();
		aux.pop();
		cout << a << endl;
	}
}

void SpecialStack :: push(int x)
{
	if(s.isEmpty())
	{
		s.push(x);
		aux.push(x);
	}	
	else 
	{
		s.push(x);
		int y = aux.peek();
		if(x < y)
			aux.push(x);
		else
			aux.push(y);
	}
}
	

int SpecialStack :: getMin()
{
	return aux.peek();
}

int main()
{
	SpecialStack s;
	s.push(15);
	s.push(20);
	cout << "Min:" << s.getMin() << endl;
	s.push(5);
	cout << "Min:" << s.getMin() << endl;
	s.pop();
	cout << "Min:" << s.getMin() << endl;
	return 0;
}