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

class extension
{
	stack<int> s;
	stack<int> aux;

public:
	void pop();
	void getMin();
	void push(int);
	void display(stack<int>);
};

void extension :: display(stack<int> a)
{
	cout << "STACK: ";
	while(!a.empty())
	{
		cout << a.top() << "  ";
		a.pop();
	}
	cout << endl;
}

void extension :: getMin()
{
	if(s.empty())
		cout << "stack empty" << endl;
	else
		cout << "Minimum: " << aux.top() << endl;
}

void extension :: push(int m)
{
	
	if(s.empty())
	{
		s.push(m);
		aux.push(m);
	}
	else
	{
		s.push(m);
		if(m < aux.top())
			aux.push(m);
		else
			aux.push(aux.top());
	}
	display(s);
}

void extension :: pop()
{
	if(s.empty())
	{
		cout << "stack underflow" << endl;
		return;
	}
	else
	{
		cout << "Popped: " << s.top() << endl;
		s.pop();
		aux.pop();
	}
	display(s);
}

int main()
{
	extension e;
	e.push(15);
	e.getMin();
	e.push(1);
	e.getMin();
	e.push(2);
	e.getMin();
	e.pop();
	e.getMin();
	e.pop();
	e.getMin();
	return 0;
}