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


template<typename T>
void enQueue(Queue<T> &q,int data)
{
	q.s1.push(data);
}

template<typename T>
int deQueue(Queue<T> &q)
{
	if((q.s1.empty()) && (q.s2.empty()))
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
	//cout << " Q s1 Size :"<<q->s1.size() << "\n";
	//q->s2.push(10);
	//q->s2.push(11);
	

	//cout << " Q s2 Size :"<<q->s2.size() << "\n";
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