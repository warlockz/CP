#include <iostream>
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

int height(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int lht = height(root->left);
		int rht = height(root->right);

		if(lht > rht)
			return (lht + 1);
		else
			return (rht + 1);
	}
}

void printLevel(Node *root,int level)
{
	if (root == NULL)
	{
		return ;
	}

	if (level == 1)
	{
		cout << root->data << " ";
	}
	else if (level > 1)
	{
		printLevel(root->left,level-1);
		printLevel(root->right,level-1);	
	}
}

void printLevelOrderTree(Node *root)
{
	int h = height(root);
	for (int i = 1; i <= h; i++)
	{
		printLevel(root,i);	
	}
}
/*
Time Complexity: O(n^2) in worst case. 
For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. 
So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2).
*/
int main(int argc, char const *argv[])
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	printLevelOrderTree(root);
	return 0;
}