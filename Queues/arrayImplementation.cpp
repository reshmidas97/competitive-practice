#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

/*
https://www.geeksforgeeks.org/queue-set-1introduction-and-array-implementation/

Array implementation Of Queue
*/

class ArrayImplementationOfQueue
{
private:
	int front, rear;
	int arr[SIZE];
public:
	ArrayImplementationOfQueue();
	void Enqueue(int);
	void Dequeue();
	bool isEmpty();
	bool isFull();
	void display();

};

ArrayImplementationOfQueue :: ArrayImplementationOfQueue()
{
	front = -1;
	rear = -1;
}

void ArrayImplementationOfQueue :: Enqueue(int x)
{
	if(isEmpty())
	{
		rear = front = 0;
		arr[rear] = x;
	}
	else
	{
		arr[(++rear) % SIZE] = x;
	}
}

void ArrayImplementationOfQueue :: Dequeue()
{
	if(isEmpty())
		cout << "Queue Underflow" << endl;

	else
	{
		cout << "Dequeued Element: " << arr[front] << endl;
		front = (front + 1) % SIZE;
	}
}

bool ArrayImplementationOfQueue :: isEmpty()
{
	if(front == -1 && rear ==  -1)
		return true;
	return false;
}

bool ArrayImplementationOfQueue :: isFull()
{
	if((rear + 1) % SIZE == front)
		return true;
	return false;
}

void ArrayImplementationOfQueue :: display()
{
	cout << "Queue: " << endl;
	
	int i = front;
	do
	{
		cout << arr[i] << " ";
		i = (i + 1) % SIZE;
	}while(i != (rear + 1) % SIZE);
	cout << endl << endl;

}

int main()
{
	ArrayImplementationOfQueue aq;
	int ch, temp;
	char ans;

	do
	{
		cout << "Menu:\n1-Enqueue\n2-Dequeue\n3-Exit\n";
		cin >> ch;

		switch(ch)
		{
			case 1:
				cout << "Enter number to be Enqueued" << endl;
				cin >> temp;
				if(!aq.isFull())
					aq.Enqueue(temp);
				else
					cout << "Queue Overflow" << endl;
				aq.display();
				break;

			case 2:
				aq.Dequeue();
				aq.display();
				break;

			case 3:
				exit(0);
				break;

			default:
				cout << "Invalid Number" << endl;
		}

		cout << "Do you want to continue?\nY - Yes\nN - No\n";
		cin >> ans;

	}while(ans == 'y' || ans == 'Y');

	return 0;
}