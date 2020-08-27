#include<bits/stdc++.h>

using namespace std;

/*
Implement getMax() to find Maximum element in the stack
Using O(1) Auxiliary space
*/

class SpecialStack
{
private:
	stack<int> s;
	int aux;

public:
	void push(int);
	void pop();
	//void display();
	void getMax();
};

void SpecialStack :: push(int x)
{
	if(s.empty())
	{
		aux = x;
		s.push(x);
	}
	else
	{
		if(x < aux)
			s.push(x);

		else
		{
			s.push(aux + x);
			aux = x;
		}
	}
}

void SpecialStack :: pop()
{
	if(s.empty())
	{
		cout << "Stack Underflow" << endl;
		return;
	}

	if(s.top() < aux)
		s.pop();

	else
	{
		aux = s.top() - aux;
		s.pop();
	}
}

void SpecialStack :: getMax()
{
	cout << "Maximum: " << aux << endl;
}
int main()
{
	SpecialStack s;
	s.push(9);
	s.getMax();
	s.push(4);
	s.getMax();
	s.push(12);
	s.getMax();
	s.push(3);
	s.getMax();
	s.push(17);
	s.getMax();
	s.push(2);
	s.getMax();
	s.pop();
	s.getMax();
	s.pop();
	s.getMax();
	s.pop();
	s.getMax();
	s.pop();
	s.getMax();
	s.pop();
	s.getMax();
	return 0;
}