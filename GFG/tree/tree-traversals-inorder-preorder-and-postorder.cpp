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
	temp->left = temp->right = NULL;
	return temp;
}

void printinorder(Node *root)
{	// L D R
	if (root == NULL)
	{
		return;
	}
	printinorder(root->left);
	cout << root->data;
	printinorder(root->right);
}

void printpreorder(Node *root)
{	// D L R
	if (root == NULL)
	{
		return;
	}
	cout << root->data;
	printpreorder(root->left);
	printpreorder(root->right);
}

void printpostorder(Node *root)
{	// L R D
	if (root == NULL)
	{
		return;
	}
	printpostorder(root->left);
	printpostorder(root->right);
	cout << root->data;
}
/********************************************************************
 Time Complexity: O(n)  all problem where tree traversal is involved 
Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(n).
*******************************************************************/

// POSTORDER is used to delete the tree since we have to del childs `st than parent
//Similarly, Preorder to copy tree
void deleteNodes(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	deleteNodes(root->left);
	deleteNodes(root->right);
	free(root);
}


void deleteTree(Node **ref)
{
	deleteNodes(*ref);
	*ref = NULL;
}

/******************************************************************************
Delete Tree : -
Time Complexity: O(n)
Space Complexity: If we don’t consider size of stack for function calls then O(1) otherwise O(n)
*********************************************************************************/

int main(int argc, char const *argv[])
{
	Node *tree = newNode(1);
	tree->left = newNode(2);
	tree->right = newNode(3);
	tree->left->left = newNode(4);
	tree->left->right =newNode(5);
	cout << "Inorder Traversal :- \n";
	printinorder(tree);
	cout << "\n";
	cout << "Preorder Traversals : -\n";
	printpreorder(tree);
	cout << "\n";
	cout << "PostOrder Traversals : -\n";
	printpostorder(tree);
	cout << "\n";
	deleteTree(&tree);
	return 0;
}