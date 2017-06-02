/*
 * dll.cpp
 *
 *  Created on: 1 Jun 2017
 *      Author: yogeshb2
 */

#include <iostream>
#include <malloc.h>
using namespace std;

struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
	void SetNode(int d,Node *p,Node *n)
	{
		data = d;
		prev  = p;
		next = n;
	}
};

void insertatfront(Node **headref,int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	if(*headref != NULL)
	{
		new_node->SetNode(data,(*headref)->prev,(*headref));
		(*headref)->prev = new_node;
	}
	else
	{
		new_node->SetNode(data,NULL,NULL);
	}
	*headref = new_node;
}

void insertatend(Node **headref, int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	Node *temp = *headref;
	if(temp == NULL)
	{
		new_node->SetNode(data,NULL,NULL);
		*headref = new_node;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		new_node->SetNode(data,temp,NULL);
		temp->next = new_node;
	}
}

void insertafter(Node *prevnode, int data)
{
	if(prevnode == NULL)
	{
		return;
	}
	else
	{
		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->SetNode(data,prevnode,prevnode->next);
		prevnode->next->prev = new_node;
		prevnode->next = new_node;
	}

}

void deleteNode(Node **headref,Node *del)
{
	if(*headref == NULL || del == NULL)
	return;

	if(*headref == del)
	{
		(*headref) = (*headref)->next;
		(*headref)->prev = NULL;
	}
	else
	{
		if(del->prev)
		del->prev->next = del->next;

		if(del->next)
		del->next->prev = del->prev;
	}
	free(del);
}


void print(Node *head)
{
	cout << "In fwd direction :- \n";
	Node *prev = head;
	while(head != NULL)
	{
		cout << "<=>[" << head->data << "]";
		prev = head;
		head = head->next;
	}
	cout << "\n In rev direction :- \n";
	while(prev != NULL)
	{
		cout << "[" << prev->data << "]<=>";
		prev = prev->prev;
	}
	cout <<"\n";
}

// Hint to reverse DLL : swap prev and next pointers hehe :)
void reverse(Node **headref)
{
	Node *head = *headref;
	Node *temp = NULL;

	while(head != NULL)
	{
		temp = head->prev;
		head->prev = head->next;
		head->next = temp;
		head = head->prev;
	}	
	if(temp != NULL)
	{
		*headref = temp->prev;
	}
}

int main(int argc, char **argv)
{
	Node *head = NULL;
	insertatfront(&head,3);
	insertatend(&head,2);
	insertatfront(&head,1);
	insertatend(&head,5);
	insertafter(head->next->next,4);
	insertafter(head,9);
	print(head);
	deleteNode(&head,head);
	print(head);
	deleteNode(&head,head->next->next);
	print(head);
	reverse(&head);
	print(head);
}
