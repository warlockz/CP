#include <iostream>
#include <malloc.h>
#include <string.h>

using namespace std;

struct Stack
{
	int top;
	int *arr;
};

Stack* createStack(int capacity)
{
	Stack *s1 = (Stack*)malloc((sizeof(Stack)));
	s1->top = -1;
	s1->arr = (int*)malloc(capacity*sizeof(int));
	return s1;
}

bool isEmpty(Stack *s)
{
	return (s->top == -1);
}

void push(Stack *stk,char op)
{
	stk->arr[++stk->top] = op;
}

char pop(Stack *stk)
{
	if(!isEmpty(stk))
	return stk->arr[stk->top--];
	return '$';
}

char peek(Stack *stk)
{
	return stk->arr[stk->top];
}

bool isOperand(char operand)
{
	return (((operand >= 'a') && (operand <= 'z')) || ((operand >= 'A') && (operand <= 'Z')));
}

int PrecedenceVal(char op)
{
	switch(op)
	{
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
	}
	return -1;
}

void infixtoposfix(char *exp)
{
	int i,k;
	Stack *stk = createStack(strlen(exp));
	
	for (i = 0,k = -1; exp[i] != '\0' ; ++i)
	{
		if (isOperand(exp[i]))
		{
			exp[++k] = exp[i];
		}
		else if(exp[i] == '(')
		{
			push(stk,exp[i]);
		}
		else if(exp[i] == ')')
		{
			while(!isEmpty(stk) && (peek(stk) != '('))
			{
				exp[++k] = pop(stk);
			}
			//now remove the ( frm stack without any output

			if(!isEmpty(stk) && (peek(stk) != '('))
			return; // invalid exp
			else
			pop(stk);
		}
		else
		{
			while(!isEmpty(stk) && (PrecedenceVal(exp[i]) <= PrecedenceVal(peek(stk))))
			{
				exp[++k] = pop(stk);
			}
			push(stk,exp[i]);
		}
	}
	while(!isEmpty(stk))
		exp[++k] = pop(stk);

	exp[++k] = '\0';
	cout << "Infix to Postfix exp : " << exp << "\n";
}

int main(int argc, char const *argv[])
{
	char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
	infixtoposfix(exp);
	return 0;
}