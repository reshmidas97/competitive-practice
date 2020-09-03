#include<bits/stdc++.h>

using namespace std;

/*
https://leetcode.com/problems/number-of-good-pairs/

Number of Good Pairs

Given an array of integers nums.

A pair (i,j) is called good if nums[i] == nums[j] and i < j.

Return the number of good pairs.

*/

int numIdenticalPairs(vector<int>& nums) 
{
    map<int, int> f;
    int i, n, sum=0;
    map <int, int>::iterator itr;

    for(i = 0 ; i < nums.size() ; i++)
    {
        if(f.find(nums[i]) == f.end())
            f[nums[i]] = 1;
        else
            f[nums[i]]++;
    }
        
    for(itr = f.begin() ; itr != f.end() ; ++itr)
    {
        n = itr->second;
        if(n > 1)
            sum += (n*(n-1))/2;
    }   
    return sum;
    
}

int main()
{
    int size, temp;
    vector<int> v;

    cout << "Enter size of array" << endl;
    cin >> size;

    for(int i = 0 ; i < size ; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }

    cout << "Sum: " << numIdenticalPairs(v) << endl;
    return 0;
}
