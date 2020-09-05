#include<bits/stdc++.h>

using namespace std;

/*
https://www.geeksforgeeks.org/interesting-method-generate-binary-numbers-1-n/

Generate Binary Numbers from 1 to n:

Given a number n, write a function that generates and prints all 
binary numbers with decimal values from 1 to n.
*/

void generateBinarynumbers(int n)
{
	string s1, s2;
	queue<string> q;

	q.push("1");

	while(n--)
	{
		s1 = q.front();
		cout << s1 << endl;
		q.pop();

		s2 = s1;

		q.push(s1.append("0"));

		q.push(s2.append("1"));
	}
}

int main()
{
	int n;
	cout << "Enter number till where you want to print binary numbers: " << endl;
	cin >> n;

	generateBinarynumbers(n);

	return 0;
}