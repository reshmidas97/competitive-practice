#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/majority-element/ 
without extra memory, Time complexity : O(n)
*/ 
int main()
{
	int current, current_count, max, max_count, temp;
	int size;
	cin >> size;
	vector<int> v;

	for(int i = 0; i < size ; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(),v.end());

	current =  v[0];
	current_count = 1;
	max = current;
	max_count = current_count;

	cout << endl << "Elements: " << endl;
	for(int i = 0; i < size ; i++)
	{
		cout << v[i] << " ";
	}

	cout << endl << current_count << " ";
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
		if(current_count > max_count)
		{
			max = current;
			max_count = current_count;
		}			
		
		
		cout << current_count << " ";
	}

	
	cout << endl << "Maximum occurence: " << max << " " << max_count << endl;
	return 0;
}