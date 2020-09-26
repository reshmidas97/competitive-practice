#include<bits/stdc++.h>

using namespace std;

/*
Given is a bag of balls of different colors. There are two baskets
in which we have to arrange the balls in such a manner that the baskets
have only balls of one color. But once you pick the first ball, you will 
have to continuously pick the balls, cannot skip over thus maximizing the 
total number of balls in both the bags.
*/

/*
Explaination of the Example:
Balls in the Bag : red, red, green, green, blue, blue, red, blue, red

Output: 5
3 Blue balls in one basket, 2 red balls in another basket
*/

int solve(vector<string> v)
{
	int latter = 0,  max = 0, count = 1, initial = 0;;
	string str1 = v[0], str2 = "";

	for(int i = 1 ; i < v.size() ; i++)
	{
		if(v[i] != str1 && v[i] != str2)
			{
				str2 = v[initial];
				str1 = v[i];
				latter = initial;
				initial = i;
			}
				count = i - latter + 1;
		
	if(max < count)
		max = count;
	}
	return max;
}

int main()
{
	vector<string> v;
	v.push_back("red");
	v.push_back("red");
	v.push_back("green");
	v.push_back("green");
	v.push_back("blue");
	v.push_back("blue");
	v.push_back("red");
	v.push_back("blue");
	v.push_back("red");

	cout << "Result: " << solve(v) << endl;
	return 0;
}