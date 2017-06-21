#include <iostream>
#include <queue>

using namespace  std;

template<typename T>
struct Stack
{
	queue<T> q1;
	queue<T> q2;
};

//Method 2 : Implm making pop operation costly i.e Efficient Pop

template<typename T>
void push(Stack<T> &s,T data)
{
	s.q1.push(data);
}

template<typename T>
T pop(Stack<T> &s)
{
	if (s.q1.empty())
	{
		while(!s.q2.empty())
		{
			if (s.q2.size() == 1)
			{
				int val = s.q2.front();
				s.q2.pop();
				return val;
			}
			s.q1.push(s.q2.front());
			s.q2.pop();
		}
	}
	else
	{
		while(!s.q1.empty())
		{
			if (s.q1.size() == 1)
			{
				int val = s.q1.front();
				s.q1.pop();
				return val;
			}
			s.q2.push(s.q1.front());
			s.q1.pop();
		}
	}
}


//***************************************************************
//Asked in: Inmobi, Accolite, Adobe, 
//Amazon, DE Shaw, Flipkart, Goldman Sachs, InfoEdge, MakeMyTrip, Microsoft, Oracle
//***************************************************************

int main(int argc, char const *argv[])
{
	Stack<int> s;
	push(s,1);
	push(s,2);
	push(s,3);
	push(s,4);
	
	for (int i = 0; i < 4; ++i)
	{
		cout << "Popped Stack Elements : "<<pop(s) << "\n";
	}

	return 0;
}