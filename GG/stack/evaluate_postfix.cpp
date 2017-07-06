#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


int evaluatePostfixExp(char exp[])
{
	int i = 0;
	stack<int> stk;
	while(exp[i] != '\0')
	{
		if(isdigit(exp[i]))
		{
			stk.push((int)(exp[i] - '0'));
		}
		else
		{
			int val1 = stk.top();
			stk.pop();
			int val2 = stk.top();
			stk.pop();
			switch(exp[i])
			{
				case '+':
				stk.push(val2 + val1);
				break;
				case '*':
				stk.push(val2 * val1);
				break;
				case '-':
				stk.push(val2 - val1);
				break;
				case '/':
				stk.push(val2 / val1);
				break;
			}
		}
		i++;
	}
	return stk.top();

	// Time Complexity : O(n) where n is no. of characters in exp
}

int main(int argc, char const *argv[])
{
	char exp[] = "231*+9-";
	cout << "Evaluate Postfix Value : "<< evaluatePostfixExp(exp) << "\n";
	return 0;
}