#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/majority-element/ 
with extra memory, Time complexity : O(n)
*/ 
int main()
{
	int current, current_count, max, index, temp;
	int size;
	cin >> size;
	vector<int> v;
	vector<int> occurence;

	for(int i = 0; i < size ; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(),v.end());

	cout << endl << "Elements: " << endl;
	for(int i = 0; i < size ; i++)
	{
		cout << v[i] << " ";
	}

	current = v[0];
	current_count = 1;
	cout << endl << current_count << " ";
	occurence.push_back(current_count);
	for(int i = 1 ; i < size ; i++)
	{
		if(v[i] == current)
		{
			current_count++;
		}
		else
		{
			current = v[i];
			current_count = 1;
		}
		
		occurence.push_back(current_count);
		cout << current_count << " ";
	}
	cout << endl;
	max = occurence[0];
	index = 0;
	for(int i = 0; i < size ; i++)
	{
		cout << occurence[i] << " ";
		if(occurence[i] > max)
		{
			index = i;
			max = occurence[i];
		}
	}

	if(max > v.size()/2)
		cout << endl << "Maximum occurence: " << max << " of " << "Element " << v[index] << endl;
	else
		cout << "No Majority Element" << endl;

	return 0;
}