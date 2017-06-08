#include <iostream>

using namespace std;

class TwoStacks
{
	int *arr;
	int size;
	int top1,top2;
public:
	TwoStacks(int n)
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = n;
	}
	~TwoStacks()
	{}

	void push1(int x)
	{
		// atlast one empty position for new element
		if(top1 < (top2 - 1))
		{
			arr[++top1] = x;
		}
		else
		{
			cout << "Stack Overflow \n";
		}
	}
	
	void push2(int x)
	{
		// atlast one empty position for new element
		if(top1 < (top2 - 1))
		{
			arr[--top2] = x;
		}
		else
		{
			cout << "Stack Overflow \n";
		}
	}

	int pop1()
	{
		if (top1 >= 0)
		{
			return arr[top1--];	
		}
		else
		{
			cout << "Stack Underflow \n";
		}
		return -1;
	}

	int pop2()
	{
		if (top2 < size)
		{
			return arr[top2++];	
		}
		else
		{
			cout << "Stack Underflow \n";
		}
		return -1;
	}

};

int main(int argc, char const *argv[])
{
	TwoStacks ts(10);
	ts.push1(1);
	ts.push1(2);
	ts.push1(3);
	cout << "Pop element from stack1 : "<< ts.pop1() << "\n";
	ts.push2(9);
	ts.push2(8);
	ts.push2(7);
	cout << "Pop element from stack2 : "<< ts.pop2() << "\n";


	return 0;
}