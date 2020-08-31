#include<bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/next-greater-element/

Given an array, print the Next Greater Element (NGE) for every element. 
The Next greater Element for an element x is the first greater element on the right side of x in array. 
Elements for which no greater element exist, consider next greater element as -1.

Video: https://www.youtube.com/watch?v=NXOOYYwpbg4
*/

vector<int> nextGreatestElement(vector<int> vec)
{
	stack<int> s;
	vector<int> v;
	reverse(vec.begin(), vec.end());

	for(int i = 0 ; i < vec.size() ; i++)
	{
		if(s.empty())
		{
			v.push_back(-1);
			s.push(vec[i]);
			continue;
		}
		if(s.top() > vec[i])
		{
			v.push_back(s.top());
			s.push(vec[i]);
		}
		else
		{
			while(!s.empty() && vec[i] > s.top())
			{
				s.pop();
			}
			if(s.empty())
			{
				v.push_back(-1);
				s.push(vec[i]);
			}
			else
			{
				v.push_back(s.top());
				s.push(vec[i]);
			}
		}
	}
	reverse(v.begin(), v.end());
	return v;
}
int main()
{
	vector<int> vec;
	int size, temp;
	cout << "Enter size of Array: " << endl;
	cin >> size;

	for(int i = 0 ; i < size ; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
 	
 	cout << endl;
 	for(int i = 0 ; i < size ; i++)
		cout << vec[i] << " ";
	cout << endl;

	vec = nextGreatestElement(vec);

	for(int i = 0 ; i < size ; i++)
		cout << vec[i] << " ";
	cout << endl;

	return 0;
}