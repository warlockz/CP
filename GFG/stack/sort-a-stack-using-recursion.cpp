#include <iostream>
#include <stack>

using namespace std;

ostream& operator<<(ostream& print,stack<int> s)
{
	while(!s.empty())
	{
		print<<s.top();
		s.pop();
	}
	cout<<"\n";
	return print;	
}

//5 0 1 7
//7
///7 1

//5 4 6 1
//1
//6
//6 1

void SortedInsert(stack<int>& s,int item)
{
	if(s.empty() ||(item > s.top()))
	{
		s.push(item);
	}
	else
	{
		int temp = s.top();
		s.pop();
		SortedInsert(s,item);
		s.push(temp);
	}
}

void SortStack(stack<int>& s)
{
	if(!s.empty())
	{
		int temp = s.top();
		s.pop();
		SortStack(s);
		SortedInsert(s,temp);
	}
}

int main(int argc, char const *argv[])
{
	stack<int> s;
	s.push(5);
	s.push(1);
	s.push(4);
	s.push(9);
	s.push(0);
	cout<<s;
	SortStack(s);
	cout<<s;
	return 0;
}