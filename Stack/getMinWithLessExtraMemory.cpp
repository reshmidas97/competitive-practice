#include<bits/stdc++.h>

using namespace std;

class SpecialStack
{
	stack<int> s;
	stack<int> aux;
public:
	void push(int);
	void pop();
	void display(stack<int>);
	void getMin();
	
};

void SpecialStack :: push(int a)
{
	if(s.empty())
	{
		s.push(a);
		aux.push(a);
	}
	else
	{
		s.push(a);
		if(a < aux.top())
			aux.push(a);
	}
	display(s);
}

void SpecialStack :: pop()
{
	if(s.empty())
	{
		cout << "Stack underflow" << endl;
	}
	else
	{
		if(aux.top() == s.top())
		{
			aux.pop();
			cout << "Popped: " << s.top() << endl;
			s.pop();
		}
		else
			s.pop();
	}
	display(s);
}

void SpecialStack :: getMin()
{
	if(s.empty())
		cout << "stack empty" << endl;
	else
		cout << "Minimum: " << aux.top() << endl;
}

void SpecialStack :: display(stack<int> a)
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
	SpecialStack s;
	s.push(15);
	s.getMin();
	s.push(1);
	s.getMin();
	s.push(2);
	s.getMin();
	s.pop();
	s.getMin();
	s.pop();
	s.getMin();
	return 0;
	
}