#include <iostream>
#include <stack>
#include <malloc.h>
using namespace std;

template<typename T>
struct Queue
{
	stack<T> s1;
	stack<T> s2;
};


void enQueue(Queue<int> q,int data)
{
	cout << "Data : "<<data << "\n";
	q.s1.push(data);
	cout << "Size :"<<q.s1.size();
}

int deQueue(Queue<int> q)
{
	if(q.s1.empty() &&  q.s2.empty())
	return -1;
	
	if(q.s2.empty())
	{
		while(!q.s1.empty())
		{
			q.s2.push(q.s1.top());
			q.s1.pop();
		}
	}
	int val = q.s2.top();
	q.s2.pop();
	return val;
}

int main(int argc, char const *argv[])
{
	//Queue<int> *q = (Queue<int> *)malloc(sizeof(Queue<int>));
	Queue<int> q;
	enQueue(q,1);
	enQueue(q,2);
	enQueue(q,3);
	enQueue(q,4);

	for (int i = 0; i < 4; ++i)
	{
		cout << "Deque Elements : "<<deQueue(q) << "\n";
	}

	return 0;
}