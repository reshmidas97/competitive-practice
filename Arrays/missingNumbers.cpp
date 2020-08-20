#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
 https://www.geeksforgeeks.org/find-missing-elements-from-an-array/
My modified problem statement:
The range is not given, we have to find missing numbers from 
1 to the maximum number in the given list
*/

int main()
{
	int size, temp, max;
	cin >> size;
	vector<int> v;

	for(int i = 0 ; i < size ; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());
	max = v[size-1];

	vector<int> vec(max, 0);

	for(int i = 0 ; i < size ; i++)
		vec[v[i]-1] = 1;

	for(int i = 0 ; i < max ; i++)
	{
		if(vec[i] == 0)
			cout << i+1 << " ";
	}

	cout << endl;

}
