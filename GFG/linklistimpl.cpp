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


/*
Asked in: Amazon, Belzabar, Brocade, 
Factset, Flipkart, Microsoft, OATS Systems, Oracle, Samsung, Synopsys
*/
// solution 1
Node* MergeList(Node *head1, Node *head2)
{
	Node *dummy = (Node*)malloc(sizeof(Node));
	dummy->next = NULL;
	Node *temp = dummy;

	while(head1 != NULL && head2 != NULL)
	{
		if(head1->data < head2->data)
		{
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;	
		}
		else
		{
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}
	}

	if (head1 == NULL)
	{
		temp->next = head2;
	}

	if (head2 == NULL)
	{
		temp->next = head1;
	}

	temp = dummy->next;
	free(dummy);
	return temp;

	//Time Complexity  : O(n + m);
}

// Solution 2 : without creating dummy node;
// Using Local References

void MoveNode(Node **destref, Node **srcref)
{
	Node *new_node = *srcref;
	(*srcref) = (*srcref)->next;
	new_node->next = (*destref);
	(*destref) = new_node;
}

Node* SortedMerge(Node *a, Node *b)
{
	Node *result = NULL;
	Node **lastref = &result;

	while((a != NULL) && (b != NULL))
	{
		if(a->data < b->data)
		{
			MoveNode(lastref,&a);
		}
		else
		{
			MoveNode(lastref,&b);
		}			
		lastref = &((*lastref)->next);
	}

	if(a == NULL)
	{
		*lastref = b;
	}
	if(b == NULL)
	{
		*lastref = a;
	}

	return result;
}

// Recursive Merge solution
Node* SortedMergeRec(Node *h1, Node *h2)
{
	Node *result = NULL;

	if(h1 == NULL)
	{
		return h2;
	}

	if(h2 == NULL)
	{
		return h1;
	}

	if(h1->data < h2->data)
	{
		result = h1;
		result->next = SortedMergeRec(h1->next,h2);
	}
	else
	{
		result = h2;
		result->next = SortedMergeRec(h1,h2->next);
	}
	// Time Complexity : O(n + m) utimately := O(z)
	// Space Complexity : O(1) ?
	return result;
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

	Node* head1 = NULL;
	insertatend(&head1,1);
	insertatend(&head1,3);
	insertatend(&head1,5);
	insertatend(&head1,9);
	printlist(head1);

	Node* head2 = NULL;
	insertatend(&head2,0);
	insertatend(&head2,1);
	insertatend(&head2,6);
	insertatend(&head2,7);
	printlist(head2);

	Node *result = MergeList(head1,head2);
	printlist(result);

	Node *a = NULL;
	insertatend(&a,0);
	insertatend(&a,1);
	insertatend(&a,2);
	insertatend(&a,9);
	printlist(a);

	Node *b = NULL;
	insertatend(&b,1);
	insertatend(&b,3);
	insertatend(&b,4);
	insertatend(&b,5);
	printlist(b);

	result = SortedMerge(a,b);
	printlist(result);

	Node *h1 = NULL;
	insertatend(&h1,6);
	insertatend(&h1,5);
	insertatend(&h1,2);
	insertatend(&h1,1);
	printlist(h1);
	Node *h2 = NULL;
	insertatend(&h2,4);
	insertatend(&h2,3);
	insertatend(&h2,2);
	insertatend(&h2,0);
	printlist(h2);

	Node *res = SortedMergeRec(h1,h2);
	printlist(res);

	return 0;
}