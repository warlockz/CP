#include <iostream>
#include<malloc.h>

using namespace std;

struct stack
{
	int top;
	int capacity;
	char *arr;
};

stack* createstack(int capacity)
{
	stack s = (stack*)malloc(sizeof(stack)));
	s->capacity = capacity;
	s->top = -1;
	s->arr = (char*)malloc(s->capacity*sizeof(char));
}

void push(stack *topref,char data)
{
	
}

char pop(stack *topref)
{

}

void print(stack *topref)
{
	cout<< "Stack contents : \n";
	while(topref->top != -1)
	{
		cout<<topref->arr[topref->top--];
	}
}

int main()
{
	stack stk;
	
	
}