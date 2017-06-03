/*
 * cll.cpp
 *
 *  Created on: 2 Jun 2017
 *      Author: yogeshb2
 */
#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
	int data;
	struct Node *next;
};

void insertatend(Node **headref,int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;

	if(*headref == NULL)
	{
		new_node->next = new_node;
		*headref = new_node;
	}
	else
	{
		Node *temp = *headref;
		while(temp->next != (*headref))
		{
			temp = temp->next;
		}
		new_node->next = *headref;
		temp->next = new_node;
	}
}

void print(Node *head)
{
	Node *first = head;
	while(head != NULL)
	{
		cout << "->[" << head->data << "]";
		head = head->next;
		if(first == head)
		{
			break;
		}
	}
	cout << "\n";
}

void splitlist(Node *head, Node **headref1, Node **headref2)
{
	//Use Tortoise and Hare Algo a bit different than SLL and DLL

	// TODO
}

int main(int argc, char **argv)
{
	Node *head = NULL;
	Node *head1,*head2;
	insertatend(&head,1);
	insertatend(&head,2);
	insertatend(&head,3);
	insertatend(&head,4);
	insertatend(&head,5);
	print(head);
	splitlist(head,&head1,&head2);
	print(head1);
	print(head2);
}


