/*
 * chk_balanced_parenthesis_stack.cpp
 *
 *  Created on: 6 Jun 2017
 *      Author: yogeshb2
 */

#include <iostream>
#include <malloc.h>

using namespace std;

struct sNode
{
	char data;
	struct sNode* next;
};

void push(sNode **topref,char data)
{
	sNode *newelement = (sNode *)malloc(sizeof(sNode));
	if(newelement == NULL)
	{
		cout << "Stack Overflow \n";
	}
	newelement->data = data;
	newelement->next = (*topref);
	(*topref) = newelement;
}

char pop(sNode **topref)
{
	sNode *temp = (*topref);
	char data;
	if(temp == NULL)
	{
		cout << "Stack Underflow \n";
		return data;
	}
	data = temp->data;
	(*topref) = temp->next;
	//delete temp; since memory allocated with malloc
	free(temp);
	return data;
}

void printStack(sNode *top)
{
	while(top != NULL)
	{
		cout << top->data <<"#";
		top = top->next;
	}
	cout<< "\n";
}

bool isMatching(char data1,char data2)
{
	bool result = false;
	if((data1 == '(') && (data2 == ')'))
	{
		result = true;
	}
	else if((data1 == '[') && (data2 == ']'))
	{
		result = true;
	}
	else if((data1 == '{') && (data2 == '}'))
	{
		result = true;
	}
	return result;
}

bool isParenthesisBalanced(char exp[])
{
	int i = 0;
	sNode *top = NULL;
	while(exp[i])
	{
		if((exp[i] == '(') || (exp[i] == '[') || (exp[i] == '{'))
		{
			push(&top,exp[i]);
			printStack(top);
		}
		else if((exp[i] == ')') || (exp[i] == ']') || (exp[i] == '}'))
		{
			if(top == NULL)
			{
				return 0;
			}
			else if(!isMatching(pop(&top),exp[i]))
			{
				return 0;
			}
		}
		i++;
	}

	if(top == NULL)
	{
		return 1;
	}

	return 0;
}

int main(int argc, char **argv)
{
	char arr[100] = "[{()}]";
	if(isParenthesisBalanced(arr))
	{
		cout << "Balanced experssion \n";
	}
	else
	{
		cout << "Not Balanced experssion \n";
	}

}




