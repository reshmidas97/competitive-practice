/*

QUESTION:

https://www.interviewbit.com/problems/add-one-to-number/

*/

#include<bits/stdc++.h>

using namespace std;

vector<int> add(vector<int> &A)
{
	vector<int> B;
	vector<int> :: iterator j;
	int index = 0;

	A[A.size()-1] += 1;
	for(int i = A.size()-1 ; i > 0 ; i--)
	{
		if(A[i] / 10)
		{
			A[i-1] +=1;
			A[i] %= 10;
		}
	}

	for(j = A.begin() ; j != A.end() ; j++)
	{
		if(*j != 0)
		{
			B.assign(j, A.end());
			break;
		}
	}

	if(B[0] / 10)
	{
		B.insert(B.begin(), (B[0] / 10));
		B[1] = B[1] % 10;
	}
	return B;

}

int main()
{
	vector<int> A = {0, 9, 9, 9};

	vector<int> B = add(A);

	for(int i = 0 ; i < B.size() ; i++)
	{
		cout << B[i];
	}
	cout << endl;

	return 0;
}