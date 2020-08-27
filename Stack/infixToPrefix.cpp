#include<bits/stdc++.h>

using namespace std;

/*
Question: geeksforgeeks.org/stack-set-2-infix-to-postfix/
Video : https://www.youtube.com/watch?v=vq-nUF0G4fI

Infix to Postfix Conversion
*/
	
bool isOperand(char ch)
{
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	return false;
}

int checkPrecedence(char ch)
{
	if(ch == '^')
		return 3;

	else if((ch == '*') || (ch == '/'))
		return 2;

	else if((ch == '+') || (ch == '-'))
		return 1;

	else
	{
		cout <<"Invalid Operator Entered" << endl;
		exit(0);
	}
}

string infixToPostfix(string s)
{
	string new_s;
	stack<char> operators;

	for(int i = 0 ; i < s.length() ; i++)
	{
		if(isOperand(s[i]))
		{
			new_s += s[i];
			continue;
		}
		
		if(operators.empty())
			operators.push(s[i]);
		else
		{
			if(checkPrecedence(s[i]) > checkPrecedence(operators.top()))
				operators.push(s[i]);
			else
			{	while((!operators.empty()) && (checkPrecedence(s[i]) <= checkPrecedence( operators.top() ) ) ) 
				{
					new_s += operators.top();
					operators.pop();
				}
				operators.push(s[i]);
			}
		}
	}
	while(!operators.empty())
	{
		new_s += operators.top();
		operators.pop();
	}
	
	return new_s;
}

int main()
{
	string str;
	cin >> str;
	cout << "Infix Expression: " << str << endl;
	cout << "Postfix Expression: " << infixToPostfix(str) << endl;
	return 0;

}