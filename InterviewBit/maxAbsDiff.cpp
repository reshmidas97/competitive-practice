/*

QUESTION:

Maximum Absolute Difference
 
https://www.interviewbit.com/problems/maximum-absolute-difference/

*/


#include<bits/stdc++.h>

using namespace std;

int maxAbsolute(vector<int> &A)
{
	 for(int i = 0 ; i < A.size() ; i++)
    {
       A[i] = A[i] + (i+1);
       //cout << A[i] << endl;
    }

    auto max1 = max_element(A.begin(), A.end());
    auto min1 = min_element(A.begin(), A.end());

    int result1 = *max1 - *min1;
    //cout << endl << *max1 << " " << *min1 << endl;
    //cout << endl;
    for(int i = 0 ; i < A.size() ; i++)
    {
       A[i] = A[i] - (2*(i+1));
       //cout << A[i] << endl;
    }

    auto max2 = max_element(A.begin(), A.end());
    auto min2 = min_element(A.begin(), A.end());

    int result2 = *max2 - *min2;

    //cout << endl << *max2 << " " << *min2 << endl;
 
    return max(result1, result2);
    
    //cout << *max1 - *min1 << " " << *max2 - *min2 << endl;
}

int main()
{
	vector<int> A = {  -98, -5, 37, -97, 38, 22, 70, 42, 61, 84  };

	cout << "Result: " << maxAbsolute(A) << endl;
	return 0;
}