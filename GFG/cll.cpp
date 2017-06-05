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

// V.IMP ***Tricky Asked in: Amazon, Microsoft
void SortedInsert(Node **headref,int data)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = NULL;

	if(*headref == NULL)     // if list empty
	{
		*headref = new_node;
		new_node->next = new_node;
	}
	else if((*headref)->data > data) // if head node 
	{
		new_node->next = (*headref);
		Node *temp = (*headref);
		while(temp->next != (*headref))
		{
			temp = temp->next;
		}
		temp->next = new_node;
		(*headref) = new_node;
	} 
	else // other than head node
	{
		Node *temp = (*headref);
		while((temp->next != (*headref)) && (temp->next->data < data))
		{
			temp = temp->next;
		}
		new_node->next = temp->next;
		temp->next = new_node;
	}
	// Time Complexity = O(n)
}

int main(int argc, char **argv)
{
	Node *head = NULL;
	Node *head1 = NULL,*head2 = NULL;
	insertatend(&head,1);
	insertatend(&head,2);
	insertatend(&head,4);
	insertatend(&head,5);
	insertatend(&head,7);
	print(head);
	//splitlist(head,&head1,&head2);
	//print(head1);
	//print(head2);
	SortedInsert(&head,3);
	print(head);
	SortedInsert(&head,0);
	print(head);
	SortedInsert(&head,8);
	print(head);

	Node *s1 = NULL;
	SortedInsert(&s1,100);
	SortedInsert(&s1,101);
	print(s1);	
}


