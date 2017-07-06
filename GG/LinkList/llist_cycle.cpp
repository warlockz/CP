/*
 * linklist.cpp
 *
 *  Created on: 24 May 2017
 *      Author: yogeshb2
 */

#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void push(Node **headref,int data)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = data;
	new_node->next = *headref;
	*headref = new_node;
}
// Method 1
void removeLoop(Node *head,Node* slow)
{
	Node *cur1 = head;
	Node *cur2 = NULL;

	while(1)
	{
		cur2 = slow;
		while((cur2->next != slow) && (cur2->next != cur1))
		cur2 = cur2->next;

		if(cur2->next == cur1)
		break;

		cur1 = cur1->next;
	}

	cur2->next = NULL;
}

// Flyod`s Cycle Detection Algo or
// Tortoise and Hare Algo
bool isLooping(Node *head)
{
	if(head == NULL)
	{
		return false;
	}
	Node *slow = head;
	Node *fast = head;
	while((slow != NULL) && (fast != NULL) && (fast->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
		{
			//Solution 1
			 removeLoop(head,slow);
			 return true;
		}
	}

	return false;
}

//	Soluion 2 / // Method2
void detectAndRemove(Node *head)
{
	Node *slow = head;
	Node *fast = head->next;

	while(fast && fast->next)
	{
		if (slow == fast)
		{
			break;
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	if (slow == fast)
	{
		slow = head;

		while(slow != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		// since fast is looping point
		fast->next = NULL;
	}
}

void print(Node *head)
{
	cout << "Llist :- \n";
	Node *temp = head;
	while(temp != NULL)
	{
		cout << "->[" << temp->data <<"]";
		temp = temp->next;
	}
	cout << "\n";
}

int main(int argc, char **argv)
{
	Node *head = NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	print(head);
	//now making loop or cycle in LL
	head->next->next->next = head->next;
	//cout << "Is Cycle or loop in LL : " <<isLooping(head) << "\n";
	cout << "Rmove loop \n";
	detectAndRemove(head);
	print(head);

}

