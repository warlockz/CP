/*
 * rev_stk_using_recursion.cpp
 *
 *  Created on: 8 Jun 2017
 *      Author: yogeshb2
 */

#include <iostream>
#include <stack>

using namespace std;

ostream& operator<<(ostream& os,stack<int> s)
{
	os<<"\n";
	while(!s.empty())
	{
		os<<s.top()<<")";
		s.pop();
	}
	os<<"\n";
	return os;
}

void pushatbottom(stack<int>& s,int item)
{
	if(s.empty())
	{
		s.push(item);
	}
	else
	{
		int itm = s.top();
		s.pop();
		pushatbottom(s,item);
		s.push(itm);
	}
}

void ReverseStack(stack<int>& s)
{
	if(!s.empty())
	{
		int temp = s.top();
		s.pop();
		ReverseStack(s);
		pushatbottom(s,temp);
	}
}

int main(int argc, char **argv)
{
	stack<int> stk;
	stk.push(4);
	stk.push(3);
	stk.push(2);
	stk.push(1);
	cout<<stk;
	cout<< "Reversing Stack ...:";
	ReverseStack(stk);
	cout<<stk;
}
