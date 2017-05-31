#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
	int data;
	Node* next;
};


void insertatfront(Node **headref,int data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->next = (*headref);
	new_node->data = data;
	(*headref) = new_node;	
}

void insertatend(Node **headref,int data)
{
	Node *temp = (*headref);

	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = data;

	if (!temp)
	{
		(*headref) = new_node;
		return; 
	}

	while(temp->next)
	{
		temp = temp->next; 
	}
	
	temp->next = new_node;
	
}

void insertafter(Node *node,int data)
{
	if (!node)
	{
		return;
	}
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->next = node->next;
	new_node->data = data;
	node->next = new_node;
}

void deleteNode(Node **headref,int key)
{
	Node *temp = *headref, *prev;

	if(temp && (temp->data == key))
	{
		(*headref) = (*headref)->next;
		free(temp);
		return;
	}

	prev = temp;
	while((temp) && (temp->data != key))
	{
		prev = temp;
		temp = temp->next;
	}

	if(!temp)
	{
		return;
	}
	prev->next = temp->next;
	free(temp);

}

void deleteNodeAt(Node **headref,int  position)
{
	Node *temp = *headref, *prev;
	int i = 0;
	if(temp && (position == 0))
	{
		(*headref) = (*headref)->next;
		free(temp);
		return;
	}	

	while((temp) && (i < (position-1)))
	{
		temp = temp->next;
	}

	if(!temp)
	{
		return;
	}
	
	prev = temp->next;
	temp->next = temp->next->next;
	free(prev);
}

int getLengthIterative(Node* head)
{
	int count = 0;

	while(head)
	{
		head = head->next;
		count++;
	}
	return count;
}

int getLengthRecursive(Node* head)
{
	int count = 0;

	if(head == NULL)
	{
		return 0;
	}

	return (1 + getLengthRecursive(head->next));
}


void swap(Node **headref,int x, int y)
{
	Node *prevX = NULL, *prevY = NULL;
	Node *curX,*curY;

	if (x == y)
	{
		return;
	}

	curX = *headref;
	while(curX && (curX->data != x))
	{
		prevX = curX;
		curX = curX->next;
	}

	curY = *headref;

	while(curY && (curY->data != y))
	{
		prevY = curY;
		curY = curY->next;
	}

	if(!curX || !curY)
	{
		return;
	}

	if(prevX)
	{
		prevX->next = curY;
	}
	else
	{
		*headref = curY;
	}

	if (prevY)
	{
		prevY->next = curX;
	}
	else
	{
		*headref = curX;
	}

	Node *temp = curY->next;
	curY->next = curX->next;
	curX->next = temp;
}

void printlist(Node *node)
{
	cout << "\n";	
	while(node)
	{
		cout <<"->["<< node->data<<"][]";
		node = node->next;
	}
	cout<<"\n";
}

/*
 Reverse()
Asked in: Accolite, Adobe, Cisco, Cognizant , 
IgniteWorld , Mahindra Comviva, Microsoft, Paytm, SAP, Snapdeal , Tejas Network, Teradata

*/
void reverse(Node **headref)
{
	Node *cur = *headref;

	Node *prev = NULL,*next = NULL;
	while(cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}

	*headref = prev;

	//Time Complexity (TC) = O (n)
	//Space Compelxity (SC) = O (1)
}

void RecursiveReverse(Node **headref)
{
	if(!*headref)
	{
		return;
	}

	Node *first = *headref;		
	Node *rest = first->next;

	if(!rest)
	{
		return;
	}

	RecursiveReverse(&rest);

	first->next->next = first;
	first->next = NULL;
	*headref = rest;

	//Time Complexity (TC) = O (n)
	//Space Compelxity (SC) = O (1)
}

// Below : Tail Recursive method

void TailRecReverse(Node *cur, Node *prev, Node **head)
{

	if(!cur->next)
	{
		*head = cur;
		cur->next = prev;
		return;
	}

	Node *next = cur->next;
	cur->next = prev;

	TailRecReverse(next,cur,head);
}

void RecursiveReverseMethodTail(Node **headref)
{
	if(!headref)
	{
		return;
	}
	TailRecReverse(*headref,NULL,headref);
}

//TODO :-
// http://www.geeksforgeeks.org/iteratively-reverse-a-linked-list-using-only-2-pointers/


// Asked in: Adobe, Microsoft, Paytm, Snapdeal
Node* ReverseIntoGroups(Node *head,int k)
{
	Node *cur = head, *prev = NULL, *next = NULL;
	int count = 0;

	while(cur && (count < k))
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
		count++;
	}

	if(next != NULL)
	{
		head->next = ReverseIntoGroups(next,k);
	}

	return prev;
	//Time Complexity: O(n)
}


int main(int argc, char const *argv[])
{
	Node* head = NULL;
	insertatfront(&head,5);
	printlist(head);
	insertatfront(&head,3);
	printlist(head);
	insertatend(&head,4);
	printlist(head);
	insertafter(head->next,1);
	printlist(head);
	insertatend(&head,7);
	insertatend(&head,9);
	printlist(head);
	deleteNode(&head,3);
	printlist(head);
	deleteNodeAt(&head,1);
	printlist(head);
	deleteNodeAt(&head,0);
	printlist(head);
	insertatfront(&head,2);
	insertatfront(&head,1);
	printlist(head);
	cout << "Length Iterative : " << getLengthIterative(head) << "\n";
	cout << "Length Recursive : " << getLengthRecursive(head) << "\n";
	printlist(head);
	swap(&head,1,9);
	printlist(head);
	swap(&head,7,4);
	printlist(head);
	reverse(&head);
	printlist(head);
	RecursiveReverse(&head);
	printlist(head);
	RecursiveReverseMethodTail(&head);
	printlist(head);
	head = ReverseIntoGroups(head,3);
	printlist(head);
	return 0;
}