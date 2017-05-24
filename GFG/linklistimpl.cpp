#include <iostream>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};


void insertatfront(Node **headref,int data)
{
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->next = (*headref):
	new_node->data = data;
	(*headref) = new_node;	
}

void insertatend()
{
	
}

void insertafter()
{
	
}

void printlist(Node *headref)
{
	cout<<headref;
	while(headref)
	{
		cout << headref->data;
		headref = headref->next;
	}
	cout<<headref;
}



int main(int argc, char const *argv[])
{
	Node* head = NULL;
	insertatfront(&head,5);
	cout<<head;
	printlist(head);
	cout<<head;
	insertatfront(&head,3);
	printlist(head);
	return 0;
}