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
// We can use traversal to solve problem like below ones
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

int sizeoftree(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		return (sizeoftree(root->left) + 1 + sizeoftree(root->right));
	}
}

int max(Node *root)
{
	if (root == NULL)
	{
		return 0 ;
	}
	else
	{
		int res = root->data;
		int lres = max(root->left);
		int rres = max(root->right);
		if (lres > res)
		{
			res = lres;
		}
		if (rres > res)
		{
			res = rres;
		}
		return res;
	}
}

int min(Node *root)
{
	if (root == NULL)
	{
		return 0 ;
	}
	else
	{
		int res = root->data;
		int lres = max(root->left);
		int rres = max(root->right);
		if (lres < res)
		{
			res = lres;
		}
		if (rres < res)
		{
			res = rres;
		}
		return res;
	}
}

void printcurrentview(Node *root,int level,int& maxlevel)
{
	if (root == NULL)
	{
		return;
	}

	if (maxlevel < level)
	{
		cout << root->data << "\n";
		maxlevel = level;
	}
	printcurrentview(root->left,level+1,maxlevel);
	printcurrentview(root->right,level+1,maxlevel);
}

void printleftviewoftree(Node *root)
{
	int maxlevel = 0;
	printcurrentview(root,1,maxlevel);
}
/************************************************************************************
Asked in: Amazon, Flipkart, Knowlarity, OLA, Open Solutions, Samsung, Snapdeal, Twitter
*************************************************************************************/
void printrightcurrentview(Node *root,int level,int& maxlevel)
{
	if (root == NULL)
	{
		return;
	}

	if (maxlevel < level)
	{
		cout << root->data << "\n";
		maxlevel = level;
	}
	printrightcurrentview(root->right,level+1,maxlevel);
	printrightcurrentview(root->left,level+1,maxlevel);
}

void printrightviewoftree(Node *root)
{
	int maxlevel = 0;
	printrightcurrentview(root,1,maxlevel);
}

/******************************************************************************
Abive fns :-
Time Complexity & Space Complexity: Similar to Tree Traversals
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
	cout << "Size of tree : "<< sizeoftree(tree) <<"\n";
	cout << "Maximum elemt of tree : "<< max(tree) <<"\n";
	cout << "Minmum elemt of tree : "<< min(tree) <<"\n";
	cout << "Print left view of tree : \n";
	printleftviewoftree(tree);
	cout << "Print right view of tree : \n";
	printrightviewoftree(tree);
	deleteTree(&tree);
	return 0;
}