#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
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

void printlist(Node *node)
{
	while(node)
	{
		cout <<"->["<< node->data<<"][]";
		node = node->next;
	}
	cout<<"\n";
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

	return 0;
}