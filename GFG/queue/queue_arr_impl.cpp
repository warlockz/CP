/*
 * queue_impl.cpp
 *
 *  Created on: 14 Jun 2017
 *      Author: yogeshb2
 */
#include <iostream>
#include <malloc.h>

using namespace std;

struct Queue
{
	int front,rear;
	int size,capacity;
	int *arr;
};

Queue* createQueue(int capacity)
{
	Queue* temp = (Queue*)malloc(sizeof(Queue));
	temp->arr = (int*)malloc(capacity * sizeof(int));
	temp->front = temp->size = 0;
	temp->capacity = capacity;
	temp->rear = capacity - 1;
	return temp;
}

bool isEmpty(Queue* Q)
{
	return (Q->size == 0);
}

bool isFull(Queue* Q)
{
	return (Q->size == Q->capacity);
}

void enQueue(Queue* Q,int item)
{
	if(isFull(Q))
	{
		cout << "Q is full";
		return;
	}
	Q->rear = (Q->rear + 1)%(Q->capacity);
	Q->arr[Q->rear] = item;
	Q->size += 1;
}

int deQueue(Queue *Q)
{
	if(isEmpty(Q))
	{
		cout << "Q is Empty\n";
		return -1;
	}
	int temp = Q->arr[Q->front];
	Q->front = (Q->front + 1)%(Q->capacity);
	Q->size -= 1;
	return temp;
}

void printQ(Queue* Q)
{
	cout << "Q Elemnets  :\n";
	for(int i = Q->front; i <= Q->rear ; i++)
	{
		cout <<"[" << Q->arr[i] <<"]";
	}
}

int main(int argc, char **argv)
{
	Queue* que = NULL;
	que = createQueue(10);
	enQueue(que,1);
	enQueue(que,2);
	enQueue(que,3);
	enQueue(que,4);
	printQ(que);
	int temp = deQueue(que);
	cout << "\nDeQueue Elemnt :=" << temp <<"\n";
	printQ(que);
}


