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

// * Asked in : Yahoo
void SplitList(Node *head, Node **head1, Node **head2)
{
	Node *slow = head;
	Node *fast = head;
	// //Use Tortoise and Hare Algo a bit different implm than SLL and DLL
	// fast->next if points to head then it is odd link list
	// fast->net->next if points to head then it is even link list
	// then slow will be mid point of the list
	while((fast->next != head) && (fast->next->next !=head))
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	//if it is even list
	if(fast->next->next == head)
	{
		fast = fast->next;
	}

	*head1 = head;

	//if list doesnt contain only 1 node
	if(head->next != head)
	{
		*head2 = slow->next;
	}
	//making 2nd half circular
	fast->next = slow->next; //since head2 can be NULL if one node in list
	//makin 1st hhalf circular
	slow->next = head;
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
	SplitList(head,&head1,&head2);
	print(head1);
	print(head2);
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


