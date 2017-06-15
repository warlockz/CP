#include <iostream>
#include <malloc.h>

using namespace std;

struct Node
{
	int key;
	Node *next;
};

struct Queue
{
	Node *front;
	Node *rear;
};

Queue* createQ()
{
	Queue *Q = (Queue*)malloc(sizeof(Queue));
	Q->front = Q->rear = NULL;
	return Q;
}

Node* newNode(int data)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->key = data;
	temp->next = NULL;
	return temp;
}

void enQueue(Queue *q,int k)
{
	Node *newnode = newNode(k);
	if(q->rear == NULL)
	{
	 	q->rear = q->front = newnode;
	 	return;
	} 

	q->rear->next = newnode;
	q->rear = newnode;

}

Node* deQueue(Queue *q)
{
	if (q->front == NULL)
	{
		return NULL;
	}
	Node *temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
	{
		q->rear = NULL;
	}

	return temp;
}

void printQ(Queue *q)
{
	cout << "\n";
	Node *temp = q->front;
	for (;temp != NULL ; temp = temp->next)
	{
		cout << "[" << temp->key << "] ";
	}
	cout << "\n";
}

// Asked in Amazon , Oracle, Samsumg
//Time Cplexityis O(1)

int main(int argc, char const *argv[])
{
	Queue *Q = createQ();
	enQueue(Q,1);
	enQueue(Q,2);
	enQueue(Q,3);
	enQueue(Q,4);
	printQ(Q);
	Node *temp = deQueue(Q);
	cout << "deQueue element = "<<temp->key << "\n";
	printQ(Q);
	return 0;
}