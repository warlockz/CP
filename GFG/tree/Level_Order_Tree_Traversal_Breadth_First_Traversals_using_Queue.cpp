#include <iostream>
#include <queue>
#include <malloc.h>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node* newNode(int data)
{
	Node *temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printLevelOrder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node *temp = q.front();
		cout <<temp->data << " ";
		q.pop();

		if (temp->left != NULL)
		{
			q.push(temp->left);
		}
		if (temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}

/*****************************************************************************8
Asked in: Amazon, Cisco, DE Shaw, Flipkart, Microsoft, Payu

//Time Complexity: O(n) where n is number of nodes in the binary tree

*****************************************************************************/

int main(int argc, char const *argv[])
{
	Node *tree = newNode(1);
	tree->left = newNode(2);
	tree->right = newNode(3);
	tree->left->left = newNode(4);
	tree->left->right  = newNode(5);
	cout << "Level Order Traversals : \n : ";
	printLevelOrder(tree);
	return 0;
}