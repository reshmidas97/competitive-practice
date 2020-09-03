#include<bits/stdc++.h>

using namespace std;

/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/

Find All Duplicates in an Array

Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

*/

vector<int> getDuplicates(vector<int>& v)
{
	int num = v.size();
	vector<int> ans;

	for(int i = 0 ; i < num ; i++)
	{
		if(v[v[i] % num] > num)
			ans.push_back(v[i] % num);

		v[v[i] % num] += num;
	}
	v.clear();
	return ans;
}

int main()
{	
	vector<int> v;
	int size, temp;

	cout << "Enter size of the array: " << endl;
	cin >> size;

	for(int i = 0 ; i < size ; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}

	v = getDuplicates(v);

	for(int i = 0 ; i < v.size() ; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	return 0;
}