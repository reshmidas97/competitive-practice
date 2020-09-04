#include<bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/implement-stack-using-queue/

Implement Stack using Queues
*/

class stackUsingQueue
{
private:
	int front, rear;
	queue<int> q1, q2;

public:
	void push(int);
	void pop();
	void display();
};

void stackUsingQueue :: display()
{
	queue<int> q3(q2);
	if(!q2.empty())
	{	
		cout << "Stack: " << endl;
		while(!q3.empty())
		{
			cout << q3.front() << " ";
			q3.pop();
		}
		cout << endl;
	}
	else
		cout << "Stack Empty" << endl;
}

void stackUsingQueue :: push(int x)
{
	if(q2.empty())
		q1.push(x);

	else
	{	
		q1.push(x);

		while(!q2.empty())
		{
			q1.push(q2.front());
			q2.pop();
		}
	}

	while(!q1.empty())
	{
		q2.push(q1.front());
		q1.pop();
	}
}

void stackUsingQueue :: pop()
{
	if(!q2.empty())
	{	
		cout << "Popped: " << q2.front() << endl;
		q2.pop();
		display();
	}
	else
	{
		cout << "Stack Underflow" << endl;
	}
}

int main()
{
	stackUsingQueue sq;
	int ch, temp;
	char ans;
	do
	{
		cout << "Menu:\n1-Push\n2-Pop\n3-Exit\n";
		cin >> ch;

		switch(ch)
		{
			case 1:
				cout << "Enter number to be Pushed: " << endl;
				cin >> temp;
				sq.push(temp);
				sq.display();
				break;

			case 2:
				sq.pop();
				break;

			case 3:
				exit(0);

			default:
				cout << "Invalid Entry" << endl;
				break;
		}
		cout << "Do you want to continue?\nY - Yes\nN - No\n";
		cin >> ans;

	}while(ans == 'y' || ans == 'Y');
}