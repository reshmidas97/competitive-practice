#include<bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
Design a stack that supports getMin() in O(1) time and O(1) extra space.
*/

class SpecialStacks
{
	stack<int> s;
	int aux;

public:
	void push(int);
	void pop();
	void getMin();
	void display(stack<int>);
	
};
	void SpecialStacks :: push(int x)
	{
		if(s.empty())
		{
			s.push(x);
			aux = x;
			display(s);
			return;
		}
		if(x < aux)
		{
			s.push(2*x - aux);
			aux = x;
		}
		else
			s.push(x);

		display(s);
	}

	void SpecialStacks :: pop()
	{
		if(s.empty())
		{
			cout << "Stack Underflow" << endl;
			return;
		}

		if(s.top() < aux)
		{
			aux = 2*aux - s.top();
		}
		cout << "Popped: " << s.top() << endl;
		s.pop();
		display(s);
	}

	void SpecialStacks :: getMin()
	{
		if(!s.empty())
		{
			cout << "Minimum: " << aux << endl;
		}
	}

	void SpecialStacks :: display(stack<int> a)
	{
		cout << "STACK: ";
		while(!a.empty())
		{
			cout << a.top() << "  ";
			a.pop();
		}
		cout << endl;
	}

int main()
{
	SpecialStacks ss;
	ss.push(3);
	ss.getMin();
	ss.push(5);
	ss.getMin();
	ss.push(2);
	ss.getMin();
	ss.push(1);
	ss.getMin();
	ss.push(1);
	ss.getMin();
	ss.push(-1);
	ss.getMin();
	ss.pop();
	ss.getMin();
	ss.pop();
	ss.getMin();
	ss.pop();
	ss.getMin();
	ss.pop();
	ss.getMin();
	ss.pop();
	ss.getMin();
	ss.pop();
	ss.getMin();
	return 0;
}