/*
 * stk.cpp
 *
 *  Created on: 30 May 2017
 *      Author: yogeshb2
 */

#include <iostream>

#define MAX 100
using namespace std;

class stack
{

	public:
	stack():top(-1)
	{

	}
	void push(int data);
	int pop()
	{
		if(top < 0)
		{
			cout << "Stack Underflow" << "\n";
			return -1;
		}
		else
		{
			return arr[top--];
		}
	}
	int peek()
	{
		if(top < 0)
		{
			cout << "Stack Underflow" << "\n";
			return -1;
		}
		else
		{
			return arr[top];
		}
	}
	bool isEmpty()
	{
		return (top < 0);
	}
	void print()
	{
		int i = 0;
		while(i <= top)
		{
			cout << "#" <<arr[i++];
		}
		cout<<"\n";
	}
	private :
	int arr[MAX];
	int top;
};

void stack::push(int data)
{
	if(top >= MAX)
	{
		cout << "Stack Overflow" << "\n";
	}
	else
	{
		arr[++top] = data;
	}
}


int main(int argc, char **argv)
{
	stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.print();
	int val = s.pop();
	cout << "val : "<<val;
}



