#include<bits/stdc++.h>

using namespace std;


int minSteps(vector<int> &A, vector<int> &B) 
{
	int sum = 0;
	for(int i = 0 ; i < A.size()-1 ; i++)
	{
		sum += max(abs(A[i] - A[i+1]), abs(B[i] - B[i+1]));
		cout << "Sum: " << sum << endl;
	}
	return sum;
}


int main()
{
	vector<int> A = {0, -3, -3};
 	vector<int> B = {0, 3, -3};

 	cout << "Minimum Steps: " << minSteps(A, B) << endl;

	return 0;
}