#include <iostream>
#include <stack>

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
	temp->left = temp->right = NULL;
	return temp;
}

void inorder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
}

int main(int argc, char const *argv[])
{
	
	return 0;
}