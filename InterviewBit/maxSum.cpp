#include<bits/stdc++.h>

using namespace std;

int maxSum(vector<int> a)
{
	//int size = sizeof(a)/sizeof(a[0]);
	int sum = a[0];
	int maximum = a[0];
	//cout << "size: " << size << endl;
	//int curr_sum = 0;

	for(int i = 1 ; i < a.size() ; i++)
	{
		
		sum = max(a[i]+sum, a[i]);
		cout << "sum: " << sum << endl;

		maximum = max(sum, maximum);
		cout << "maximum: " << maximum << endl;
	}

	return maximum;	
}

int main()
{
	vector<int> a = { -2, 1, -3, 4, -1, 2, 1,-5, 4};

	cout << "Max:" << maxSum(a) << endl;
	//int size = sizeof(a)/sizeof(a[0]);
	//cout << "size: " << size << endl;

	return 0;
}