#include<bits/stdc++.h>

using namespace std;

/* https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/

Given an expression string exp, write a program to examine whether the pairs 
and the orders of “{“, “}”, “(“, “)”, “[“, “]” are correct in exp.
*/

bool checkParenthesis(string str)
{
	stack<int> s;

	for(int i = 0; i < str.length() ; i++)
	{
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
		{
			s.push(str[i]);
			continue;
		}
		if(str[i] == ')')
		{
			if(s.top() == '(')
			{	
				s.pop();
				continue;
			}
		}
		else if(str[i] == ']')
		{
			if(s.top() == '[')
			{	
				s.pop();
				continue;
			}
		}
		else if(str[i] == '}')
		{
			if(s.top() == '{')
			{	
				s.pop();
				continue;
			}
		}
		cout << "Not balanced" << endl;
		exit(0);
	}
	if(!s.empty())
		return false;
	else
		return true;
}
int main()
{
	string str;
	cin >> str;

	if(checkParenthesis(str))
		cout << "Balanced" << endl;
	else
		cout << "Not Balanced" << endl;
	return 0;

}