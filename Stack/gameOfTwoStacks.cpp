#include<bits/stdc++.h>

using namespace std;

/* 
https://www.hackerrank.com/challenges/game-of-two-stacks/problem

Approach 1: 
		Time complexity : O(n)
		Auxilary space :O(1)
*/

int calculateScore(vector<int> a, vector<int> b, int score)
{
	int count = 0, j = 0, i;
	long int sum = 0;

	/*
	Sums of all numbers in Stack 1 having sum less than or
	equal to the score. Hence, setting a bar below which the 
	the sum of numbers will be greater than score.
	*/
	for(i = 0 ; (sum + a[i]) <= score && i < a.size() ; i++)
		sum += a[i];

	//Keeping count of numbers the sum consists so far.
	count = i;

	while(j < b.size())
	{
		//Adding elements of Stack 2 to the sum
		sum += b[j++];

		/*
		Adding elements of Stack 2 in the above line and seeing
		 if the sum exceeds the score then removing elements of Stack A
		 */
		while(sum > score && i >= 0)
			sum -= a[--i];

		/*
		Checking sum of elements in less than or equal to score 
		and keeping the count of element max
		*/
		if(sum <= score && count < i + j)
			count = i + j;

		/*
		When Stack 1 is empty and sum consists of elements
		 of B only and the sum is greater than score, break the 
		 loop because we have found the count already.
		 */
		if(sum > score && i <= 0)
			break;
	}
	return count;
}

int main()
{
	int a_size, b_size, score, temp;

	cout << "Size of Stack 1: " << endl;
	cin >> a_size;

	vector<int> a;

	cout << "Enter elements in Stack 1" << endl;
	for(int i = 0 ; i < a_size ; i++)
	{	
		cin >> temp;
		a.push_back(temp);
	}

	cout << "Size of Stack 2: " << endl;
	cin >> b_size;

	vector<int> b;

	cout << "Enter elements in Stack 2" << endl;
	for(int i = 0 ; i < b_size ; i++)
	{
		cin >> temp;
		b.push_back(temp);
	}

	cout << "Enter total score: " << endl;
	cin >> score;

	cout << "Score: " << calculateScore(a, b, score) << endl;
	return 0;

}