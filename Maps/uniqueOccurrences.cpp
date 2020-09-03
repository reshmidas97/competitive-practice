#include<bits/stdc++.h>

using namespace std;

/* 
https://leetcode.com/problems/unique-number-of-occurrences/

Unique Number of Occurrences:

Given an array of integers arr, write a function that returns true if 
and only if the number of occurrences of each value in the array is unique.
 
*/

bool uniqueOccurrences(vector<int>& arr) 
    {
        map<int, int> m1,m2;
        map<int, int>::iterator itr;

        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(m1.find(arr[i]) == m1.end())
                m1[arr[i]] = 1;
            else
                m1[arr[i]]++;
        }
        
            for (itr = m1.begin(); itr != m1.end(); ++itr) 
            { 
                if(m2.find(itr->second) == m2.end())
                    m2[itr->second] = itr->first;
            
                else
                    return false;
            }
        return true;
    }

int main()
{
    int size, temp;

    cout << "Enter the size of array: " << endl;
    cin >> size;

    vector<int> vec;

    for(int i = 0 ; i < size ; i++)
    {
        cin >> temp;
        vec.push_back(temp);
    }

    if(uniqueOccurrences(vec))
        cout << "true" << endl;
    else
        cout <<"false" << endl;

    return 0;
}