#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/pascal-triangle/
Pascal Triangle with Time complexity: O(n)
*/

vector<vector<int> > generate(int numRows) 
    {
        int temp;
        vector< vector<int> > v;
        vector<int> a;
        for(int i = 0 ; i < numRows ; i++)
        {
            a.clear();
            for(int j = 0 ; j <= i ; j++)
            {
                if(j == 0 || j == i)
                    a.push_back(1);
                
                else
                {
                    temp = v[i-1][j-1] + v[i-1][j];
                    a.push_back(temp);
                
                }
               
            }
             v.push_back(a);
        }
        
        return v;
        
    }

int main()
{
    int line;
    cin >> line;

    vector< vector<int> > v = generate(line);

    for(int i = 0 ; i < v.size() ; i++)
    {
        for(int j = 0 ; j <= i ; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

}