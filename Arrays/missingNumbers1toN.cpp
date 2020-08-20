#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/find-missing-elements-from-an-array/
Problem statement:
Find missing numbers from [1-N] in an array of size N
*/

int main()
{
	int size, temp;
	cin >> size;
	vector<int> v;

	for(int i = 0 ; i < size ; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	vector<int> vec(size, 0);

	for(int i = 0 ; i < size ; i++)
		vec[v[i]-1] = 1;

	for(int i = 0 ; i < size ; i++)
	{
		if(vec[i] == 0)
			cout << i+1 << " ";
	}

	cout << endl;

}
