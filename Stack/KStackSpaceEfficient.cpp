#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/
reate a data structure kStacks that represents k stacks. Implementation of kStacks 
should use only one array, i.e., k stacks should use the same array for storing elements. 
Following functions must be supported by kStacks.
*/

void push(int value, int s, int arr[], int next[], int& free, int top[])
{
	int temp = free;
	arr[free] = value;
	free = next[free];

	next[temp] =top[s-1];
	top[s-1] = temp;
}

void displayStack(int s, int arr[], int next[], int free, int top[])
{
	if(top[s-1] != -1)
	{
		cout << "Elements in stack: " << s << endl;
		cout << arr[top[s-1]] << " ";
		int n = next[top[s-1]];
		while(n != -1)
		{
			cout << arr[n] << " ";
			n = next[n];
		}
		cout << endl;
	}
}

int pop(int s, int arr[], int next[], int& free, int top[])
{
	int temp;
	int popp = arr[top[s-1]]; 
	temp = next[top[s-1]];
	next[top[s-1]] = free;
	free = top[s-1];
	top[s-1] = temp;
	return popp;
}

int main()
{
	int stacks;
	cout << "Enter the number of stacks: " << endl;
	cin >> stacks;

	int num, choice, stack_number;
	char ch;
	int top[stacks];

	for(int i = 0 ; i < stacks ; i++)
		top[i] = -1;

	int arr[100];
	int next[100];
	int free = 0;

	for(int i = 0 ; i < 99 ; i++)
		next[i] = i+1;

	next[100] = -1;

	do
	{
		cout << "\nMENU: " << endl;
		cout << "1 - Push \2 - Pop \n3 - Exit" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;

		switch(choice)		
		{
			case 1:
				cout << "Enter the number to be pushed" << endl;
				cin >> num;
				cout << "Enter the stack in which the number is to be pushed" << endl;
				cin >> stack_number;
				if(stack_number < 1 && stack_number > stacks)
				{
					cout << "Invalid Entry" << endl;
					break;
				}
				push(num, stack_number, arr, next, free, top);
				break;


			case 2:
				cout << "Enter the stack number from which you wish to pop" << endl;
				cin >> stack_number;
				cout << "Popped: " << pop(stack_number, arr, next, free, top) << endl;
				break;


			case 3:
				exit(0);
				
			default:
				cout << "Invalid Entry" << endl;
				break;

		}

		for(int i = 1 ; i <= stacks ; i++)
			displayStack(i, arr, next, free, top);
		cout << endl;
		cout << "Do you wish to continue? " << endl;
		cout << "Enter: \nY for Yes \nN for No" << endl;
		cin >> ch;

	}while(ch == 'y' || ch =='Y');
	return 0;
}